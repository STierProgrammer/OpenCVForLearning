#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using std::string;

void showImageCV() {
	string path = "Resources/test.png";
	
	cv::Mat img = cv::imread(path);
	cv::imshow("Image", img);

	cv::waitKey(0);
}

void showVideoCV() {
	string path = "Resources/test_video.mp4";
	cv::VideoCapture cap(path);

	cv::Mat img;

	while (true) {
		cap.read(img);

		cv::imshow("Video", img);
		cv::waitKey(1);
	}
}

void showWebcamCV() {
	cv::VideoCapture cap(0);
	cv::Mat img;

	while (true) {
		cap.read(img);

		cv::imshow("Webcam", img);
		cv::waitKey(1);
	}
}

void showImageTestsCV() {
	string path = "Resources/test.png";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

	cv::imshow("Image", img);
	cv::waitKey(0);
}

int main() {

	return 0;
}