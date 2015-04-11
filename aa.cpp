//#include "stdafx.h"
#include "BlobResult.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

const std::string filepath = "D:\\chess\\croppedimg1.jpg";

void difference()
{
	IplImage *first = cvLoadImage("D:\\chess\\new.jpg");
 IplImage *second = cvLoadImage("D:\\chess\\new1.jpg");
 
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
 sprintf(name, "D:\\chess\\croppedimg1.jpg");

 cvSaveImage(name,subImage );
 
//cvWaitKey(0);
 //cvDestroyWindow("Original:");
 //cvReleaseImage(&first);
 //cvDestroyWindow("Modified:");
 //cvReleaseImage(&second);
 //cvDestroyWindow("Diff:");
 //cvReleaseImage(&subImage);
 //return 0;
}

int main()
{ 
	difference();
   CBlobResult blobs;
   CBlob *currentBlob;

   // Load grayscale version of coloured input image
   IplImage* original = cvLoadImage( filepath.c_str(),
                                     CV_LOAD_IMAGE_GRAYSCALE );

   // Make sure image file is available
   assert ( original );

   // Obtain binary (black and white) version of input image
   IplImage* img_bwt = cvCreateImage( cvGetSize( original ),
                                     IPL_DEPTH_8U,
                                     1 );
   
   // Threshold to convert image into binary (B&W)
   cvThreshold( original,     // source image
                img_bwt,       // destination image img_bw
                50,          // threhold val.
                100,          // max. val
                CV_THRESH_BINARY ); // binary type ); 

   IplImage* img_bwe = cvCreateImage( cvGetSize( original ),
                                     IPL_DEPTH_8U,
                                     1 );
   IplImage* img_bw = cvCreateImage( cvGetSize( original ),
                                     IPL_DEPTH_8U,
                                     1 );
   cvErode(img_bwt, img_bwe, 0, 1);
 
cvNamedWindow( "erode", 1 );
 
cvShowImage( "erode", img_bwe );
 
cvDilate(img_bwe, img_bw, 0, 2);
 
cvNamedWindow( "dilate", 1 );
 
cvShowImage( "dilate", img_bw );
 


   // Find the white blobs in the B&W image
   blobs = CBlobResult( img_bw, NULL, 0 );

   // Exclude all white blobs smaller than the given value (80)
   // The bigger the last parameter, the bigger the blobs need
   // to be for inclusion
   blobs.Filter( blobs,
                 B_EXCLUDE,
                 CBlobGetArea(),
                 B_LESS,
                 80 );

   // Get the number of blobs discovered
   int num_blobs = blobs.GetNumBlobs(); 
   printf("%d",num_blobs);

   // Display the filtered blobs
   IplImage* filtered = cvCreateImage( cvGetSize( img_bw ),
                                       IPL_DEPTH_8U,
                                       3 ); 

   cvMerge( img_bw, img_bw, img_bw, NULL, filtered );

   for ( int i = 0; i < num_blobs; i++ )
   {
      currentBlob = blobs.GetBlob( i );
      currentBlob->FillBlob( filtered, CV_RGB(255,0,0));
   }

   // Display the input / output windows and images
   cvNamedWindow( "input" );
   cvNamedWindow( "output" );
   cvShowImage("input", img_bw );
   cvShowImage("output", filtered);

   // Wait for user key press and then tidy up
   cvWaitKey(0);

   cvReleaseImage( &original );
   cvReleaseImage( &filtered );

   cvDestroyWindow( "input" );
   cvDestroyWindow( "output" );    

   return 0;
}