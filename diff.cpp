//#include "stdafx.h"
 #include<opencv\cv.h>
 #include<opencv\cxcore.h>
 #include<opencv\highgui.h>
 
int main(int argc, char* argv[])
 {
 
IplImage *first = cvLoadImage("D:\\chess\\photoaf.jpg");
 IplImage *second = cvLoadImage("D:\\chess\\photoaf1.jpg");
 
IplImage *subImage;
 subImage = cvCloneImage(first);
 
cvAbsDiff(first,second,subImage);
 cvNamedWindow("Original:");
 cvShowImage("Original:", first);
 
cvNamedWindow("Modified:");
 cvShowImage("Modified:", second);
 
cvNamedWindow("Diff:");
 cvShowImage("Diff:", subImage);
char *name = new char[100];
 sprintf(name, "D:\\chess\\croppedimg.jpg");

 cvSaveImage(name,subImage );
 
cvWaitKey(0);
 cvDestroyWindow("Original:");
 cvReleaseImage(&first);
 cvDestroyWindow("Modified:");
 cvReleaseImage(&second);
 cvDestroyWindow("Diff:");
 cvReleaseImage(&subImage);
 return 0;
 
}