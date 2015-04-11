
#include <iostream>

#include <opencv2/opencv.hpp>

CvRect box;


int main (int argc, const char * argv[])

{

    int saved = 0;

    IplImage* img = cvLoadImage("croppedimg0.jpg");

	
    box = cvRect(44,118,256,343);  //x,y,width,height

            cvSetImageROI(img, box);

            char *name = new char[100];

            sprintf(name, "D:\\chess\\croppedimg%d.jpg", saved);

            cvSaveImage(name, img);

            cvResetImageROI(img);

           printf("saved");

          cvReleaseImage(&img);

           return 0;

      

        

    }



