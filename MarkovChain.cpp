#include "MarkovChain.hpp"

int MarkovChain::command(string command) {
    if (command == "exit") {
        return -3;
    } else if (command == "open") {
        string name = Console::waitInput();

        return addStat(name);
    }

    return -2;
}

int MarkovChain::addStat(string fileName) {
    ifstream input(fileName);
    if (!input.is_open()) {
        return 1; // RETURN 1 FILE IS NOT OPENED
    }

    unsigned char symbol, prevSymbol = '\n';
    while (!input.eof()) {
        input >> symbol;

        // cout << symbol << " " << (int) symbol << endl;
        statistics[(unsigned int)prevSymbol][(unsigned int)symbol]++;
        prevSymbol = symbol;
    }

    for (int prev = 0; prev < 256; ++prev) {
        int sum = 0;
        for (int curr = 0; curr < 256; ++curr) {
            sum += statistics[prev][curr];
        }
        for (int curr = 0; curr < 256; ++curr) {
            matrix.at<float>(prev, curr) = (float)statistics[prev][curr] / sum;
        }
    }
    cout << "ok" << endl;

    return 0;
}

Mat MarkovChain::getMatrix() {
    return matrix;
}

MarkovChain::MarkovChain() : matrix(256, 256, CV_16FC1), statistics(256, vector<int>(256, 0)) {
}