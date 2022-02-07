#include <iostream>
using namespace std;
void convert()
{
    // 1
    int array[] = {1, 2, 0, 4, 6, 0, 9, 0, 4, 0, 3, 0, 9, 0, 1, 0, 3, 0};

    // 2
    int current = sizeof(array) / sizeof(array[0]) - 1;

    // 3
    for (int i = current - 1; i >= 0; i--)
    {
        if (array[i] != 0)
        {
            array[current] = array[i];
            current--;
        }
    }

    // 4
    while (current >= 0)
    {
        array[current] = 0;
        current--;
    }

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        cout << array[i] << " ";
    }
}
int main()
{
    convert();
}
