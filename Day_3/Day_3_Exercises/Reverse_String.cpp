#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


//NOTE: Use the C++14 standard
// Create a function that takes will reverse a word that it's given
// Hint: You can use the .length() function to determine how long the word is
// You may print the reversed word in this function, but you are not reqired to;


string reverse_word(string word)
{
    // insert code here
}



// The main function need not concern you, all you need to do is complete the function
int main()
{
    string words[] = {"abcd", "Hello", "Reverse me please"};
    string revArray[3];

    for(int i = 0; i < 3; i++)
    {
        revArray[i] = reverse_word(words[i]);
    }

    if(revArray[0] != "dcba")
    {
        cout << "Failed: " << revArray[0] << " is not correct" << endl;
    }

    if(revArray[1] != "olleH")
    {
        cout << "Failed: " << revArray[1] << " is not correct" << endl;
    }

    if(revArray[2] != "esaelp em esreveR")
    {
        cout << "Failed: " << revArray[2] << " is not correct" << endl;
    }

    else
    {
        cout << "All words were reversed correclty" << endl;
    }
    
    return 0;
}
