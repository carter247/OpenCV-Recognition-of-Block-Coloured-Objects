
#include <sstream>
#include <string>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int objectNumber = 0;

// Object No's
// No object = 0
// Blue = 1
// Red = 2
// Green = 3
// Yellow = 4

char colour[50];            // Storage of user input
char blue[] = "blue";       // Comparison string - blue
char red[] = "red";         // Comparison string - red
char green[] = "green";     // Comparison string - green
char yellow[] = "yellow";   // Comparison string - yellow

int objectColour(char* str1, char* str2, char* str3, char* str4, char* str5){
    // Function to compare user input to possible options of colour
    
    int r1 = strncmp(str1, str2, 4);
    
    if(r1 == 0){
        
        objectNumber = 1;
    }
    
    else{
        
        objectNumber = 0;
        
    }   // Comparison of user input agaianst blue, if it matches then variable 'objectNumber' = 1
    
    int r2 = strncmp(str1, str3, 3);
    
    if(r2 == 0){
        
        objectNumber = 2;
    }
    
    else{
        
        objectNumber = 0;
        
    }   // Comparison of user input agaianst red, if it matches then variable 'objectNumber' = 2
    
    int r3 = strncmp(str1, str4, 5);
    
    if(r3 == 0){
        
        objectNumber = 3;
    }
    
    else{
        
        objectNumber = 0;
        
    }   // Comparison of user input agaianst green, if it matches then variable 'objectNumber' = 3
    
    int r4 = strncmp(str1, str5, 6);
    
    if(r4 == 0){
        
        objectNumber = 4;
    }
    
    else{
        
        objectNumber = 0;
        
    }   // Comparison of user input agaianst yellow, if it matches then variable 'objectNumber' = 4
    
    return objectNumber;
    
}   // Function returns the value of 'objectNumber'

int main(){
    
    Mat cameraFeed;     // Matrix to store each frame of the webcam feed
    Mat HSV;            // Matrix storage for HSV image
    Mat threshold1;      // Matrix storage for binary threshold image 1
    Mat threshold2;      // Matrix storage for binary threshold image 2
    Mat thresholdComb;      // Matrix storage for binary threshold image combination
    
    VideoCapture capture;   // Video capture object to acquire webcam feed
    
    capture.open(0);   // Open capture object at location zero (default location for webcam)
    
    cout << "What is the block colour of the object being detected?\n";
    cin >> colour;
    
    while(1){

        capture.read(cameraFeed);   // Store image to matrix "cameraFeed"
        
        cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);   // Convert image from BGR to HSV colorspace
        
        if(objectColour(colour, blue, red, green, yellow) == 0){
            
            inRange(HSV, Scalar(0, 0, 0), Scalar(255, 255, 255),threshold1);
            // Filter HSV image between values and store filtered image to threshold matrix
            
            imshow("Threshold Image",threshold1);   // Show threshold image 1
            
        }

        if(objectColour(colour, blue, red, green, yellow) == 1){
            
            inRange(HSV, Scalar(101, 124, 128), Scalar(203, 205, 255),threshold1);
            // Filter HSV image between values and store filtered image to threshold matrix
            
            imshow("Threshold Image",threshold1);   // Show threshold image 1
            
        }
        
        if(objectColour(colour, blue, red, green, yellow) == 2){
            
            inRange(HSV, Scalar(0, 160, 160), Scalar(14, 255, 255),threshold1);
            // Filter HSV image between values and store filtered image to threshold matrix 1
            
            inRange(HSV, Scalar(207, 160, 160), Scalar(255, 255, 255),threshold2);
            // Filter HSV image between values and store filtered image to threshold matrix
            
            add(threshold1, threshold2, thresholdComb);
            // adds value of elements from threshold 1 and threshold 2 and stored in thresholdComb
            
            imshow("Threshold Image",thresholdComb);   // Show threshold image combination
            
        }
        
        if(objectColour(colour, blue, red, green, yellow) == 3){
            
            inRange(HSV, Scalar(43, 214, 28), Scalar(122, 255, 255),threshold1);
            // Filter HSV image between values and store filtered image to threshold matrix
            
            imshow("Threshold Image",threshold1);   // Show threshold image 1
            
        }
        
        if(objectColour(colour, blue, red, green, yellow) == 4){
            
            inRange(HSV, Scalar(21, 135, 135), Scalar(56, 255, 255),threshold1);
            // Filter HSV image between values and store filtered image to threshold matrix
            
            imshow("Threshold Image",threshold1);   // Show threshold image 1
            
        }
        
        waitKey(30);   // Delay 30ms so that screen can refresh. Image will not appear without this waitKey() command
        
    }
    
    return 0;
    
}
