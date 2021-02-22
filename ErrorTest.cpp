#include <iostream>
#include <stdexcept>
using std::cin, std::cout, std::endl;
using std::invalid_argument;

int main() {


    int low;
    int high;

    cin >> low;
    cin >> high;

    int value = 0;

    // if(low==INT32_MIN || high==INT32_MIN || low==INT32_MAX || high==INT32_MAX)
    // {
    //   throw std::invalid_argument("arguements out of bounds");
    // }
    if((low > high) || (high < low))
    {
        throw std::invalid_argument("invalid arguments: out of order");
    }
    else if(low == INT32_MIN)
    {
        value = INT32_MIN;
        cout << "1" << endl;
        return value;
    }
    else if((low < 0) && (abs(low) == high))
    {
        value = 0;
        cout << "2" << endl;;
        return value;
    }
    // else if(low <= (INT32_MIN / 2))
    // {
    //     value = low;
    //     cout << "3"<< endl;;
    //     return value;
    //     // throw(std::invalid_argument("invalid arguments: low too small"));
    // }
    else if(low == INT32_MAX)
    {
        value = INT32_MAX;
        cout << "4" << endl;
        return value;
        // throw(std::overflow_error("Value too big"));
    }
    else if((low == INT32_MIN) && (high == INT32_MAX))
    {
        value = (INT32_MIN + INT32_MAX);
        cout << "5" << endl;
        return value;
    }
    else
    {
        if((low < 0) && (high > 0))
        {
            if(abs(high) > abs(low))
            {
                low = abs(low) + 1;
                // cout << "new low triggered: " << low << endl;
                // return high + low;
            }
            else if(abs(low) > abs(high))
            {
                high = -1 * high;
            }
        }
        // value += low;
        for (int n = low; n <= high; n++)
        {
            // cout << "value: " << value << endl;
            // cout << "n: " << n << endl;
            // cout << "room: " << INT32_MAX - value << endl;
            if((n==INT32_MAX) && (value > 0))
            {
                throw(std::overflow_error("iterator too big"));
            }
            if(n==INT32_MIN)
            {
                throw(std::overflow_error("iterator too small"));
            }
            if((n > 0) && (value > 0))
            {
                if((n >= (INT32_MAX - value)) )
                {
                    throw(std::overflow_error("Value too big"));
                }
                else
                {
                    value += n;
                }
            }
            else if((n < 0) && (value < 0))
            {

                if(n < (INT32_MIN - value))
                {
                    if(n==INT32_MIN)
                    {
                        throw(std::overflow_error("Value too small: n=INT32_MIN"));
                    }
                    else if(n < (INT32_MIN / 2))
                    {
                        if(value < (INT32_MIN / 2))
                        {
                            throw(std::overflow_error("Value too small: value<INT32_MIN / 2"));
                        }
                        else if(value > (INT32_MIN / 2))
                        {
                            throw(std::overflow_error("Value too small: value>INT32_MIN / 2"));
                        }
                        else
                        {
                            throw(std::overflow_error("Value too small: not sure"));
                        }

                    }
                    else
                    {
                        throw(std::overflow_error("Value too small: general"));
                    }

                }
                else
                {
                    value += n;
                }
            }
            else
            {
                value += n;
                if(value == INT32_MAX)
                {
                    cout << "final sum: " << value << endl;
                    return value;
                }
            }

        }
        cout << "final sum: " << value << endl;
        return value;
    }



}


//-2147483646 2147483647
