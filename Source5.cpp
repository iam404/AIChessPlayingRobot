#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui_c.h"
#include <stdlib.h>
#include <stdio.h>
#include "opencv2/core/core_c.h"
#include <opencv2/opencv.hpp>
#include "opencv/cv.h";

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	 int  corner_count = 160;
Size patternsize(9,9);
//vector<Point2f> corners;
CvPoint2D32f *corners;
corners = (CvPoint2D32f *) cvAlloc (corner_count * sizeof (CvPoint2D32f));
IplImage* grayimg = cvLoadImage ("D:/storeroom/unwantedPack/4.jpg", CV_LOAD_IMAGE_GRAYSCALE );
if (grayimg.data == NULL) {
    printf("Unable to read image");
	waitkey(100);
    return 0;
}
int patternfound =  cvFindChessboardCorners (grayimg, patternsize, corners,NULL,
        CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_FAST_CHECK);
printf("%d",&patternfound);
if (patternfound) {
    printf("Chessboard not found");
	waitkey(100);
	

}
getchar();
    return 0;
}