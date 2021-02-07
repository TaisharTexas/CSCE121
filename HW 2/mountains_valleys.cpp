#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
		char a[20];
		char b[20];
		int firstNum;
		int secondNum;

		do {
				cout << "Enter numbers 10 <= a <= b < 10000: ";
				cin >> a;
				cin >> b;

				firstNum = atoi(a);
				secondNum = atoi(b);
		}
		while (!(is_valid_range(firstNum, secondNum)));

		count_valid_mv_numbers(firstNum, secondNum);


		return 0;
}
