#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "AggiePatrons.h"

using namespace std;


// default constructor
AggiePatrons::AggiePatrons() : table(nullptr), numDays(0), numPatrons(0),
                   dayCapacity(0), patronCapacity(0) {}

// copy constructor
AggiePatrons::AggiePatrons(const AggiePatrons& src) :
                   table(nullptr), numDays(0), numPatrons(0),
                   dayCapacity(0), patronCapacity(0) {
  this->resizeTable(src.patronCapacity, src.dayCapacity);
  this->numDays = src.numDays;
  this->numPatrons = src.numPatrons;
  for (unsigned int patron=0; patron<numPatrons; ++patron) {
    for (unsigned int day=0; day<numDays; ++day) {
      table[patron][day] = src.table[patron][day];
    }
  }
}

// destructor
AggiePatrons::~AggiePatrons() {
  deleteTable();
}

// copy assignment
AggiePatrons& AggiePatrons::operator=(const AggiePatrons& src) {
  if (this != &src) { // check for self assignment
    this->deleteTable(); // delete old memory
    this->resizeTable(src.patronCapacity, src.dayCapacity); // allocate new memory
    this->numDays = src.numDays;
    this->numPatrons = src.numPatrons;
    // copy
    for (unsigned int patron=0; patron<numPatrons; ++patron) {
      for (unsigned int day=0; day<numDays; ++day) {
        table[patron][day] = src.table[patron][day];
      }
    }
  }
  return *this;
}


void AggiePatrons::print() {
  if (table == nullptr) {
    cout << "Empty Table" << endl;
  }
  for (unsigned int patron = 0; patron < numPatrons; ++patron) {
    for (unsigned int day = 0; day < numDays; ++day) {
      cout << table[patron][day] << '\t';
    }
    cout << endl;
  }
}

void AggiePatrons::deleteTable() {
  for (unsigned int row = 0; row < patronCapacity; ++row) {
    delete [] table[row];
  }
  delete [] table;
  table = nullptr;
  patronCapacity = 0;
  dayCapacity = 0;
  numPatrons = 0;
  numDays = 0;
}

void AggiePatrons::increasePatrons() {
  unsigned int newPatronCapacity = patronCapacity*2;
  resizeTable(newPatronCapacity, dayCapacity);
}

void AggiePatrons::increaseDays() {
  unsigned int newDayCapacity = dayCapacity*2;
  resizeTable(patronCapacity, newDayCapacity);
}

// new cells are initialized to 0
void AggiePatrons::resizeTable(unsigned int newPatronCapacity, unsigned int newDayCapacity) {

  unsigned int theNumPatrons = numPatrons;
  unsigned int theNumDays = numDays;
  // save a copy since deleteTable() function will reset them to 0

  if (newPatronCapacity == 0) newPatronCapacity = 1;
  if (newDayCapacity == 0) newDayCapacity = 1;


  // allocate new table
  unsigned int** newTable = new unsigned int*[newPatronCapacity];
  for (unsigned int row = 0; row < newPatronCapacity; ++row) {
    newTable[row] = new unsigned int[newDayCapacity] {0};
  }

  // copy values
  for (unsigned int row = 0; row < numPatrons; ++row) {
    for (unsigned int col = 0; col < numDays; ++ col) {
      newTable[row][col] = table[row][col];
    }
  }

  // delete old table
  deleteTable();
  // everything comes back zeroed out

  // update data members
  table = newTable;
  patronCapacity = newPatronCapacity;
  dayCapacity = newDayCapacity;
  numPatrons = theNumPatrons;
  numDays = theNumDays;

 }

void AggiePatrons::loadPatronData(std::string filename) {
  //cout << "starting loadPatronData" << endl;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw invalid_argument("Invalid filename: " + filename);
  }
  //cout << "Opened: " << filename << endl;
  string line;
  int patronIndex = 0;
  while (getline(ifs, line)) {
    //cout << "start processing lines" << endl;
    //cout << "line to process: " << line << endl;
    if (line.empty()) {
      //cout << "Empty line" << endl;
      continue;
    }
    addPatron();

    istringstream iss(line);

    int events = 0;
    int dayIndex = 0;

    while(iss >> events) {
      if (iss.fail())
        continue;
      //cout << "patronIndex: " << patronIndex << endl;
      //cout << "dayIndex: " << dayIndex << endl;
      //cout << "events: " << events << '\n' << endl;
      addDayEvent(patronIndex, dayIndex, events);
      dayIndex++;
    }
    patronIndex++;
  }
}

// add zeros too all patrons for the start day through the last day

// adds days needed to add the new day
void AggiePatrons::addDayEvent(unsigned int patronID, unsigned int dayID,
unsigned int events) {
  if (patronID >= numPatrons)
    throw invalid_argument("invalid patron ID");
  while (dayID >= dayCapacity) {
    increaseDays();
  }
  if (dayID >= numDays) {
    numDays = dayID + 1;
  }
  table[patronID][dayID] = events;

}

// adds an additional patron
void AggiePatrons::addPatron() {
  if (numPatrons == patronCapacity) {
    increasePatrons();
  }
  numPatrons++;
}

double AggiePatrons::getAverageAttendanceForDay(unsigned int dayID)
{
    try
    {
        double theSum = 0;
        double theAvg = 0;
        double cnt = 0;
        for(unsigned int i = 0; i < numPatrons; i++)
        {
            theSum += table[i][dayID];
            cnt++;
        }
        theAvg = theSum / cnt;

        return theAvg;
    }
    catch(...){ throw std::invalid_argument("dayID out of range"); }
}

unsigned int AggiePatrons::getTotalAttendanceForPatron(unsigned int patronID)
{
    try
    {
        int theSum = 0;
        for(unsigned int i = 0; i < numDays; i++)
        {
            theSum += table[patronID][i];
        }
        return theSum;
    }
    catch(...){ throw std::invalid_argument("patronID is out of range"); }
}

std::vector<unsigned int> AggiePatrons::getActiveDays()
{
    std::vector<unsigned int> bigDays{};
    for(unsigned int i = 0; i < numDays; i++)
    {
        int dayTotal = 0;
        for(unsigned int k = 0; k < numPatrons; k++)
        {
            dayTotal += table[k][i];
        }
        if(dayTotal > 4)
        {
            bigDays.push_back(i);
        }
    }
    return bigDays;
}

std::vector<unsigned int> AggiePatrons::getMostActivePatrons()
{
    int currMax = -1;
    std::vector<unsigned int> busyPatrons{};
    for(unsigned int i = 0; i < numPatrons; i++)
    {
        int patronTotal = 0;
        for(unsigned int k = 0; k < numDays; k++)
        {
            patronTotal += table[i][k];
        }
        if(patronTotal > currMax)
        {
            currMax = patronTotal;
            busyPatrons.clear();
            busyPatrons.push_back(i);
        }
        else if(patronTotal == currMax)
        {
            busyPatrons.push_back(i);
        }
    }
    return busyPatrons;
}
