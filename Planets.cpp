#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Planets.h"
using namespace std;
int randomNumbers(int min, int max) // random number generator
{
    return (rand() % (max - min + 1)) + min;
}

Planets::Planets()
{
    _planetname="";
    _planetSize=0;
    _carryingCapacity=0;
    _fuelneeded=50000;
    planetsExplored=0;
    acurateplanetsExplored=0;
    inaccurateplanetsExplored=0;

    for(int i=0;i<_htsize;i++)
    {
        habitableTraits[i]="";
        nonhabitableTraits[i]="";
    }

    frieandlyAlien="";
}

string Planets::getPlanetname()
{
    return _planetname;
}

double Planets::getplanetsize()
{
    return _planetSize;
}

double Planets::getcarryngCapacity()
{
    return _carryingCapacity;
}

double Planets::getfuelneeded()
{
    return _fuelneeded;
}

string Planets::gethabitabletratitsAt(int index)
{
    return habitableTraits[index];
}

string Planets::getnonhabitabletraitsAt(int index)
{
    return nonhabitableTraits[index];
}

string Planets::getfriendlyAlien()
{
    return frieandlyAlien;
}

int Planets::getPlanetsExplored()
{
    return planetsExplored;
}

int Planets::getaccuratePlanetsExplored()
{
    return acurateplanetsExplored;
}

int Planets::getinaccuratePlanetsExplored()
{
    return inaccurateplanetsExplored;
}

void Planets::setplanetname(string planetname)
{
    _planetname=planetname;
}

void Planets::setplanetsize(double planetsize)
{
    _planetSize=planetsize;
}

void Planets::setcarryingcapacity(double carryingCapacity)
{
    _carryingCapacity=carryingCapacity;
}

void Planets::setfuelneeded(double fuelneeded)
{
    _fuelneeded=fuelneeded;
}

void Planets::sethabitabletraitAt(int index,string trait)
{
    habitableTraits[index]=trait;
}

void Planets::setnonhabitabletraitAt(int index,string trait)
{
   nonhabitableTraits[index]=trait; 
}

void Planets::generatename(string filename) // creates planet name given limits 
{
    ifstream fin;
    string line;
    string planetname;
    string secondPart;
    int numbersforloop;
    string arr[3125];
    int i=0;
    char number;
    char Capitalletters;
    char letters;
    int numbers;

    fin.open(filename);

    while(getline(fin,line))
    {
       arr[i]=line;
       i++;
    }

    for(int i=0;i<9;i++)
    {
      number=randomNumbers(48,57);
      Capitalletters=randomNumbers(65,90);
      letters=randomNumbers(97,122);
      numbers=randomNumbers(1,3);
      numbersforloop=randomNumbers(0,3124);

      if(numbers==1)
      {
        planetname=planetname+number;
      }
      else if(numbers==2)
      {
        planetname=planetname+Capitalletters;
      }
      else
      {
        planetname=planetname+letters;
      }
    }
planetname=planetname+'-'+arr[numbersforloop];
_planetname=planetname;   
}

void Planets::generatesize() // generates the size randomly 
{
    double planetsize=randomNumbers(1,16)/2.0;
    _planetSize=planetsize;
}

void Planets::generatecapacity() // generates the planet size 
{
    _carryingCapacity=_planetSize*615.0;
}

void Planets::generatefuel()// generates the fuel needed for the next planet 
{   
    double fuelneeded;
    fuelneeded=_fuelneeded * _fuelneeded/1000000.0 + _fuelneeded;
    _fuelneeded=fuelneeded; 

}

void Planets::setPlanetsExplored(int _planetsExplored)
{
    planetsExplored=_planetsExplored;
}

void Planets::setaccuratePlanetsExplored(int _accuratePlanetsExplored)
{
    acurateplanetsExplored=_accuratePlanetsExplored;
}

void Planets::setinaccuratePlanetsExplored(int _inaccuratePlanetsExplored)
{
    inaccurateplanetsExplored=_inaccuratePlanetsExplored;
}

void Planets::setfriendlyAlien(string _friendlyAlien)
{
    frieandlyAlien=_friendlyAlien;
}