#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include<chrono>
#include<thread>
#include "Map.h"
#include "Planets.h"
#include "User.h"
#include "Crewmates.h"
#include "RescourceCenter.h"
#include "SpaceStore.h"
#include "Alien.h"
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals;

#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

class PlayerStatus
{
    public:
    // generates player status interface 
    void getplayerStatus(User player,ResourceCenter Store,Planets NewPlanet);
};

#endif