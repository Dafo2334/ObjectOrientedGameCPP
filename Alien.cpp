#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Planets.h"
#include "User.h"
#include  "Crewmates.h"
#include "RescourceCenter.h"
#include "Alien.h"
using namespace std;

int randomNumbers2(int min, int max) // random number generator
{
    return (rand() % (max - min + 1)) + min;
}

Alien::Alien()
{
    AlienName="";
    for(int i=0;i<20;i++)
    {
        _AlienNameArr[i]="";
    }
}

void Alien::generateAlienname(string filename)
{
    ifstream fin; //temproraray vriables that take track of each operation
    string line;
    int a=0;
    int value=0;

    fin.open(filename);

    if(fin.is_open()) // always chechk if the file is open 
    {
        while(getline(fin,line))// conditions to fill the array as long as the array can still be filled 
        {
            _AlienNameArr[a]=line;
            a++;
        }
    }
    AlienName=_AlienNameArr[randomNumbers2(0,19)];
}

void Alien::setAlienName(string _Aliename)
{
    AlienName=_Aliename;
}

string Alien::getAlienName()
{
    return AlienName;
}