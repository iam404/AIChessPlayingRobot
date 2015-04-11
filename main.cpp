#include "BlobResult.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <iostream>
#include<string>

#include <fstream>
#include <iostream>

#include <opencv2/opencv.hpp>

CvRect box;

int blob(const char *filepath);
void difference();
void segmentation();
void stat(int );
using namespace std;

void difference()
{
	IplImage *first = cvLoadImage("D:\\chess\\new.jpg");
 IplImage *second = cvLoadImage("D:\\chess\\new1.jpg");
 
IplImage *subImage;
 subImage = cvCloneImage(first);
 
cvAbsDiff(first,second,subImage);
char *name = new char[100];
 sprintf(name, "D:\\chess\\croppedimg1.jpg");

 cvSaveImage(name,subImage );
 

}


int blob(const char *filepath){
	 CBlobResult blobs;
   CBlob *currentBlob;

   // Load grayscale version of coloured input image
   IplImage* original = cvLoadImage( filepath,
                                     CV_LOAD_IMAGE_GRAYSCALE );

   // Make sure image file is available
   assert ( original );

   // Obtain binary (black and white) version of input image
   IplImage* img_bwt = cvCreateImage( cvGetSize( original ),
                                     IPL_DEPTH_8U,
                                     1 );
   
   // Threshold to convert image into binary (B&W)
   cvThreshold( original,     // source image
                img_bwt,       // destination image img_bw
                50,          // threhold val.
                100,          // max. val
                CV_THRESH_BINARY ); // binary type ); 

   IplImage* img_bwe = cvCreateImage( cvGetSize( original ),
                                     IPL_DEPTH_8U,
                                     1 );
   IplImage* img_bw = cvCreateImage( cvGetSize( original ),
                                     IPL_DEPTH_8U,
                                     1 );
   cvErode(img_bwt, img_bwe, 0, 1);
 
//cvNamedWindow( "erode", 1 );
 
//cvShowImage( "erode", img_bwe );
 
cvDilate(img_bwe, img_bw, 0, 2);
 
//cvNamedWindow( "dilate", 1 );
 
//cvShowImage( "dilate", img_bw );
 


   // Find the white blobs in the B&W image
   blobs = CBlobResult( img_bw, NULL, 0 );

   // Exclude all white blobs smaller than the given value (80)
   // The bigger the last parameter, the bigger the blobs need
   // to be for inclusion
   blobs.Filter( blobs,
                 B_EXCLUDE,
                 CBlobGetArea(),
                 B_LESS,
                 80 );

   // Get the number of blobs discovered
   int num_blobs = blobs.GetNumBlobs(); 
   printf("%d",num_blobs);

   
   cvWaitKey(0);

   //cvReleaseImage( &original );
   

   if ((num_blobs)==1)
   {
	   return 1;
   } else return 0;


   return 0;
}


int main()
{
	int state[64]={1,1,1,1,1,1,1,1,
				   1,1,1,1,1,1,1,1,
				   0,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,
				   1,1,1,1,1,1,1,1,
				   1,1,1,1,1,1,1,1,};


	int saved=64,a,b,value;
	
	difference();

	segmentation();

for( int i=1; i<=saved; i++ )
{
    

	char *name = new char[100];
	 
	// IplImage* img= cvLoadImage("D:\\chess\\New\\3.jpg");
	 //cvShowImage("bbbb",img);
	// cvWaitKey(1000);

  //  IplImage* imgD ;

	sprintf(name, "D:\\chess\\crop123\\%d.jpg", i);

			//imgD = cvLoadImage(name);
			//cvShowImage("bbbbbb",imgD);
		value=blob(name);
			if (value==1) {

				if (state[i]==0){ a=i;}
				else b=i;

			}
			//cvWaitKey(1000);
			//cvReleaseImage(&img);
//			cvReleaseImage(&imgD);

}

//const char* ll= itoa(stat(b));
//const char* bb= stat(a);
//cout<<"ggg"<<stat(b)<<endl
printf("movement from ");
stat(b);
stat(a);
stat(0);

cvWaitKey(0);

return 0;
}


