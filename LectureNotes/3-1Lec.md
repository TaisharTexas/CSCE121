## String Stream


#### Linear Search of An Array
sizeof() returns the number of bytes taken up by an array.

char targ;
char sentence[] = "the quick brown fox jumped over the lazy dog";
cin >> targ;
int t = search( sentence, sizeof(sentence), targ );

#### Input String Stream

string greeting = "hello world";
string word;
string word2;
istringstream inputStream(greeting);

inputStream >> word >> word2;
cout << word << endl; // output: hello
cout << "my " << word2 << endl; //output: my world


while(true){
  cout << "Please enter first name, last initial and age (type exit to quit):"

  getline(cin, line);
  inputStream.clear();
  inputStream.str(line);
  inputStream >> firstName;

  if(firstName == "exit"){ break; }

  inputStream >> lastInitial;
  inputStream >> age;
}
