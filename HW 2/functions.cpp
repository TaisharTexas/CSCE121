#include <iostream>
#include "functions.h"



using std::cout, std::endl;

bool is_valid_range(int a, int b) {
		if ((a >= 10) && (a <= b) && (b < 10000)){
				return true;
		}
		else {
				cout << "Invalid Input" << endl;
				return false;
		}
	}

char classify_mv_range_type(int number) {
		int d1;
		int d2;
		int d3;
		int d4;
		int numberOfDigits = 0;
		int n = number;

	// find number of digits in the number given via the argument
		do {
			 ++numberOfDigits;
			 n /= 10;

		}
		while (n != 0);

	// based on number of digits, split the number into its individual digits
		if(numberOfDigits == 2){
				d1 = number / 10;
				d2 = number % 10;
				if(d1 < d2){
						return 'M';
				 }
				 else if(d2 < d1){
						 return 'V';
				 }
				 else{
					 	return 'N';
				 }
		}
		else if(numberOfDigits == 3){
				d1 = number / 100;
				d2 = (number / 10) % 10;
				d3 = number % 10;
				if((d1 < d2) && (d2  > d3)){
						return 'M';
				}
				else if((d1 > d2) && (d2 < d3)){
						return 'V';
				}
				else{
						return 'N';
				}
		}
		else{
				d1 = number / 1000;
				d2 = (number / 100) % 10;
				d3 = (number / 10) % 10;
				d4 = number % 10;

				if((d1 < d2) && (d2 > d3) && (d3 < d4)){
						return 'M';
				}
				else if((d1 > d2) && (d2 < d3) &&  (d3 > d4)){
						return 'V';
				}
				else{
						return 'N';
				}
		}

}

void count_valid_mv_numbers(int startNum, int endNum) {
		int currentNum = startNum;
		int numMountains = 0;
		int numValleys = 0;
		while(currentNum <= endNum){
				char shape = classify_mv_range_type(currentNum);
				if(shape == 'M'){
						++numMountains;
				}
				else if(shape == 'V'){
						++numValleys;
				}

				++currentNum;
		}

		cout << "There are " << numMountains << " mountain ranges and " <<
				numValleys << " valley ranges between " << startNum << " and " <<
				endNum << "." << endl;
}
