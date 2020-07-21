#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void convertAll(vector<string>& files_name) {
    for (int i = 0; i < (int)files_name.size(); i++) {

        string path = files_name[i];
    cout << path << endl;
        // reading image
        Mat image = imread(files_name[i], IMREAD_GRAYSCALE);
        //imshow("im", image);
        imwrite(files_name[i], image);
        // Saving with the same name but as gray
        waitKey();
    }
}

int main() {

    string directory = "negativePics\\"; // directory of the image
    string type = "*.png"; // read all png

    vector<string>files_name;

    // Glob function for collecting images from directories
    glob(directory+type,files_name, false);
    convertAll(files_name);
    return 0;
}
