#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;


// Drakes equation is as follows: N = R * f_p * n_e * f_l * f_i * f_c * L

// N : the number of civilizations in our galaxy with which communication might be possible, this is what you will be calculating
// R : the average rate of star formation in our galaxy
// f_p : the fraction of those stars that have planets
// n_e : the average number of planets that can potentially support life per star that has planets
// f_l : the fraction of planets that could support life that actually develop life at some point
// f_i : the fraction of planets with life that actually go on to develop intelligent life (civilizations)
// f_c : the fraction of civilizations that develop a technology that releases detectable signs of their existence into space
// L : the length of time for which such civilizations release detectable signals into space[


/*
 * The data SET/ ARRAY that you will be provided with is as follows (you MUST name them like this in the main):
 * RArray   = {1.0, 1.0, 1.5, 3.0}
 * FpArray  = {0.2, 0.5, 1.0, 1.0}
 * NeArray  = {1, 5, 3, 5}
 * FlArray  = {1.0, 1.0, 1.0, 1.0}
 * FiArray  = {1.0, 1.0, 0.0001, 1.0}
 * FcArray  = {0.1, 0.2, 0.001, 0.1}
 * LArray   = {1000, 345, 1000000000, 100000000}
*/



/*
 * Create a function that takes all the needed parameters for the drake equation, and returns an accurate result (use an appropriate type)
 * Check if the result is above 4, if that is the case then print a message that states what the variables were to allow this
 * NOTE: You may need to change the retrun type and the arguments
*/
void drakeEquation()
{
}




// Replace the AUTO keyword of the follwoing arrays with an appropriate type.
// The main will let you know if one of your answeres is incorrect.
int main()
{
    auto RArray[] = {1.0, 1.0, 1.5, 3.0};
    auto FpArray[] = {0.2, 0.5, 1.0, 1.0};
    auto NeArray[] = {1, 5, 3, 5};
    auto FlArray[] = {1.0, 1.0, 1.0, 1.0};
    auto FiArray[] = {1.0, 1.0, 0.0001, 1.0};
    auto FcArray[] = {0.1, 0.2, 0.001, 0.1};
    auto LArray[] = {1000, 345, 1000000000, 100000000};
    
    
    
    // You do NOT need to worry about this part, just worry about your method and the array types
    for(int i = 0; i < 4; i++)
    {
        auto n = drakeEquation(RArray[i], FpArray[i], NeArray[i], FlArray[i], FiArray[i], FcArray[i], LArray[i]);
        
        if((floor(n * 100.) / 100.) == 20.0)
        {
            cout << "Set1 is: " << n << " which is correct." << endl;
        }
        else if( (floor(n * 100.) / 100. ) == 172.5)
        {
            cout << "Set2 is: " << n << " which is correct." << endl;
        }
        else if( (floor(n * 100.) / 100. ) == 450.0)
        {
            cout << "Set3 is: " << n << " which is correct." << endl;
        }
        else if(n == 1.5e+08)
        {
            cout << "Set4 is: " << n << " which is correct." << endl;
        }
        else
        {
            cout << "Set" << i+1 << " evaluated to: " << drakeEquation(RArray[i], FpArray[i], NeArray[i], FlArray[i], FiArray[i], FcArray[i], LArray[i]) << " which is INCORRECT!" << endl;
        }
    }
}
