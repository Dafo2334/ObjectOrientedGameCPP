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
#include "PlayerStatus.h"
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals;

#ifndef LOGBOOK_H
#define LOGBOOK_H

class LogBook
{
    public:
    //Log book builder
    void getLogBook(int page,User player,Planets NewPlanet);   
};

#endif