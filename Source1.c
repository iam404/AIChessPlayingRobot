#include "opencv2/highgui/highgui_c.h"
#include "opencv2/core/core_c.h"
#include "opencv/cv.h"
#include <stdlib.h>

#include <stdio.h>
//#include "opencv2/opencv.hpp"

int n_boards = 0;
const int board_dt = 20;
int board_w;
int board_h;

int main(int argc, char** argv)
{
	board_w = 5; // Board width in squares
	board_h = 8; // Board height 
	n_boards = 8; // Number of boards
	int board_n = board_w * board_h;

	CvSize board_sz = cvSize( board_w, board_h );
	CvCapture* capture = cvCreateCameraCapture( 0 );
	assert( capture );

	cvNamedWindow( "Calibration" );
	// Allocate Sotrage
	CvMat* image_points		= cvCreateMat( n_boards * board_n, 2, CV_32FC1 );
	CvMat* object_points		= cvCreateMat( n_boards*board_n, 3, CV_32FC1 );
	CvMat* point_counts			= cvCreateMat( n_boards, 1, CV_32SC1 );
	CvMat* intrinsic_matrix		= cvCreateMat( 3, 3, CV_32FC1 );
	CvMat* distortion_coeffs	= cvCreateMat( 5, 1, CV_32FC1 );

	CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
	int corner_count;
	int successes = 0;
	int step, frame = 0;

	IplImage *image = cvQueryFrame( capture );
	IplImage *gray_image = cvCreateImage( cvGetSize( image ), 8, 1 );

	// Capture Corner views loop until we've got n_boards
	// succesful captures (all corners on the board are found)

	while( successes < n_boards ){
		// Skp every board_dt frames to allow user to move chessboard
		if( frame++ % board_dt == 0 ){
			// Find chessboard corners:
			int found = cvFindChessboardCorners( image, board_sz, corners,
				&corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );

			// Get subpixel accuracy on those corners
			cvCvtColor( image, gray_image, CV_BGR2GRAY );
			cvFindCornerSubPix( gray_image, corners, corner_count, cvSize( 11, 11 ), 
				cvSize( -1, -1 ), cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

			// Draw it
			cvDrawChessboardCorners( image, board_sz, corners, corner_count, found );
			cvShowImage( "Calibration", image );

			// If we got a good board, add it to our data
			if( corner_count == board_n ){
				step = successes*board_n;
				for ( int i=step, j=0; j < board_n; ++i, ++j )
				{
					CV_MAT_ELEM( *image_points, float, i, 0 ) = corners[j].x;
					CV_MAT_ELEM( *image_points, float, i, 1 ) = corners[j].y;
					CV_MAT_ELEM( *object_points, float, i, 0 ) = (float)j/board_w;
					CV_MAT_ELEM( *object_points, float, i, 1 ) = (float)(j%board_w);
					CV_MAT_ELEM( *object_points, float, i, 2 ) = 0.0f;
				}
				CV_MAT_ELEM( *point_counts, int, successes, 0 ) = board_n;
				successes++;
			}
		} 

		// Handle pause/unpause and ESC
		int c = cvWaitKey( 15 );
		if( c == 'p' ){
			c = 0;
			while( c != 'p' && c != 27 ){
				c = cvWaitKey( 250 );
			}
		}
		if( c == 27 )
			return 0;
		image = cvQueryFrame( capture ); // Get next image
	} // End collection while loop

	// Allocate matrices according to how many chessboards found
	CvMat* object_points2 = cvCreateMat( successes*board_n, 3, CV_32FC1 );
	CvMat* image_points2 = cvCreateMat( successes*board_n, 2, CV_32FC1 );
	CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );
	
	// Transfer the points into the correct size matrices
	for( int i = 0; i < successes*board_n; ++i ){
		CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0 );
		CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1 );
		CV_MAT_ELEM( *object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0 );
		CV_MAT_ELEM( *object_points2, float, i, 1) = CV_MAT_ELEM( *object_points, float, i, 1 );
		CV_MAT_ELEM( *object_points2, float, i, 2) = CV_MAT_ELEM( *object_points, float, i, 2 );
	}

	for( int i=0; i < successes; ++i ){
		CV_MAT_ELEM( *point_counts2, int, i, 0 ) = CV_MAT_ELEM( *point_counts, int, i, 0 );
	}
	cvReleaseMat( &object_points );
	cvReleaseMat( &image_points );
	cvReleaseMat( &point_counts );

	// At this point we have all the chessboard corners we need
	// Initiliazie the intrinsic matrix such that the two focal lengths
	// have a ratio of 1.0

	CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0;
	CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0;

	// Calibrate the camera
	cvCalibrateCamera2( object_points2, image_points2, point_counts2, cvGetSize( image ), 
		intrinsic_matrix, distortion_coeffs, NULL, NULL, CV_CALIB_FIX_ASPECT_RATIO ); 

	// Save the intrinsics and distortions
	cvSave( "Intrinsics.xml", intrinsic_matrix );
	cvSave( "Distortion.xml", distortion_coeffs );

	// Example of loading these matrices back in
	CvMat *intrinsic = (CvMat*)cvLoad( "Intrinsics.xml" );
	CvMat *distortion = (CvMat*)cvLoad( "Distortion.xml" );

	// Build the undistort map that we will use for all subsequent frames
	IplImage* mapx = cvCreateImage( cvGetSize( image ), IPL_DEPTH_32F, 1 );
	IplImage* mapy = cvCreateImage( cvGetSize( image ), IPL_DEPTH_32F, 1 );
	cvInitUndistortMap( intrinsic, distortion, mapx, mapy );

	// Run the camera to the screen, now showing the raw and undistorted image
	cvNamedWindow( "Undistort" );

	while( image ){
		IplImage *t = cvCloneImage( image );
		cvShowImage( "Calibration", image ); // Show raw image
		cvRemap( t, image, mapx, mapy ); // undistort image
		cvReleaseImage( &t );
		cvShowImage( "Undistort", image ); // Show corrected image

		// Handle pause/unpause and esc
		int c = cvWaitKey( 15 );
		if( c == 'p' ){
			c = 0;
			while( c != 'p' && c != 27 ){
				c = cvWaitKey( 250 );
			}
		}
		if( c == 27 )
			break;
		image = cvQueryFrame( capture );
	}

	return 0;
}

