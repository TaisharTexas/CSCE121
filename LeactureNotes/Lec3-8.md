##Dynamic Memory

### RAII
- the preferred programming technique for interacting with c++ objects
- stands for Resource Acquisition is Initialization
- lets objects get resources (ie, open a file) during initialization and dispose of resources (ie, closing a file) during its destruction.

1) OPEN -- create a single statement that declares/defines file stream and lets initialization open the file stream (implicitly opens the file)
2) CHECKING -- check if file opened successfully
3) USING -- use the file stream
4) CLOSING -- implicitly close the file (file closes automatically when the object is destroyed)

/////////EXAMPLE/////////
//provide filename with a value
string filename = "";
ifstream fin(filename);
if(fin.open()) {
  //use file
  //closes automatically when exits
}

//////////OR/////////////

string filename = "";
ofstream fout(filename);
if(!fout.open()){
  throw std::runtime_error("cannot open file");
}

for(size_t i = 0; i < 3; i++)
{
  string word;
  cout << "enter a word" << endl;
  cin >> word;
  fout << word << " ";
}
///////////////////////////
