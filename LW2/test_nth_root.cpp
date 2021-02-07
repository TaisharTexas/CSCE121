#include <iostream>
#include <cmath>
#include "./nth_root.h"

using std::cout;

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        try {
            double x = 1;
            int n = 0;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(4, -2);
        // try {nth_root(4, -2);} catch(...){cout<<"not a legal square root";}
        try {
            double x = -2;
            int n = 4;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(-2, 0);
        // try {nth_root(-2, 0);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 0;
            int n = -2;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(1, 5);
        // try {nth_root(1, 5);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 5;
            int n = 1;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(-1, 10);
        // try {nth_root(-1, 10);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 10;
            int n = -1;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(-3, 7);
        // try {nth_root(-3, 7);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 7;
            int n = -3;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(-8, 20runtime_error
        // try {nth_root(-8, 20);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 20;
            int n = -8;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(11, 4);
        // try {nth_root(11, 4);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 4;
            int n = 11;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(5, 1);
        // try {nth_root(5, 1);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 1;
            int n = 5;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(2, 0);
        // try {nth_root(2, 0);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 0;
            int n = 2;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(5, -3);
        // try {nth_root(5, -3);} catch(...){cout<<"not a legal square root";}
        try {
            double x = -3;
            int n = 5;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(6, 32);
        // try {nth_root(6, 32);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 32;
            int n = 6;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
        // nth_root(2, 5.7);
        // try {nth_root(2, 5.7);} catch(...){cout<<"not a legal square root";}
        try {
            double x = 5.7;
            int n = 2;
            nth_root(n, x);
            if(x < 0 || n <= 0){
                throw 20;
            }
        } catch(...){
            // cout<<"not a legal square root";
        }
    }



    // {   // TRY HARD
    //     // report the value
    //     double actual = nth_root(0, 1);
    //     std::cout << "nth_root(2, 1) = " << actual << std::endl;
    //     // actual = nth_root(4, -2);
    //     // std::cout << "nth_root(4, -2) = " << actual << std::endl;
    // }
    //
    // {   // TRY HARDER
    //     // compare the actual value to the expected value
    //     double actual = nth_root(2, 1);
    //     double expected = 1;
    //     if (std::fabs(actual - expected) > 0.00005) {
    //         std::cout << "[FAIL] (n=2, x=1)" << std::endl;
    //         std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
    //         std::cout << "  got " << actual << std::endl;
    //     } else {
    //         std::cout << "[PASS] (n=2, x=1)" << std::endl;
    //     }
    // }
}
