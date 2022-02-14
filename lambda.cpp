#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 42;
    int m = 456;
    vector<int> v1 = { 3, 1, 7, 9 };
    //! here we have taken as reference , so both read and write permision is there.
    auto fp = [&n]() ->void {
        n = n + 10;
    };
    fp();


    // access v1 by copy ( Read only, so we can not change the V1 , just use it.
    [v1]()
    {
        for (auto p = v1.begin(); p != v1.end(); p++)
        {
            cout << *p << " ";
        }
    };


    //! [=] denotes,   can access all variable
    [=]() -> void
    {
        cout << "M = " << m << "\n n = " << n << "\n";
    }();

    //! [m] denotes,   can access only m not n variable
    [m() -> void
    {
        //! lambda.cpp:35:50: error: 'n' is not captured , so wee need to  capture it 
        cout << "1::  M = " << m << "\n n = " << n << "\n";
    }();

    cout << "value of  n : " << n << endl;
    // cout << "value of x: " << x << " type of x: " << typeid(x).name() << endl;

    return 0;
}