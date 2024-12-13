#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using std::string;
using cv::Mat;
using cv::VideoCapture;
using cv::Size;
using cv::Rect;
using cv::Scalar;
using cv::Point;
using cv::Point2f;

#define CARD_WIDTH 250
#define CARD_HEIGHT 350

void showImageCV() {
	// Path
	string path = "Resources/test.png";
	
	Mat img = cv::imread(path);

	cv::imshow("Image", img);
	cv::waitKey(0);
}

void showVideoCV() {
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);

	Mat img;

	while (true) {
		cap.read(img);

		cv::imshow("Video", img);
		cv::waitKey(1);
	}
}

void showWebcamCV() {
	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);

		cv::imshow("Webcam", img);
		cv::waitKey(1);
	}
}

void showWebcamResizeCV() {
	VideoCapture cap(0); 

	Mat img;
	Mat imgResize;

	while (true) {
		cap.read(img); 
		
		cv::resize(img, imgResize, Size(), 1.5, 1.5);

		cv::imshow("Webcam", img);
		cv::imshow("Webcam Resized", imgResize);

		cv::waitKey(1);
	}
}


void showImageTestsCV() {
	string path = "Resources/test.png";
	Mat img = cv::imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	cv::Canny(imgBlur, imgCanny, 50, 150);

	Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, Size(5, 5));

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

void showImageResizeCV() {
	string path = "Resources/test.png";

	Mat img = cv::imread(path);
	Mat imgResize;

	std::cout << img.type() << std::endl;

	// std::cout << img.size() << std::endl;

	// Defined size
	// cv::resize(img, imgResize, Size(640, 480));
	
	// Scaling
	cv::resize(img, imgResize, Size(), 0.5, 0.5);

	cv::imshow("Image", img);
	cv::imshow("Image Resize", imgResize);

	cv::waitKey(0);
}

void showImageCropCV() {
	string path = "Resources/test.png";
	Mat img = cv::imread(path);
	Mat imgCrop;

	Rect roi(200, 100, 300, 250);
	imgCrop = img(roi);

	cv::imshow("Image", img);
	cv::imshow("Image Crop", imgCrop);
	cv::waitKey(0);
}

void blankImageCreationCV() {
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	cv::circle(img, Point(256, 256), 155, Scalar(0, 69, 255), cv::FILLED);
	cv::rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), cv::FILLED);

	cv::line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	cv::putText(img, "STierProgrammer", Point(137, 262), cv::FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 69, 255), 2);

	cv::imshow("Image", img);
	cv::waitKey(0);
}


void imageWarpingCV(Mat& matrix, const Mat& imgWarp) {
	string path = "Resources/cards.jpg";
	Mat img = cv::imread(path);

	Point2f source[4] = {
		{ 529, 142 },
		{ 771, 190 },
		{ 405, 395 },
		{ 674, 457 }
	};
	Point2f destination[4] = {
		{ 0.0f, 0.0f },
		{ CARD_WIDTH, 0.0f },
		{ 0.0f, CARD_HEIGHT },
		{ CARD_WIDTH, CARD_HEIGHT }
	};

	matrix = cv::getPerspectiveTransform(source, destination);

	cv::warpPerspective(img, imgWarp, matrix, Point(CARD_WIDTH, CARD_HEIGHT));

	for (int i = 0; i < 4; i++) {
		cv::circle(img, source[i], 10, Scalar(0, 0, 255), cv::FILLED);
	}

	cv::imshow("Image", img);
	cv::imshow("ImageWarp", imgWarp);
	cv::waitKey(0);
}

int main() {
	Mat matrix, imgWarp;

	imageWarpingCV(matrix, imgWarp);

	return 0;
}