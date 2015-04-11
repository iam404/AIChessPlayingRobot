#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"
//#define FALSE 0;

IplImage* frame, * img1;
CvPoint point;
int drag = 0;
int key = 0 ;
bool  pause = FALSE;

void mouseHandler(int event, int x, int y, int flags, void* param)
{
    /* user press left button */
    if (event == CV_EVENT_LBUTTONDOWN && !drag)
    {
        point = cvPoint(x, y);
        drag = 1;
    }

    /* user drag the mouse */
    if (event == CV_EVENT_MOUSEMOVE && drag)
    {
        cvDestroyWindow("result");
        img1 = cvCloneImage(frame);
        cvRectangle(img1,point,cvPoint(x, y),CV_RGB(255, 0, 0),1, 8, 0);
        cvCopy(img1,frame, NULL);
        cvShowImage("origin", img1);
        pause = TRUE;
    }

    /* user move the mouse */
    if (event == CV_EVENT_MOUSEMOVE && !drag)
    {
        point = cvPoint(x, y);
        printf("x = %d y = %d \n",point.x,point.y);
    }

    /* user release left button */
    int a,b;
    if (event == CV_EVENT_LBUTTONUP && drag)
    {
        img1 = cvCloneImage(frame);
        if ((x == point.x) || (y == point.y)) goto jmp;
        if ((point.x > x) && (point.y < y)) goto jmp;
        if ((point.x < x) && (point.y > y)) goto jmp;
        if ((point.x > x) && (point.y > y)) {
			a = point.x;
            b = point.y;
            point.x = x;
            point.y = y;
            x = a;
            y = b;
        }
        cvSetImageROI(img1,cvRect(point.x,point.y,x - point.x,y - point.y));
        cvNot(img1, img1); // or do whatever with the ROI
        cvShowImage("result", img1);
        cvResetImageROI(img1);
        //cvCopy(img1,frame, NULL); //other tricks
        //cvShowImage("result1", img1);
        jmp:
        drag = 0;
        pause = FALSE;
    }

    /* user click right button: reset all */
    if (event == CV_EVENT_RBUTTONUP)
    {
        cvShowImage("result", frame);
        drag = 0;
    }
}

int main(int argc, char *argv[])
{
    /* create a window for the video */
    cvNamedWindow( "origin", CV_WINDOW_AUTOSIZE );
    cvSetMouseCallback("origin", mouseHandler, NULL);

    while( key != 'q' )
    {
    frame = cvLoadImage("D:\\storeroom\\unwantedPack\\4.jpg",1);
    if (!pause) cvShowImage("origin", frame);
    key = cvWaitKey( 30 );
    }

    cvDestroyWindow("origin");
    cvReleaseImage(&frame);
    cvReleaseImage(&img1);
    return 0;
}