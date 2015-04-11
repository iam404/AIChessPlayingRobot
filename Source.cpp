#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;
Mat image, image_gray;
int max_corners = 23;

void on_slider(int, void *) {
if(image_gray.empty()) return;
max_corners = max(1, max_corners);
setTrackbarPos("Max no. of corners", "Corners", max_corners);
float quality = 0.01;
int min_distance = 10;
vector<Point2f> corners;
int blocksize = 3;

goodFeaturesToTrack(image_gray, corners, max_corners, quality, min_distance,cv::Mat(),blocksize,true);

// Draw the corners as little circles
Mat image_corners = image.clone();
for(int i = 0; i < corners.size(); i++) {
circle(image_corners, corners[i], 4, CV_RGB(255, 0, 0), -1);
cout<<"corner:"<<corners[i]<<"/n";
//waitKey();
}
imshow("Corners", image_corners);

waitKey();
}

int main() {
image = imread("D:/storeroom/unwantedPack/5.jpg",1);
cvtColor(image, image_gray, CV_RGB2GRAY);
namedWindow("Corners");
on_slider(0, 0);
createTrackbar("Max. no. of corners", "Corners", &max_corners, 250, on_slider);
while(char(waitKey(1)) != 'q') {}
return 0;
}