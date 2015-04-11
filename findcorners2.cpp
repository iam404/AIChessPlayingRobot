#include <stdio.h>
//#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(){
    Size patternsize(8,8); //number of centers
    Mat frame = imread("D:\\PX8P6.jpg"); //source image
    vector<Point2f> centers(4); //this will be filled by the detected centers

    bool patternfound = findChessboardCorners(frame,patternsize,centers, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);

  // cout<<patternfound<<endl;
	//cornerSubPix(frame, centers);
    drawChessboardCorners(frame, patternsize, Mat(centers), patternfound);

    cvNamedWindow("window");
    while(1){
        imshow("window",frame);
        cvWaitKey(33);
    }
}