#pragma once

#include "MarkovChain.hpp"
#include "Mouse.hpp"

#include <opencv2/opencv.hpp>

using namespace cv;

class Drawer {
public:
    Drawer();

    void render(MarkovChain& markovChain);

    const Mat& getWindow();
private:
    void renderMatrix(MarkovChain& markovChain);
    void renderPopup();
    void updatePopup();

    Mat window;
    bool isPopupActive;
    Vec2i popupPos;
};
