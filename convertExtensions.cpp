#include <iostream>
#include "opencv2/opencv.hpp"
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    string directory = "C:\\Users\\annel\\Desktop\\EyeMovement\\Detect Eye\\haar Training\\positive\\rawdata";
    string initial_extension = "";
    string final_extension = ".bmp";

    vector<string>files_name;

    // Glob function for collecting images from directories and store all those file in file_name vector
    glob(directory+initial_extension,files_name, false);

    // to save file with the same name as the original file
    int sz = (int)directory.size();

    for (int i = 0; i < (int)files_name.size(); i++) {
        string path = files_name[i];

        // getting name of the file (without the original extension)"
        string namefile = "";
        for(int j = sz+1; j < (int)path.size(); j++) {
            if (path[j] == '.')
                break;
            namefile+=path[j];
        }

        Mat img = imread(path, IMREAD_COLOR);
        imwrite(directory+"\\"+namefile+".bmp", img);
    }
    return 0;
}
