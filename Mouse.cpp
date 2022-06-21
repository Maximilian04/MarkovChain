#include "Mouse.hpp"

int Mouse::key = -1; // key was pressed on keyboard

int Mouse::x = 0;
int Mouse::y = 0;

Mouse::Button Mouse::button = Mouse::Button::NO;

Mouse::Button Mouse::getButton() {
    Button res = button;
    button = Button::NO;
    return res;
}

void Mouse::callBack(int event, int _x, int _y, int flags, void* userdata) {
    switch (event) {
    case EVENT_MOUSEMOVE:
        y = _y;
        x = _x;
        break;
    case EVENT_LBUTTONDOWN:
        x = _x;
        y = _y;

        button = Button::LEFT;
        break;
    case EVENT_RBUTTONDOWN:
        x = _x;
        y = _y;

        button = Button::RIGHT;
        break;
    case EVENT_MBUTTONDOWN:
        x = _x;
        y = _y;

        button = Button::MIDDLE;
        break;
    }
}

void Mouse::waitKey(int delay) {
    key = cv::waitKey(delay);
}

const int& Mouse::getKey() {
    return key;
}

const int& Mouse::getX() {
    return x;
}

const int& Mouse::getY() {
    return y;
}
