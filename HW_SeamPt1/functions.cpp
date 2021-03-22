#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;

using std::cout;
using std::endl;
using std::string;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
    // TODO(student): create a seam
    INFO(length);
  return nullptr;
}

void deleteSeam(int* seam) {
    // TODO(student): delete a seam
    INFO(seam);
}

bool loadImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): load an image
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): output an image
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
  return true;
}

int energy(Pixel** image, int column, int row, int width, int height) { 
    // TODO(student): compute the energy of a pixel
    INFO(image);
    INFO(column);
    INFO(row);
    INFO(width);
    INFO(height);
  return 0;
}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
    // TODO(student): load a vertical seam
    INFO(image);
    INFO(start_col);
    INFO(width);
    INFO(height);
    INFO(seam);
  return 0;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
    // TODO(student): load a horizontal seam
    INFO(image);
    INFO(start_row);
    INFO(width);
    INFO(height);
    INFO(seam);
  return 0;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min vertical seam
    INFO(image);
    INFO(width);
    INFO(height);
  return nullptr;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min horizontal seam
    INFO(image);
    INFO(width);
    INFO(height);
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
    // TODO(student): remove a vertical seam
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(verticalSeam);
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
    // TODO(student): remove a horizontal seam
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(horizontalSeam);
}
