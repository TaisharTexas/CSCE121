#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <cctype>		// Contains isdigit, isalpha, isupper, etc.

using std::cin, std::cout, std::endl, std::string, std::sort;
using std::invalid_argument;

void get_ranking(const float *timeArray, unsigned int *rankArray);


int main()
{

    float dummy[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int otherDummy[9] = {};

    cout << "Start of function test" << endl;
    cout << "---------------------------" << endl;
    cout << "time data: " << dummy << endl;

    get_ranking(dummy, otherDummy);

    cout << "ranking: ";
    for(int i = 0; i < 9; i++)
    {
        cout << otherDummy[i] << ", ";
    }
    cout << endl;


    cout << "---------------------------" << endl;
    cout << "End of function test" << endl;

    return 0;
}

void get_ranking(const float *timeArray, unsigned int *rankArray)
{
	 	float timeCopy[9] = {};
		for(int i = 0; i < 9; i++)
		{
				timeCopy[i] = timeArray[i];
		}

		for(int k = 0; k < 9; k++)
		{
				int min = timeCopy[0];
				unsigned int minLoc = 0;
				for(int j = 0; j < 9; j++)
				{
						if(timeCopy[j] < min)
						{
								min = timeCopy[j];
								minLoc = j;
						}
				}
        timeCopy[minLoc] = 1000;
				rankArray[k] = minLoc;
		}

		cout << "Ran get_ranking" << endl;
}
