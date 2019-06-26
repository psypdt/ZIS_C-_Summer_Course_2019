#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;


void extension_of_exercise()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}



void print_simple_pyramid()
{
    for (int i = 0; i < 5; i++)
    {
        for(int j = 5 - i; j > 0; j--)
        {
            cout << "*";   
        }
        cout << endl;
    }
}




// You don't need to worry about the main function, you just need to complete the functions 
int main()
{
    print_simple_pyramid();


    return 0;
}
