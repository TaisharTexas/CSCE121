#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <cctype>		// Contains isdigit, isalpha, isupper, etc.

using std::cin, std::cout, std::endl, std::string, std::sort, std::getline;
using std::invalid_argument;

int countVowels(const string (&sentences)[], int numSentences);

int main()
{
    int nSentences;
    string* theSentences;

    cout << "enter number of sentences: ";
    cin >> nSentences;
    cin.ignore(10000, '\n');
    theSentences = new string[nSentences];
    cout << endl;
    for(int i = 0; i < nSentences; i++)
    {
        cout << "enter sentence " << i+1 << ": ";
        getline(cin, theSentences[i]);
        // cout << "> " << theSentences[i] << endl;

    }

    cout << "There are " << countVowels(theSentences, nSentences)
         << " vowels in the " << nSentences << " given sentences." << endl;


    return 0;
}

int countVowels(const string (&sentences)[], int numSentences)
{
    int numVowels = 0;

    for(int i = 0; i < numSentences; i++)
    {
        string tempSentence = sentences[i];
        for(int k = 0; k < )
    }

    return numVowels;
}
