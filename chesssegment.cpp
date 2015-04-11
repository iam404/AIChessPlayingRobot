#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <opencv2/opencv.hpp>*/
#include <stdio.h>
#include <time.h>

using namespace cv;
using namespace std;
//using namespace ocl;


int main(int argc, char** argv)
{
	
			
			Mat region;
		Mat image1;

			

			


	image1 =  imread("C:/croppedimg0.jpg",1);
	if(image1.empty())
	{
		cerr<<"empty"<<endl;
		getchar();
	}
	
	for(int i=0;i<800;i=i+118){
		region =image1.rowRange(i,i+118).colRange(0,118);
	//region =image1.colRange(0,100).rowRange(1,118);

	
  // imshow("source", region);

		imshow("detected",region);
	}
	//imshow("detected lines", region[2]);

	   // waitKey(50);
	}
	


