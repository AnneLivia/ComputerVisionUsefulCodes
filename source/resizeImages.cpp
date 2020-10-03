#include <iostream>
#include "opencv2/opencv.hpp"
#include <vector>

using namespace std;
using namespace cv;

int main() {
    string directory = "C:\\Users\\annel\\Desktop\\positive";

    vector<string>files;

    glob(directory, files, false);

    int sizex = 400, sizey = 400;
    for(string file : files) {
        Mat img = imread(file, IMREAD_COLOR);
        cv::resize(img, img, Size(sizex, sizey));
        // getting the name and extension of the file to save as the same name and extension
        string filename = "";
        for(int i = (int)directory.size() + 1; i < (int)file.size(); i++) {
            filename+=file[i];
        }
        // saving in a new archive called resized+original file name to not overwrite the other files in case of regret
        imwrite(directory+"\\resized"+filename, img);
    }
    return 0;
}
