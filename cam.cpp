#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/core/core.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
 
using namespace std;
using namespace cv;
 
int main( int argc, const char** argv )
{
   VideoCapture cap(0); // open the default camera
   if(!cap.isOpened()) // check if we succeeded
     return -1;
    Mat frame;
	cap >> frame;
	int rows1=frame.rows;
	int cols1=frame.cols;
	cols1=cols1*3;
	Mat img(rows1,cols1,CV_8UC3,Scalar(0,0,0));
	int prev[cols1][rows1];
	for(int i=0;i<rows1;i++)
	{
		for(int j=0;j<cols1;j++)
		{
			Scalar inten = img.at<uchar>(Point(j,i));
			prev[j][i]=inten[0];
		}
	}

   while(1)
   {
     cap >> frame;
     flip(frame,frame,1);
     for(int i=0;i<rows1;i++)
     {
		 for(int j=0;j<cols1;j++)
		 {
			Scalar intensity = frame.at<uchar>(Point(j,i));
			double r = ((double) rand() / (RAND_MAX));
			if(r<1 && (prev[j][i]-intensity[0])>100 || (intensity[0]-prev[j][i])>100)
			{
				prev[j][i] = 0;
				img.at<uchar>(Point(j,i))=255;

			}

		 }
	 }
     
     imshow("window", img); //display the image which is stored in the 'img' in the "MyWindow" window
     imshow("webcam", frame);
     if(waitKey(30) >= 0) break;
	}
}
