#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;





long double drakeEquation(double dR, double dFp, int iNe, double dFl, double dFi, double dFc, long lL)
{
    return dR * dFp * iNe * dFl * dFi * dFc * lL;
}


int main()
{
    double RArray[] = {1.0, 1.0, 1.5, 3.0};
    double FpArray[] = {0.2, 0.5, 1.0, 1.0};
    int NeArray[] = {1, 5, 3, 5};
    double FlArray[] = {1.0, 1.0, 1.0, 1.0};
    double FiArray[] = {1.0, 1.0, 0.0001, 1.0};
    double FcArray[] = {0.1, 0.2, 0.001, 0.1};
    long LArray[] = {1000, 345, 1000000000, 100000000};


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

    return 0;
}