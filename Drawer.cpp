#include "Drawer.hpp"

Drawer::Drawer() : window(512, 512, CV_8UC3) {
}

void Drawer::render(MarkovChain& markovChain) {
    for (int i = 0; i < window.rows; ++i) {
        for (int j = 0; j < window.cols; ++j) {
            window.at<Vec3b>(i, j)[1] = markovChain.getMatrix().at<float>(i / 2, j / 2) * 255;
            // (prev, curr)
        }
    }

    //putText(window,
    //    "!eof : " + to_string(cin.rdbuf()->in_avail()),
    //    Point(0, 10), cv::FONT_HERSHEY_PLAIN, 1.0, Scalar(255, 255, 255));
}

const Mat& Drawer::getWindow() {
    return window;
}
