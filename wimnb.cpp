

#include <iostream>

#include <windows.h> // for sleep

#include <string>

#include <fstream>

#include <istream>

using namespace std;

 

int main()

{

    string::size_type loc; // to hold location in string

    string::size_type loc2; 

    string::size_type loc3; 

    string xtoe; // Used to store messages from winboard to engine(me)

    string mtoe; // Used to store messages sent from matlab(textfile) to engine(me)

    int run=1;   //  flag

 

    ofstream outfile("E:\in.txt",ios::app);    //The file where we write (selected) messages sent to us my winboard. . Since we can't directly send message to matlab, this file is used as medium.

    ofstream dumpfile("E:\dump.txt",ios::app); // We will dump everything we have been sent by winboard to this file. will be usefull for debugging purpose, and just for knowledge of what is being sent to us

    ifstream infile("E:\out.txt",ios::in);     //We will read what is being sent to us by matlab through this file. since we don't directly know how to send datas from matlab to winboard, we will use this as medium

 



 

    while (run) // the (almost) infinite program loop

    {

 

        Sleep(10);  
 

        

        getline(cin,xtoe); //recieve a message from winboard and store in xtoe string

        dumpfile << xtoe.data() << endl; //immidiately dumpt that message to the file

        loc = xtoe.find( "quit", 0 );    //get the location of occurence of word 'quit' in the message

        if (loc != string::npos)         //loc != string::npos means, the location is not npos(no position). Which means the message contains 'quit'

        {

            return 0; // quit the game     // so, what to wait for, just quit! :)

        }

        loc = xtoe.find( "exit", 0 );

        if (loc != string::npos)         // see if it contains the 'exit' keyword and act accordingly

        {

            return 0; // quit the game

        }

        loc = xtoe.find( "xboard", 0 );

        if (loc != string::npos)

        {

            // nothing to do, just be ready :)

        }

        loc = xtoe.find( "protover", 0 );

        if (loc != string::npos)

        {

            cout << "feature usermove=1 done=1"<<endl; // send back features command. After sending "protover" command the winboard expects us to send back feature command followed by a set of feature we desire. We end this by sending done=1. Here we have requested for usermove feature. which means, every move made by the other (genuine) engine will be sent to us prececeding with 'usermove' keyword. This makes us easier to know when a move is sent to us and act accordingly. the winboard will reply with "accepted usermove" and "accepted done"

        }

        loc = xtoe.find( "time", 0 ); // detect if time is sent. we don't do anything for now but you could add something

        if (loc != string::npos)

        {

            // not care time for now

            // outfile << xtoe.data() << endl << flush;

        }

        loc = xtoe.find( "otim", 0 );  // we just ignore this message

        if (loc != string::npos)

        {

            // not care time for now

            // outfile << xtoe.data() << endl << flush;

 

        }

 

 

      
 

        loc = xtoe.find( "usermove", 0 );

        loc2 = xtoe.find("accepted", 0);

        loc3 = xtoe.find("rejected", 0);

 

        if (loc != string::npos && loc2 == string::npos && loc3 == string::npos)

        {

            //so a valid move is sent.

            outfile << xtoe.data() << endl << flush; //save this message into outfile

 

            //now we need to send back our move back to winboard, in the form like "move g7g5". Since we aren't a genuine engine, we will just wait for some external medium (like matlab, or human) to provide us the move, we will poll the infile for new moves

            int endfile = 1; // a flag to indicate when to stop polling for our reply move

            while (endfile) // repeat till we get the move

            {

                Sleep(10); //make the polling less intensive to the cpu by including sleep

                infile.clear(); // see the comment on the line just below this

                getline(infile,mtoe); //if the infile don't contains any new line (which occurs everytime our engine runs out of new moves),then the infile's some error flag bits will be set, and it will prevent reading anymore lines, so we need to clear these flags repetedly. Hence the line above.

                if (strcmp(mtoe.data(),"")!=0) endfile=0; //if we got any new data, just end the poll. (we should get data like "g7g5")

            }

            cout << "move "<< mtoe.data() << endl; // send the move to the winboard by preceding with "move".

        }

 

        mtoe = "";

 

    } //loop. start listening to winboard again.

    return 0;

}
