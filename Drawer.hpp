#pragma once

#include "MarkovChain.hpp"

#include <opencv2/opencv.hpp>

using namespace cv;

class Drawer {
public:
    Drawer();

    void render(MarkovChain& markovChain);

    const Mat& getWindow();
private:
    Mat window;
};
