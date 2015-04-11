// Program illustrate single camera calibration
// Author: Samarth Manoj Brahmbhatt, University of Pennsylvania
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>

using namespace cv;
using namespace std;

int main() {


	if(findChessboardCorners(img,boardSize,imageCorners))
	{
		drawChessboardCorners(img,boardSize,imageCorners,true);
		Rect myroi(imageCorners(0),imageCorners((height*width) -1);

}