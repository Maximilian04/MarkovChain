#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
using namespace cv;

class MarkovChain {
public:
    int command(string command);
    int addStat(string fileName);
    
    Mat getMatrix();

    MarkovChain();
private:
    Mat matrix;
    vector<vector<int>> statistics;
};