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

    float dummy[9] = {97.831, 38.3608, 60.8176, 77.5583, 71.9368, 53.3277, 46.9393, 74.7743, 64.1635};
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

    cout << "values: ";
    for(int j = 0; j < 9; j++)
    {
        cout << dummy[otherDummy[j]] << ", ";
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
				float min = timeCopy[0];
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
				rankArray[minLoc] = k+1;
		}

		cout << "Ran get_ranking" << endl;
}
