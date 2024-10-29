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
using namespace std;

#ifndef ALIEN_H
#define ALIEN_H

class Alien
{
    public:
    //default constructor
    Alien();

    //setters
    string getAlienName();
    void setAlienName(string _Alienname);
    //generators
    void generateAlienname(string filename);

    private:
    const static int _size=20;
    string _AlienNameArr[_size];
    string AlienName;

};

#endif