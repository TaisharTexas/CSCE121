#include <iostream>
#include <vector>
#include "AggiePatrons.h"

using namespace std;

// Function to print the contents of class members that return a vector
void printVector(vector<unsigned int> vec, string label = "") {
  cout << label << ": " << endl;
  for (unsigned int i=0; i<vec.size(); ++i) {
    cout << vec.at(i) << endl;
  }
}

int main() {
  AggiePatrons ap;
  ap.loadPatronData("data.txt");
  ap.print();

  // cout << "patron attendance: " << ap.getTotalAttendanceForPatron(2) << endl;
  std::vector<unsigned int> myBigDays{};
  myBigDays = ap.getMostActivePatrons();
  for(int i = 0; i < myBigDays.size(); i++)
  {
      cout << myBigDays.at(i) << ", ";
  }
  cout << endl;


  // add calls to test your functions
  // Note there is a print vector function that will print the contents
  //   of class members that return a vector.


}
