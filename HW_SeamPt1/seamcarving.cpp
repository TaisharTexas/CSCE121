#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::ostringstream;

int main() { 
  cout << "Input filename: ";
  string filename;
  cin >> filename;
  
  // TODO(student): add error checking for width, height, targetWidth, and targetHeight
  cout << "Input width and height: ";
  int width = 0;
  int height = 0;
  cin >> width >> height;
  cout << "Input target width and height: ";
  int targetWidth = 0;
  int targetHeight = 0;
  cin >> targetWidth >> targetHeight;
  
  // save originalWidth since width will change with carving
  int originalWidth = width; 
  
  Pixel** image1 = createImage(width, height);
  if (image1 != nullptr) { // new returns nullptr if it fails to allocate array

    if (loadImage(filename, image1, width, height)) {
      
      // uncomment for part 2
      /*
      while ((width - targetWidth > 0) || (height - targetHeight > 0)) {
        if (width - targetWidth > 0) {
          int* verticalSeam = findMinVerticalSeam(image, width, height);
          removeVerticalSeam(image, width, height, verticalSeam);
          deleteSeam(verticalSeam);
          width--;
        }
        
        // this is for the extra credit
        if (height - targetHeight > 0) {
          int* horizontalSeam = findMinHorizontalSeam(image, width, height);
          removeHorizontalSeam(image, width, height, horizontalSeam);
          deleteSeam(horizontalSeam);
          height--;
        }
      }
      */
      
      ostringstream oss;
      oss << "carved" << width << "X" << height << "." << filename;
      outputImage(oss.str().c_str(), image1, width, height);
    }
  }
  
  // call last to remove the memory from the heap
  deleteImage(image1, originalWidth);
}