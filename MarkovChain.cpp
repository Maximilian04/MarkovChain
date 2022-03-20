#include "MarkovChain.hpp"

int MarkovChain::command(string command) {
    if (command == "exit") {
        return -3;
    } else if (command == "open") {
        string name;
        cin >> name;
        
        return addStat(name);
    }
    
    return -2;
}

int MarkovChain::addStat(string fileName) {
    
    return 0;
}

Mat MarkovChain::getMatrix() {
    return matrix;
}

MarkovChain::MarkovChain() : matrix(256, 256, CV_16FC1), statistics(256, vector<int>(256, 0)) {
}