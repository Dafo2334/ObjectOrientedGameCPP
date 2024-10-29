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

#ifndef SPACESTORE_H
#define SPACESTORE_H

class SpaceStore
{
    public:
    // builds resaource center 
    User getSpacestore(User player,ResourceCenter Store,Planets NewPlanet);
};
#endif