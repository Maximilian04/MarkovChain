#include "Drawer.hpp"

Drawer::Drawer() : window(512, 512, CV_8UC3), isPopupActive(false), popupPos(0, 0) {
}

void Drawer::render(MarkovChain& markovChain) {
    updatePopup();

    renderMatrix(markovChain);
    renderPopup();
}

void Drawer::renderMatrix(MarkovChain& markovChain) {
    for (int i = 0; i < window.rows; ++i) {
        for (int j = 0; j < window.cols; ++j) {
            window.at<Vec3b>(i, j)[0] = 0;
            window.at<Vec3b>(i, j)[1] = markovChain.getMatrix().at<float>(i / 2, j / 2) * 255;
            window.at<Vec3b>(i, j)[2] = 0;
            // (prev, curr)
        }
    }
}

void Drawer::renderPopup() {
    if (!isPopupActive) return;

    putText(window,
        string(1, (unsigned char)(popupPos[0] / 2)) + "->" + string(1, (unsigned char)(popupPos[1] / 2)),
        //to_string((unsigned char)(popupPos[0] / 2)) + "->" + to_string((unsigned char)(popupPos[1] / 2)),
        Point(popupPos), FONT_HERSHEY_PLAIN, 1.0, Scalar(255, 255, 255));


    window.at<Vec3b>(popupPos[0], popupPos[1])[2] = 255;
}

void Drawer::updatePopup() {
    switch (Mouse::getButton()) {
    case Mouse::Button::LEFT:
        isPopupActive = true;
        popupPos = Vec2i(Mouse::getX(), Mouse::getY());

        break;
    case Mouse::Button::RIGHT:
        isPopupActive = false;

        break;
    }
}

const Mat& Drawer::getWindow() {
    return window;
}