void stat(int pos){
	ofstream outfile("E:\out.txt",ios::app);

	switch (pos){
	case 1: outfile<< "a1";break;
	case 2:outfile<<"b1" ;break;
	case 3:outfile<< "c1" ;break;
	case 4:outfile<< "d1" ;break;
	case 5:outfile<< "e1" ;break;
	case 6:outfile<< "f1" ;break;
	case 7:outfile<< "g1" ;break;
	case 8:outfile<< "h1" ;break;
	case 9: outfile<< "a2" ;break;
	case 10:outfile<< "b2" ;break;
	case 11:outfile<< "c2" ;break;
	case 12:outfile<< "d2" ;break;
	case 13:outfile<< "e2" ;break;
	case 14:outfile<< "f2" ;break;
	case 15:outfile<<"g2" ;break;
	case 16:outfile<< "h2" ;break;
	case 17: outfile<< "a3" ;break;
	case 18:outfile<< "b3" ;break;
	case 19:outfile<<"c3" ;break;
	case 20:outfile<< "d3" ;break;
	case 21:outfile<< "e3" ;break;
	case 22:outfile<<"f3" ;break;
	case 23:outfile<< "g3" ;break;
	case 24:outfile<< "h3" ;break;
	case 25: outfile<<"a4" ;break;
	case 26:outfile<<"b4" ;break;
	case 27:outfile<<"c4" ;break;
	case 28:outfile<<"d4" ;break;
	case 29:outfile<< "e4" ;break;
	case 30:outfile<<"f4" ;break;
	case 31:outfile<<"g4" ;break;
	case 32:outfile<<"h4" ;break;
	case 33: outfile<< "a5" ;break;
	case 34:outfile<<"b5" ;break;
	case 35:outfile<< "c5" ;break;
	case 36:outfile<<"d5" ;break;
	case 37:outfile<<"e5" ;break;
	case 38:outfile<< "f5" ;break;
	case 39:outfile<< "g5" ;break;
	case 40:outfile<<"h5" ;break;
case 41: outfile<< "a6" ;break;
case 42: outfile<<"b6";break ;
	case 43:outfile<<"c6" ;break;
	case 44:outfile<<"d6" ;break;
	case 45:outfile<< "e6" ;break;
	case 46:outfile<<"f6" ;break;
	case 47:outfile<< "g6" ;break;
	case 48:outfile<<"h6" ;break;
case 49: outfile<<"a7" ;break;
	case 50:outfile<<"b7" ;break;
	case 51: outfile<<"c7";break;
	case 52:outfile<< "d7" ;break;
	case 53:outfile<<"e7" ;break;
	case 54:outfile<< "f7" ;break;
	case 55:outfile<<"g7" ;break;
	case 56:outfile<<"h7" ;break;
	case 57:outfile<<"a8" ;break;
	case 58:outfile<<"b8" ;break;
	case 59:outfile<<"c8" ;break;
	case 60:outfile<<"d8" ;break;
	case 61:outfile<<"e8" ;break;
	case 62:outfile<<"f8" ;break;
	case 63:outfile<<"g8" ;break;
	case 64:outfile<<"h8" ;break;
	default:
		break;



	}



	if(pos==0) outfile<<endl;
	
}

void segmentation()
{
	int saved = 1;
	char *name = new char[100];
	IplImage* img = cvLoadImage("D:\\chess\\croppedimg1.jpg");
	  //1
	
			box = cvRect(71,1,52,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");

			//2
			box = cvRect(67,59,53,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//3
			box = cvRect(68,110,52,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//4
			box = cvRect(67,165,57,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//5
			box = cvRect(67,219,52,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//6
			box = cvRect(67,273,50,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//7
			box = cvRect(66,327,54,50);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//8
			box = cvRect(67,379,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//9
			box = cvRect(122,5,51,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//10
			box = cvRect(123,57,50,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//11
			box = cvRect(122,111,53,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//12
			box = cvRect(120,165,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//13
			box = cvRect(119,217,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//14
			box = cvRect(120,272,51,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//15
			box = cvRect(120,326,50,50);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//16
			box = cvRect(121,380,51,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//17
			box = cvRect(178,3,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//18
			box = cvRect(179,57,52,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//19
			box = cvRect(175,112,50,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//20
			box = cvRect(175,167,51,49);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//21
			box = cvRect(173,219,52,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//22
			box = cvRect(173,274,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//23
			box = cvRect(174,328,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//24
			box = cvRect(178,380,53,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//25
			box = cvRect(232,3,50,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//26
			box = cvRect(230,57,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");

			//27
			box = cvRect(230,111,51,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//28
			box = cvRect(229,164,52,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//29
			box = cvRect(227,221,54,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//30
			box = cvRect(226,273,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//31
			box = cvRect(228,327,47,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//32
			box = cvRect(224,382,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//33
			box = cvRect(285,4,53,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//34
			box = cvRect(284,58,54,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//35
			box = cvRect(283,110,55,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//36
			box = cvRect(282,166,52,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//37
			box = cvRect(282,220,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//38
			box = cvRect(280,273,52,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//39
			box = cvRect(280,330,55,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//40
			box = cvRect(279,382,52,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//41
			box = cvRect(339,4,53,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//42
			box = cvRect(338,56,55,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//43
			box = cvRect(337,112,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//44
			box = cvRect(337,166,52,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//45
			box = cvRect(337,222,52,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//46
			box = cvRect(336,277,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//47
			box = cvRect(336,330,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//48
			box = cvRect(335,384,55,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//49
			box = cvRect(393,4,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//50
			box = cvRect(395,60,51,49);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//51
			box = cvRect(393,112,50,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//52
			box = cvRect(392,166,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//53
			box = cvRect(391,220,53,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//54
			box = cvRect(390,276,50,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//55
			box = cvRect(391,331,54,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//56
			box = cvRect(390,385,51,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//57
			box = cvRect(446,3,53,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//58
			box = cvRect(446,60,55,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            
			//59
			box = cvRect(446,112,55,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            
			//60
			box = cvRect(446,116,55,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            
			//61
			box = cvRect(446,220,55,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            
			//62
			box = cvRect(446,276,54,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            
			//63
			box = cvRect(446,330,54,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
         
			//64
			box = cvRect(444,385,54,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            
			
			

	}