#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace cv;
using namespace std;
//using namespace ocl;
//Mat region[64];

int main(int argc, char** argv)
{

	Mat image = imread("D:\\chess\\1.jpg",0);
	
	///for(int i=0;i<800;i=i+118){
	//Mat region =image.rowRange(i,i+118).colRange(0,118);
	//Mat region =image.rowRange(118,236).colRange(0,118);

	
    imshow("source", image);
   // imshow("detected lines", region);
	// imshow("detected lines", region[2]);

	    waitKey(50);
	//}
    return 0;
}

