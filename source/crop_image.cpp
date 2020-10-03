#include <iostream>
#include "opencv2/opencv.hpp"
#include <vector>

using namespace std;
using namespace cv;

void save_detected(string dir, string filename, vector<Mat>& eyes);

int main()
{
    // directory where the images are
    string dir = "C:\\Users\\annel\\Desktop\\training_real\\";
    string save_dir = "C:\\Users\\annel\\Desktop\\eyes\\";
    // Mat to load images and convert to gray
    Mat image, gray;

    // using already created cascade to select eyes and crop them to create my own haar cascade file
    CascadeClassifier cascade("haarcascade_eye.xml");

    // array that stores all images located at dir
    vector<string>files;
    glob(dir+"*.jpg", files, false);

    string res;

    /*
    namedWindow("Image", WINDOW_NORMAL);
    resizeWindow("Image", 500, 500);
    namedWindow("Eye", WINDOW_NORMAL);
    resizeWindow("Eye", 60, 60);
    */

    // for each image, crop and save
    for(int k = 0; k < (int)files.size(); k++) {
        image = imread(files[k], IMREAD_COLOR);
        Mat copyImage = image;
        cvtColor(image, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, gray);

        string filename = "";
        for(int j = dir.size(); j < (int)files[k].size(); j++) {
            if (files[k][j] == '.')
                break;
            filename+=files[k][j];
        }
        vector<Rect>points;
        vector<Mat>eyes;

        cascade.detectMultiScale(gray, points, 1.9, 5);
        for (int i = 0; i < (int)points.size(); i++) {
            eyes.push_back(image(points[i]));
            // rectangle(copyImage, Point(points[i].x, points[i].y), Point(points[i].x + points[i].width,
            //            points[i].width + points[i].y), Scalar(255, 0, 0));
        }

        // imshow("Image", copyImage);
        save_detected(save_dir,"yes_"+filename+".bmp", eyes);
        // waitKey();
    }

    return 0;
}

void save_detected(string dir, string filename, vector<Mat>& eyes) {
    for (int i = 0; i < (int)eyes.size(); i++) {
        // imshow("Eye", eyes[i]);
        imwrite(dir+filename, eyes[i]);
        // waitKey();
    }
}
