#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
 
using namespace cv;
 
int main( int argc, char** argv )
{
 char* imageName = argv[1];
 
 Mat image;
 image = imread( imageName, 1 );
 
 if( argc != 2 || !image.data )
 {
   printf( " No image data n " );
   return -1;
 }
 
 // Pixel access
 uchar pixValue;
 for (int i = 0; i < image.cols; i++) {
    for (int j = 0; j < image.rows; j++) {
        Vec3b &intensity = image.at<Vec3b>(j, i);
        for(int k = 0; k < image.channels(); k++) {
            // calculate pixValue
            image.at<Vec3b>(j, i)[0] = 2*image.at<Vec3b>(j, i)[0];
            image.at<Vec3b>(j, i)[1] = 2*image.at<Vec3b>(j, i)[1];
            image.at<Vec3b>(j, i)[2] = 2*image.at<Vec3b>(j, i)[2];
        }
     }
 }
 
 namedWindow( "talkera.org/opencv", CV_WINDOW_AUTOSIZE );
 imshow( "talkera.org/opencv", image );
 waitKey(0);
 
 return 0;
}
