#include <iostream>

using namespace std;
using std::cout;
using std::cin;

class Date
{
private:
    int day;
    int month;
    int year;

    friend ostream& operator << (ostream& os, const Date& d);

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    bool operator<(const Date& a);
    bool operator==(const Date& a);
};

ostream& operator << (ostream& os, const Date& d)
{
    cout << "Day: " << d.day << endl;
    cout << "Month: " << d.month << endl;
    cout << "Year: " << d.year << endl;
    return os;
}

bool Date::operator<(const Date& a)
{
    bool lessThan = false;
    if(this->year < a.year)
    {
        lessThan = true;
    }
    else if(this->month < a.month &&
            this->year == a.year)
    {
        lessThan = true;
    }
    else if(this->day < a.day &&
            this->month == a.month &&
            this->year == a.year)
    {
        lessThan = true;
    }
    else lessThan = false;

    return lessThan;
}

bool Date::operator==(const Date& a)
{
    bool isEqual = false;
    if(a.year == this->year){
        if(a.month == this->month){
            if(a.day == this->day){
                isEqual = true;
            }
            else isEqual = false;
        }
        else isEqual = false;
    }
    else isEqual = false;

    return isEqual;
}

int main()
{
    int day, month, year;
    cout << "Enter in date (day month year): ";
    cin >> day;
    cin >> month;
    cin >> year;
    cout << endl;
    Date firstDate(day, month, year);
    cout << "Enter in another date (day month year): ";
    cin >> day;
    cin >> month;
    cin >> year;
    cout << endl;
    Date secondDate(day, month, year);

    if(firstDate == secondDate) cout << "The dates are equal: \n" << firstDate;
    else if(firstDate < secondDate) cout << "The first date is smaller: \n" << firstDate;
    else cout << "The second date is smaller: \n" << secondDate;
}
