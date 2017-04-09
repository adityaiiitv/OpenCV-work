// Author: Aditya Prakash
// Title: Create a coloured image in C++ using OpenCV.
#include "opencv2/highgui/highgui.hpp"
// highgui - an easy-to-use interface to video capturing, image and video codecs, as well as simple UI capabilities.
#include <iostream>
// For basic input / output operations.
using namespace cv;
// Namespace where all the C++ OpenCV functionality resides. 
using namespace std;
// For basic input / output operations. Else use macro 'std::' everywhere.
int main()
{
	Mat img(500, 1000, CV_8UC3, Scalar(0,0, 100));
	// To create an image
	// CV_8UC3 depicts : (3 channels,8 bit image depth
	// Height  = 500 pixels, Width = 1000 pixels
	// (0, 0, 100) assigned for Blue, Green and Red plane respectively. So the image will appear red as the red component is set to 100.

	if (img.empty()) //check whether the image is loaded or not
	{
		cout<<"\n Image not created. You have done something wrong. \n";
		return -1;	// Unsuccessful.
	}

	namedWindow("A_good_name", CV_WINDOW_AUTOSIZE);
	// first argument: name of the window
	// second argument: flag- types: 
	// WINDOW_NORMAL If this is set, the user can resize the window.
	// WINDOW_AUTOSIZE If this is set, the window size is automatically adjusted to fit the displayed image, and you cannot change the window size manually.
	// WINDOW_OPENGL If this is set, the window will be created with OpenGL support.

	imshow("A_good_name", img);
	// first argument: name of the window
	// second argument: image to be shown(Mat object)

	waitKey(0);					//wait infinite time for a keypress

	destroyWindow("A_good_name");	//destroy the window with the name, "MyWindow"

	return 0;
}
// END OF PROGRAM
