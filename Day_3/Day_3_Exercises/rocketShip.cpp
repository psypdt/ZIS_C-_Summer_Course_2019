//
//  main.cpp
//  Example_Code
//
//  Created by Philipp Tiso on 30/05/2019.
//  Copyright © 2019 Philipp Tiso. All rights reserved.
//

//NOTE: Use g++ rocketship.cpp -o test to avoid linker issue with x86 architecture


#include <iostream>
#include <unistd.h>
#include <time.h>
using namespace std;

void animation1()
{
    system("clear");
    cout << "       " << endl;
    cout << "       " << endl;
    cout << "       " << endl;
    cout << "       " << endl;
    cout << "       " << endl;
    cout << "   ___ " << endl;
    cout << "  |___|" << endl;
    cout << "  |___|" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << " ||___||" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << " .o.oo.o" << endl;
    
    sleep(1);
}


void animation2()
{
    system("clear");
    cout << "       " << endl;
    cout << "       " << endl;
    cout << "   ___ " << endl;
    cout << "  |___|" << endl;
    cout << "  |___|" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << " ||___||" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << " .#.Vo.v" << endl;
    cout << "  vVY V" << endl;
    cout << "  v vv " << endl;
    cout << "       " << endl;
    
    sleep(1);
}


void animation3()
{
    system("clear");
    cout << "       " << endl;
    cout << "   ___ " << endl;
    cout << "  |___|" << endl;
    cout << "  |___|" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << " ||___||" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "  VVVVV  " << endl;
    cout << " v.Vo.v" << endl;
    cout << " . .oY.V" << endl;
    cout << "  Vv. ." << endl;
    cout << "  VV .   " << endl;
    
    sleep(1);
}


void animation4()
{
    system("clear");
    cout << "       " << endl;
    cout << "   ___ " << endl;
    cout << "  |___|" << endl;
    cout << "  |___|" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "         " << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "  VV V " << endl;
    cout << "   v v" << endl;
    cout << "   , .   " << endl;
    cout << "  .. ." << endl;
    cout << "    " << endl;
    
    sleep(1);
}


void animation5()
{
    system("clear");
    cout << "   ___ " << endl;
    cout << "  |___|" << endl;
    cout << "  |___|" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "       " << endl;
    cout << "       " << endl;
    cout << "       " << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "  VV V " << endl;
    cout << "   v v" << endl;
    cout << "       " << endl;
    cout << "       " << endl;
    
    sleep(1);
}


void animation6()
{
    system("clear");
    cout << "   ___ " << endl;
    cout << "  |___|" << endl;
    cout << "  |___|" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "  V V V " << endl;
    cout << "   V V " << endl;
    cout << "    V  " << endl;
    cout << "  . . . " << endl;
    cout << "    .  " << endl;
    cout << "  .   ." << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "       " << endl;
    
    sleep(1);
}



void animation7()
{
    system("clear");
    cout << "   ___ " << endl;
    cout << "  |___|" << endl;
    cout << "  |___|" << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    cout << "  V V V " << endl;
    cout << "  V V V " << endl;
    cout << "    V  " << endl;
    cout << "  . V . " << endl;
    cout << "    .  " << endl;
    cout << "  .   ." << endl;
    cout << "       " << endl;
    cout << " /|___|\\" << endl;
    cout << " ||___||" << endl;
    
    sleep(1);
}



int main()
{
    for(int i = 0; i < 10; i++)
    {
        animation1();
        animation2();
        animation3();
        animation4();
        animation5();
        animation6();
        animation7();
    }
    
    return 0;
}