*/


/*
void main( int argc, char** argv ) {
	/* int KEY ;
	
	CvCapture *capture = 0; //The camera
IplImage* frame = 0; //The images you bring out of the camera
capture = cvCaptureFromCAM( 0 ); //Open the camera
if (!capture ){
printf("Could not connect to camera\n" ); return 1;
}
//int key;
cvNamedWindow( "demowin1", CV_WINDOW_AUTOSIZE ); //Create output window
// while(1 /*escape key to quit*///)
/*{
//Query for the next frame
//frame = cvQueryFrame( capture );
//if( !frame ) break;
//show the raw image in the first window
cvShowImage( "demowin1", frame );
//cvReleaseImage( frame );
//Get the last key that's been pressed for input
//KEY = 1;
//}
//Shutdown
cvWaitKey(0);
cvReleaseCapture( &capture ); // WARNING: DO NOT release the "frame" variable
cvDestroyWindow( "demowin1" );
return 0;

*/

	/* CvCapture* cvCaptureFromCAM(int device);

 int cvGrabFrame( CvCapture* capture );
	//cvShowImage( "Example1" , capture );
IplImage* cvRetrieveFrame( CvCapture* capture );
IplImage* cvQueryFrame( CvCapture* capture );*/

/*
 IplImage* img = cvLoadImage( "D:/storeroom/unwantedPack/4.png",1 );
 IplImage* img2 = cvCreateImage(cvSize(150,250),img->depth,img->nChannels);

//cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );
//cvShowImage( "Example1" , img );
//IplImage* cropped = crop(source,cvRect(0,0,1280,500));
//cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE );
//cvShowImage( "Example2" , cropped );

 
			cvSetImageROI(img,cvRect(150,200,150,250));
			
		cvCopy(img, img2 ,NULL);
		cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );
 cvShowImage( "Example1" , img2 );
		
cvWaitKey(0);
cvResetImageROI(img);
cvReleaseImage( &img );
cvDestroyWindow( "Example1");
//cvReleaseImage( &cropped );
//cvDestroyWindow( "Example2");
}
/*
IplImage* crop( IplImage * src , CvRect roi)
	{
		IplImage* cropped =cvCreateImage(cvSize(roi.width,roi.height),src->depth,src->nChannels);
			cvSetImageROI(src,roi);
		cvCopy(src,cropped,NULL);
		cvResetImageROI(src);
		return cropped;

	}
	*/
