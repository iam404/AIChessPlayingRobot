// space to exit and "s" to save


#include <iostream>

#include <opencv2/opencv.hpp>


void my_mouse_callback( int event, int x, int y, int flags, void* param );

void draw_box(IplImage* img, CvRect rect);



CvRect box;

bool mouse_down = false;


int main (int argc, const char * argv[])

{

    int saved = 1;

    IplImage* img = cvLoadImage("D:\\chess\\new.jpg");

    IplImage* imgDrawn = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);

    cvNamedWindow("window");
	 
    box = cvRect(-1,-1,0,0);

    cvSetMouseCallback("window", my_mouse_callback, img);

   while(1)

    {

        cvCopy(img,imgDrawn);

       draw_box(imgDrawn, box );

      cvShowImage("window", imgDrawn);

              

        //  "s"  - saved

        char s = cvWaitKey(10);

        if ( s == 115)

        {

            cvSetImageROI(img, box);
			          

            char *name = new char[100];

            sprintf(name, "D:\\chess\\crop\\%d.jpg", saved);

            cvSaveImage(name, img);

            cvResetImageROI(img);

            saved += 1;

            printf("saved");

        }

       

        if (s == 32){

            cvReleaseImage(&img);

            cvReleaseImage(&imgDrawn);

            cvDestroyWindow("window");

            return 0;

        }

        

    }

}

void my_mouse_callback( int event, int x, int y, int flags, void* param ){

  

    switch( event ){

        case CV_EVENT_MOUSEMOVE: 

            if( mouse_down ){

                box.width = x-box.x;

                box.height = y-box.y;

            }

            break;
			
            

        case CV_EVENT_LBUTTONDOWN:

            mouse_down = true;

            box = cvRect( x, y, 0, 0 );

            break;

            

        case CV_EVENT_LBUTTONUP:

            mouse_down = false;

            if( box.width < 0 ){

                box.x += box.width;

                box.width *= -1;

            }

            if( box.height < 0 ){

                box.y += box.height;

                box.height *= -1;

            }            

            break;

    }

}



void draw_box( IplImage* img, CvRect rect ){

    cvRectangle( img, cvPoint(box.x, box.y), cvPoint(box.x+box.width,box.y+box.height),

                cvScalar(0xff,0x00,0x00) );
	printf("cordinate: %d / %d / %d %d ",box.x,box.y,box.width,box.height);
	cvWaitKey(150);

}