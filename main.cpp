#include "MarkovChain.hpp"
#include "Console.hpp"
#include "Mouse.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    setlocale(LC_ALL, "Russian");

    Mat window(512, 512, CV_8UC3);
    int key = -1;
    string command;

    MarkovChain markovChain;

    Console::start();

    namedWindow("Markov Chain");
    setMouseCallback("Markov Chain", Mouse::callBack);

    while (key != 27) {
        if (Console::hasGotInput()) {
            command = Console::getInput();

            int result = markovChain.command(command);
            if (result != 0) {
                switch (result) {
                case -2:
                    cout << result << ": wrong command" << endl;
                    break;
                case 1:
                    cout << result << ": cannot open file" << endl;
                    break;
                case -3:
                    return 0;
                    break;
                default:
                    cout << result << ": error" << endl;
                }
            }
            //cout << command << endl;
        }

        for (int i = 0; i < window.rows; ++i) {
            for (int j = 0; j < window.cols; ++j) {
                window.at<Vec3b>(i, j)[1] = markovChain.getMatrix().at<float>(i / 2, j / 2) * 255;
                // (prev, curr)
            }
        }

        //putText(window,
        //    "!eof : " + to_string(cin.rdbuf()->in_avail()),
        //    Point(0, 10), cv::FONT_HERSHEY_PLAIN, 1.0, Scalar(255, 255, 255));

        imshow("Markov Chain", window);
        key = waitKey(10);
    }

    cout << "Program finished 0" << endl;
    return 0;
}
