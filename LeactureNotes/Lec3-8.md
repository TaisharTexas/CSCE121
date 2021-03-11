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


### Hexadecimal

base 2  -- 0 1 10 11 100 101 110 111 1000 1001 1010 1011 1101
base 10 -- 1 2 3  4  5   6   7   8   9    10   11   12   13
base 16 -- 1 2 3  4  5   6   7   8   9    a    b    c    d

- change output format with std::dec, std::hex, etc


### Stacks
3 main functions
- push() : add element
- pop() : remove element
- top() : view latest element

Stacks have a Last In First Out structure, can only access the top value in the stack.
Get to other values by using pop() and top() to remove elements on top and access the desired element.

arrays: can access any element in array with index
        resizing a full array requires making a new bigger array
stacks: hard to access elements, need to pop elements until the element is reached
        resizing is easy, just keep pushing elements

the stack is where a function's local variables are kept

Dynamic Memory is kept in the Heap.
 - new keyword is used to initialize enough memory for that variable in the Heap (ie, new int;)

 - delete dynamically deallocates space in the Heap
 - garbage is created when space in the Heap is no longer accessible
 - dangling pointer is a pointer that no longer points to a valid space in Heap


 int* p = new int;
 \*p = 42;
 // creates an int p on the stack with a value 42 in the heap.

 delete p;
 //drops 42 from the heap because the value isn't needed any more, but the pointer p still exists in the stack
 p = new int(1337);
 //p now has a new value in the heap of 1337


 // creates a function in the stack
 void func(){
   //creates an int p with a value in the heap
   int* p = new int;
   //gets rid of the value of p in the heap
   delete p;
 }
 int main(){
   //calls the function
   func();
 }


///////////

int length;
cin >> length;
//creates aan array of length length
int* arr = new int[length]
