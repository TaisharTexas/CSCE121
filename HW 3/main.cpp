#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

		string string1 = "125412135";
		string string2 = "365998134";
		// answer: 491410269

		add(string1, string2);

    // TODO(student): implement the UI
}
