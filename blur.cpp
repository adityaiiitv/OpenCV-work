// Author: Aditya Prakash
// Title: OpenCV C++ Program to blur an image.
#include <opencv2/core/core.hpp>		//	Import the core header file
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>	//	For dealing with images
#include <stdio.h>
 
using namespace cv;						// Using namespace cv. We can also use 'namespace std' if need be.
 
int main( int argc, char** argv )		// Main function
{
 char* imageName = argv[1];
 
 Mat image;								// Mat object named image
 image = imread( imageName, 1 );		// Read the image in the directory
 
 if( argc != 2 || !image.data )			// Check if the image is loaded or not
 {
   printf( " No image data n " );		// Suitable message
   return -1;							// Unsuccessful
 }
 blur(image,image,Size(10,10));			// Function to blur the image
 namedWindow( imageName, CV_WINDOW_AUTOSIZE );	// Create a window with name as the image name
 imshow( imageName, image );			// Display the image
 waitKey(0);							// Wait infinite time for a keypress
 return 0;								// Return from the main function
}
