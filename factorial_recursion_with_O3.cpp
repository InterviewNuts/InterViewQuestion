
/**
 * @file factorial_recursion_with_O3.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright Copyright (c) 2022
 *
 */

 /*

Types of Recursion:
There are five types of recursions. They are as follows:

1) Tail Recursion
2) Head Recursion
3) Tree Recursion
4) Indirect Recursion
5) Nested Recursion
-----------------------

What does it mean by Tail Recursion?
If a function is calling itself and that recursive call is the last statement in a function then
it is called tail recursion. After that call there is nothing, it is not performing anything,
so, it is called tail recursion. For better understanding
#include <stdio.h>
void fun(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        fun(n-1);
    }
}
int main ()
{
    fun(3);
    return 0;
}


if you compile program with g++ *.cpp -O3
then you  will see compile time / build time increases and code size increases but
run time performance is increased.
Because O3 flag removes the recurasion call & do the optimisation ,
You can check it by using -S flag.

I have checked in all these exe as well , It increases the size if we use O3 flagg.

 */
#include<iostream>
using namespace std;

// A tail recursive function to calculate factorial
unsigned factTR(unsigned int n, unsigned int a)
{
    if (n == 1)  return a;

    return factTR(n - 1, n * a);
}



// Driver program to test above function
int main()
{
    cout << factTR(3, 1);
    return 0;
}