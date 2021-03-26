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
using std::ifstream;
using std::ofstream;

Pixel** createImage(int width, int height) {
  // cout << "Start createImage... " << endl;

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
  // cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  // cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
    int* seam = new int[length];
    for(int i = 0; i < length; i++){
        seam[i] = 0;
    }
    INFO(length);
    return seam;
}

void deleteSeam(int* seam) {
    delete [] seam;
    seam = nullptr;
    INFO(seam);
}

bool loadImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): load an image
    // cout << "Loading image..." << endl;
    // declare/define and open input file stream
    ifstream ifs (filename);

    // check if input stream opened successfully
    if (!ifs.is_open()) {
      cout << "Error: failed to open input file - " << filename << endl;
      return false;
    }

    // get type from preamble
    char type[3];
    ifs >> type; // should be P3
    if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
      cout << "Error: type is " << type << " instead of P3" << endl;
      return false;
    }

    // get width (w) and height (h) from preamble
    int w = 0, h = 0;
    ifs >> w;
    if(ifs.fail()){
        cout << "Error: read non-integer value" << endl;
        return false;
    }
    ifs >> h;
    if(ifs.fail()){
        cout << "Error: read non-integer value" << endl;
        return false;
    }

    if (w != width) { // check that width matches what was passed into the function
      cout << "Error: input width (" << width << ") does not match value in file (" << w << ")" << endl;
      return false;
    }
    if (h != height) { // check that height matches what was passed into the function
      cout << "Error: input height (" << height << ") does not match value in file (" << h << ")" << endl;
      return false;
    }

    // get maximum value from preamble
    int colorMax = 0;
    ifs >> colorMax;
    if(ifs.fail()){
        cout << "Error: read non-integer value" << endl;
        return false;
    }
    if (colorMax != 255) {
      cout << "Error: file is not using RGB color values." << endl;
      return false;
    }

    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            int lineValueR = 0, lineValueG = 0, lineValueB = 0;

            ifs >> lineValueR;
            if(ifs.eof()){
                cout << "Error: not enough color values" << endl;
                return false;
            }
            if(ifs.fail()){
                cout << "Error: read non-integer value" << endl;
                return false;
            }

            ifs >> lineValueG;
            if(ifs.eof()){
                cout << "Error: not enough color values" << endl;
                return false;
            }
            if(ifs.fail()){
                cout << "Error: read non-integer value" << endl;
                return false;
            }

            ifs >> lineValueB;
            if(ifs.eof()){
                cout << "Error: not enough color values" << endl;
                return false;
            }
            if(ifs.fail()){
                cout << "Error: read non-integer value" << endl;
                return false;
            }

            if( (lineValueR < 0 || lineValueR > 255)){
                cout << "Error: invalid color value " << lineValueR << endl;
                return false;
            }
            if( (lineValueB < 0 || lineValueB > 255)){
                cout << "Error: invalid color value " << lineValueB << endl;
                return false;
            }
            if( (lineValueG < 0 || lineValueG > 255)){
                cout << "Error: invalid color value " << lineValueG << endl;
                return false;
            }

            image[col][row].r = lineValueR;
            image[col][row].g = lineValueG;
            image[col][row].b = lineValueB;
        }
    }
    int nextValue;
    ifs >> nextValue;
    // cout << ifs.rdstate() << endl;
    if(!ifs.eof()){
        cout << "Error: too many color values" << endl;
        return false;
    }
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
    return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): output an image
    // cout << "Outputting image..." << endl;
    ofstream ofs;
    ofs.open(filename);

    if (!ofs.is_open())
    {
        cout << "Error: failed to open output file " << filename << endl;
        return false;
    }
    else
    {
        // TODO(student): output preamble
        ofs << "P3" << endl;
        ofs << width << " " << height << endl;
        ofs << 255 << endl;
        // TODO(student): output pixels
        for(int row = 0; row < height; row++)
        {
            for(int col = 0; col < width; col++)
            {
                ofs << image[col][row].r << endl;
                ofs << image[col][row].g << endl;
                ofs << image[col][row].b << endl;
            }
        }
        ofs.close();
    }
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
    return true;
}

int energy(Pixel** image, int column, int row, int width, int height) {

    int xRed, xGreen, xBlue,
        yRed, yGreen, yBlue,
        xGradient, yGradient, pxEnergy;

        if(column == 0)
        {
            xRed   = abs(image[column+1][row].r - image[width-1][row].r);
            xGreen = abs(image[column+1][row].g - image[width-1][row].g);
            xBlue  = abs(image[column+1][row].b - image[width-1][row].b);
        }
        else if(column == width-1)
        {
            xRed   = abs(image[0][row].r - image[column-1][row].r);
            xGreen = abs(image[0][row].g - image[column-1][row].g);
            xBlue  = abs(image[0][row].b - image[column-1][row].b);

        }
        else
        {
            xRed   = abs(image[column+1][row].r - image[column-1][row].r);
            xGreen = abs(image[column+1][row].g - image[column-1][row].g);
            xBlue  = abs(image[column+1][row].b - image[column-1][row].b);
        }
        if(row == 0)
        {
            yRed   = abs(image[column][row+1].r - image[column][height-1].r);
            yGreen = abs(image[column][row+1].g - image[column][height-1].g);
            yBlue  = abs(image[column][row+1].b - image[column][height-1].b);
        }
        else if(row == height-1)
        {
            yRed   = abs(image[column][0].r - image[column][row-1].r);
            yGreen = abs(image[column][0].g - image[column][row-1].g);
            yBlue  = abs(image[column][0].b - image[column][row-1].b);
        }
        else
        {
            yRed   = abs(image[column][row+1].r - image[column][row-1].r);
            yGreen = abs(image[column][row+1].g - image[column][row-1].g);
            yBlue  = abs(image[column][row+1].b - image[column][row-1].b);
        }

    xGradient = pow(xRed, 2) + pow(xGreen, 2) + pow(xBlue, 2);
    yGradient = pow(yRed, 2) + pow(yGreen, 2) + pow(yBlue, 2);
    pxEnergy = xGradient + yGradient;

    INFO(image);
    INFO(column);
    INFO(row);
    INFO(width);
    INFO(height);
    return pxEnergy;
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
