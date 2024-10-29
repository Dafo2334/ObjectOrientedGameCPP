#include <iostream>
#include <string>
using namespace std;


#ifndef PLANETS_H
#define PLANETS_H

class Planets
{
    public:
    Planets();
    
    string getPlanetname();
    double getplanetsize();
    double getcarryngCapacity();
    double getfuelneeded();
    string gethabitabletratitsAt(int index); 
    string getnonhabitabletraitsAt(int index);
    string getfriendlyAlien();
    int getPlanetsExplored();
    int getaccuratePlanetsExplored();
    int getinaccuratePlanetsExplored();

    void setplanetname(string planetname);
    void setplanetsize(double planetsize);
    void setcarryingcapacity(double carryingCapacity);
    void setfuelneeded(double fuelneeded);
    void sethabitabletraitAt(int index,string trait);
    void setnonhabitabletraitAt(int index,string trait);
    void setPlanetsExplored(int _planetsExplored);
    void setaccuratePlanetsExplored(int _accuratePlanetsExplored);
    void setinaccuratePlanetsExplored(int _inaccuratePlanetsExplored);
    void setfriendlyAlien(string _friendlyAlien);

    void generatename(string filename); // all these generate the info of a planet randomly 
    void generatesize();
    void generatecapacity();
    void generatefuel();

    private:
    string _planetname;
    double _planetSize;
    int _carryingCapacity;
    double _fuelneeded;
    const static int _htsize=3;
    string habitableTraits[_htsize]; // saves traits that player has disscovered 
    string nonhabitableTraits[_htsize]; //saves trait that player has disciovered so far
    string frieandlyAlien;
    int planetsExplored;
    int acurateplanetsExplored;
    int inaccurateplanetsExplored;
};

#endif