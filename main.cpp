#include "Drawer.hpp"
#include "MarkovChain.hpp"
#include "Console.hpp"
#include "Mouse.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    setlocale(LC_ALL, "Russian");

    string command;

    MarkovChain markovChain;
    Drawer drawer;

    Console::start();

    namedWindow("Markov Chain");
    setMouseCallback("Markov Chain", Mouse::callBack);

    while (Mouse::getKey() != 27) {
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
        }

        drawer.render(markovChain);

        imshow("Markov Chain", drawer.getWindow());
        Mouse::waitKey(10);
    }

    cout << "Program finished 0" << endl;
    return 0;
}
