
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main ( int argc, char **argv )
{
    Mat im_gray;
    Mat img_bw;
    Mat img_final;

    Mat im_rgb  = imread("D:\\storeroom\\unwantedPack\\4.jpg");
    cvtColor(im_rgb,im_gray,CV_RGB2GRAY);
	imshow("gg:",im_rgb);


    adaptiveThreshold(im_gray, img_bw, 255, ADAPTIVE_THRESH_MEAN_C, 0, 105, 1); 
	imshow("thres",img_bw);


    dilate(img_bw, img_final, Mat(), Point(-1, -1), 2, 1, 1);


    imshow("cam_final.jpg", img_final);
	waitKey(0);

    return 0;
}