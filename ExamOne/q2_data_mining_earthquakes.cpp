#include <iostream>

using std::cout, std::cin, std::endl;

int main()
{
	int test[10] = { -12, 2, -2, 3, 5, -4, 78, -3, 19, 33};
	// the largest difference between values should be 82
	unsigned int answer = 0;
	int difference[9];

	// loop and compare
	for(int i = 0; i < (9); i++)
	{

		difference[i] = ( abs( test[i+1]-test[i] ));
		//check to see if the current value is larger than the previous max
		if(difference[i] > answer)
		{
			answer = difference[i];
		}

	}

	cout << "The anwer: " << answer << endl;
	return answer;
}
