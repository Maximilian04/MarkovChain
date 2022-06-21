#pragma once

#include <functional>
#include <opencv2/opencv.hpp>

using namespace cv;

class Mouse {
public:
	static void callBack(int event, int x, int y, int flags, void* userdata);

	static void waitKey(int delay); // instead of cv::waitKey()
	static const int& getKey();

	static const int& getX();
	static const int& getY();

	enum Button {
		NO = 0,
		LEFT,
		MIDDLE,
		RIGHT
	};

	static Button getButton();

private:
	static int x, y;

	static Button button;

	static int key;
};
