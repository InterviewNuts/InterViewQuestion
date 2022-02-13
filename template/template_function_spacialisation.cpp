#include <iostream>
using namespace std;

template<typename T>
void func(T arg)
{
    cout << "General template Function  \n";
    cout << arg << "\n";
}
template<>
void func<int>(int x)
{
    cout << " Spacialation " << x << "\n";
}

//! class template spacialisation example
template <class T>
class Test
{
    // Data members of test
public:
    Test()
    {
        // Initialization of data members
        cout << "General template object \n";
    }
    // Other methods of Test
};

template <>
class Test <int>
{
public:
    Test()
    {
        // Initialization of data members
        cout << "Specialized template object\n";
    }
};




int main()
{

    func(4.5);
    func(90);

    Test<int> a;
    Test<char> b;

    return 0;
}