/*#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int main() {
VideoCapture capr(1), capl(2);
//reduce frame size
capl.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
capl.set(CV_CAP_PROP_FRAME_WIDTH, 320);
capr.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
capr.set(CV_CAP_PROP_FRAME_WIDTH, 320);
namedWindow("Left");
namedWindow("Right");
while(char(waitKey(1)) != 'q') {
//grab raw frames first
capl.grab();
capr.grab();
//decode later so the grabbed frames are less apart in time
Mat framel, framer;
capl.retrieve(framel);
capr.retrieve(framer);
if(framel.empty() || framer.empty()) break;
imshow("Left", framel);
imshow("Right", framer);
}
capl.release();
capr.release();
return 0;
}

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int main()
{
// 0 is the ID of the built-in laptop camera, change if you want to use other camera
	VideoCapture cap = VideoCapture(0);
//cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
//cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
//check if the file was opened properly
if(!cap.isOpened())
{
cout << "Capture could not be opened successfully" << endl;
waitKey(100);

}
namedWindow("Video");
// Play the video in a loop till it ends
while(char(waitKey(1)) != 'q' //&& cap.isOpened()
	  )
{
Mat frame;
cap >> frame;
waitkey(20);
// Check if the video is over
if(frame.empty())
{
cout << "Video over" << endl;
break;
}
imshow("Video", frame);
}
return 0;
}*/

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int main() {
VideoCapture cap(0); // open the default camera
if(!cap.isOpened()) {
	waitKey(100);// check if we succeeded
	return -1;}
waitKey(100);
Mat edges;
namedWindow("edges",1);
for(;;)
{
    Mat frame;
    cap >> frame; // get a new frame from camera
    cvtColor(frame, edges, CV_BGR2GRAY);
    //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
    //Canny(edges, edges, 0, 30, 3);
    imshow("edges", edges);
	waitKey(20);
   if(waitKey(30) >= 0) break;
}
// the camera will be deinitialized automatically in VideoCapture destructor
return 0;
}