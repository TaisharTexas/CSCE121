#include <iostream>

using std::cout, std::cin, std::endl, std::string;

string scrambleWord(string word);

int main()
{
	string aWord = "somethingthatwilllookweird";
	cout << "scrambled word: " << scrambledWord(aWord) << endl;
	return 0;
}

//scramble the word by swapping the odd index letters
string scrambleWord(string word)
{
	// cycle through every letter in the input string
	for(int i = 0; i < word.length(); i++)
	{
		// check if the current letter is odd and
		//   make sure that it's not the last letter
		if((i % 2) != 0 && (i != (word.length()-1)))
		{

			string letterA = word[i];
			string letterB = word[i-1];

			//check to make sure "e" would not be supplanted
			if(letterB != "e")
			{
				word[i-1] = letterA;
				word[i] = letterB;
			}

		}
	}

	return word;
}
