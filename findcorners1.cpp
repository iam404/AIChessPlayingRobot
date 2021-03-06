#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
 
#include <iostream>
#include <string>
 
std::vector<cv::Point3f> Create3DChessboardCorners(cv::Size boardSize, float squareSize);
 
int main( int argc, char* argv[])
{
  // Specify the number of squares along each dimension of the board.
  // This is actually the number of "inside corners" (where a black square meets a white square).
  // That is, if the board is composed of n x m squares, you would use (n-1, m-1) as the arguments.
  // For example, for a standard checkerboard (8x8 squares), you would use:
  cv::Size boardSize(8,8);
 
  float squareSize = 1.0f; // This is "1 arbitrary unit"
 
 // std::string imageFileName = argv[1];
 // std::cout << "Reading " << imageFileName << std::endl;
 
  cv::Mat image = cv::imread("D:\\PX8P6.jpg");
  if(image.empty())
    {
    std::cerr << "Image not read correctly!" << std::endl;
	cv::waitKey(0);
	    exit(-1);
    }
 
  cv::namedWindow( "Image View", 1 );
 
  cv::Size imageSize = image.size();
 
  // Find the chessboard corners
  std::vector<std::vector<cv::Point2f> > imagePoints(1);
  bool found = findChessboardCorners(image, boardSize, imagePoints[0],CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);
  if(!found)
    {
    std::cerr << "Could not find chess board!" << std::endl;
	cv::waitKey(0);
   // exit(-1);
    }
 
  drawChessboardCorners(image, boardSize, cv::Mat(imagePoints[0]), true );
 
  std::vector<std::vector<cv::Point3f> > objectPoints(1);
  objectPoints[0] = Create3DChessboardCorners(boardSize, squareSize);
 
  std::vector<cv::Mat> rotationVectors;
  std::vector<cv::Mat> translationVectors;
 
  cv::Mat distortionCoefficients = cv::Mat::zeros(8, 1, CV_64F); // There are 8 distortion coefficients
  cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
 
  int flags = 0;
  double rms = calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix,
                  distortionCoefficients, rotationVectors, translationVectors, flags|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);
 
  std::cout << "RMS: " << rms << std::endl;
 
  std::cout << "Camera matrix: " << cameraMatrix << std::endl;
  std::cout << "Distortion _coefficients: " << distortionCoefficients << std::endl;
 
  cv::imshow("Image View", image);
  cv::waitKey(0);
 
  return 0;
}
 
std::vector<cv::Point3f> Create3DChessboardCorners(cv::Size boardSize, float squareSize)
{
  // This function creates the 3D points of your chessboard in its own coordinate system
 
  std::vector<cv::Point3f> corners;
 
  for( int i = 0; i < boardSize.height; i++ )
  {
    for( int j = 0; j < boardSize.width; j++ )
    {
      corners.push_back(cv::Point3f(float(j*squareSize),
                                float(i*squareSize), 0));
    }
  }
 
  return corners;
}