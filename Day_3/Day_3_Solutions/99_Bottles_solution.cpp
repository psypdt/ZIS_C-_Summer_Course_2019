#include <cstdlib>
#include <iostream>
using namespace std;

//NOTE: This is done using the C++14 standard



/* NOTE: 
-   Doing "input - 1" is saying "subtract 1 from the current input, but DON'T SAVE that result"
-   Doing "input--" is saying "input = input-1", so the result gets SAVED!

- Doint input-- in the for loop will hence change the actual value of input. Doing input-1 WON'T change the actual value of input
*/



// This is how you would use a while loop to solve the problem
void while_solution_function(int input)
{
    if (input < 0) // If the input is NOT POSSITIVE, then we dont accept it
    {
        return;
    }

    while (input >= 0) // Loop while the current itteration is LESSTHAN or EQUAL TO 0
    {
        if (input == 0) // If we are at 0 bottles, print this special string
        {
            cout << "0 bottles of stuff on the wall 0 bottles of stuff." << endl;
            cout << "Can't take it down, can't pass it around because there are 0 bottles of stuff on the wall." << endl << endl;
            return; // The function ends since nothing else can be done
        }
        
        else if (input == 1) // If there is only 1 bottle left, print this special string
        {
            cout << "1 bottle of stuff on the wall, 1 bottle of stuff." << endl;
            cout << "Take it down pass it around 0 bottles of stuff on the wall." << endl << endl;
        }
        
        else
        {
            cout << input << " bottles of stuff on the wall, " << input << " bottles of stuff." << endl;
            cout << "Take it down pass it around " << input-1 << " bottles of stuff on the wall." << endl << endl;
        }
        input--; // Decrement the number of bottles permenantly
    }
    
}





// This is how you can use a for loop to solve the problem
void for_slolution_function(int input)
{
    if(input < 0) // If the input is negative, we reject it
    {
        return;
    }

    for(; input >= 0; input--) // No initialization is required
    {
        if (input == 0) // If we are at 0 bottles, print this special string
        {
            cout << "0 bottles of stuff on the wall 0 bottles of stuff." << endl;
            cout << "Can't take it down, can't pass it around because there are 0 bottles of stuff on the wall." << endl << endl;
            return; // The function ends since nothing else can be done
        }
        
        else if (input == 1) // If there is only 1 bottle left, print this special string
        {
            cout << "1 bottle of stuff on the wall, 1 bottle of stuff." << endl;
            cout << "Take it down pass it around 0 bottles of stuff on the wall." << endl << endl;
        }
        
        else
        {
            cout << input << " bottles of stuff on the wall, " << input << " bottles of stuff." << endl;
            cout << "Take it down pass it around " << input-1 << " bottles of stuff on the wall." << endl << endl;
        }
    }
}




int main()
{
    while_solution_function(2);
    for_slolution_function(2);
}
