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
	cv::Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, imgBlur, cv::Size(7, 7), 5, 0);
	cv::Canny(imgBlur, imgCanny, 50, 150);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

	cv::dilate(imgCanny, imgDil, kernel);
	cv::erode(imgDil, imgErode, kernel);

	cv::imshow("Image", img);
	cv::imshow("Image Gray", imgGray);
	cv::imshow("Image Blur", imgBlur);
	cv::imshow("Image Canny", imgCanny);
	cv::imshow("Image Dialation", imgDil);
	cv::imshow("Image Erode", imgErode);
	
	cv::waitKey(0);
}

int main() {
	showImageTestsCV();

	return 0;
}