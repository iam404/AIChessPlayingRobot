#include <iostream>

#include <opencv2/opencv.hpp>

CvRect box;
int main (int argc, const char * argv[])

{

    int saved = 1;
	char *name = new char[100];
	IplImage* img = cvLoadImage("D:\\chess\\croppedimg1.jpg");
	 //1
	
			box = cvRect(67,4,55,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");

			//2
			box = cvRect(67,59,53,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//3
			box = cvRect(68,110,52,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//4
			box = cvRect(67,165,57,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//5
			box = cvRect(67,219,52,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//6
			box = cvRect(67,273,50,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//7
			box = cvRect(66,327,54,50);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//8
			box = cvRect(67,379,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//9
			box = cvRect(122,5,51,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//10
			box = cvRect(123,57,50,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//11
			box = cvRect(122,111,53,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//12
			box = cvRect(120,165,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//13
			box = cvRect(119,217,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//14
			box = cvRect(120,272,51,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//15
			box = cvRect(120,326,50,50);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//16
			box = cvRect(121,380,51,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//17
			box = cvRect(175,3,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//18
			box = cvRect(175,57,52,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//19
			box = cvRect(175,112,50,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//20
			box = cvRect(175,167,51,49);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//21
			box = cvRect(173,219,52,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//22
			box = cvRect(173,274,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//23
			box = cvRect(174,328,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//24
			box = cvRect(178,380,53,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//25
			box = cvRect(229,4,53,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//26
			box = cvRect(229,59,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");

			//27
			box = cvRect(228,112,54,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//28
			box = cvRect(228,167,54,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//29
			box = cvRect(227,221,54,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//30
			box = cvRect(227,273,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//31
			box = cvRect(227,329,54,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//32
			box = cvRect(227,382,51,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//33
			box = cvRect(283,3,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//34
			box = cvRect(284,56,50,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//35
			box = cvRect(283,111,51,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//36
			box = cvRect(282,166,54,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//37
			box = cvRect(281,220,52,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//38
			box = cvRect(281,273,52,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//39
			box = cvRect(281,330,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//40
			box = cvRect(281,382,52,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//41
			box = cvRect(337,3,52,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//42
			box = cvRect(338,56,51,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//43
			box = cvRect(337,112,52,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//44
			box = cvRect(337,166,52,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//45
			box = cvRect(337,222,52,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//46
			box = cvRect(336,275,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//47
			box = cvRect(336,330,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//48
			box = cvRect(335,384,55,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//49
			box = cvRect(392,2,52,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//50
			box = cvRect(393,57,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//51
			box = cvRect(391,114,54,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//52
			box = cvRect(392,166,53,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//53
			box = cvRect(391,220,53,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//54
			box = cvRect(390,276,53,53);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//55
			box = cvRect(391,331,54,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//56
			box = cvRect(390,385,53,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//57
			box = cvRect(446,3,57,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//58
			box = cvRect(446,57,55,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//59
			box = cvRect(446,112,55,51);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//60
			box = cvRect(446,116,55,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//61
			box = cvRect(446,220,55,55);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//62
			box = cvRect(446,276,54,54);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//63
			box = cvRect(446,330,54,56);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			//64
			box = cvRect(444,385,54,52);
			cvSetImageROI(img, box);
			sprintf(name, "D:\\chess\\crop123\\%d.jpg", saved);
            cvSaveImage(name, img);
            cvResetImageROI(img);
            saved += 1;
            printf("saved");
			

			return 0;
}