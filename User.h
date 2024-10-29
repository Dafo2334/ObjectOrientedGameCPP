#include <iostream>
#include <string>
#include "Crewmates.h"
using namespace std;


#ifndef USER_H
#define USER_H

class User
{
    public:
    User();

    string getname();
    int gethp(); 
    double getfuel();
    int getmoney();
    string getWeponsAt(int index); // get a specific wepon
    int getWeponum(); 
    int getspaceSuit();
    int getspaceSuithp();
    int gettranslator();
    int getmedicalkit();
    int getcrewnumber();
    int getHumansSaved();
    int getHumansKilled();
    int getHumansToSave();
    string getFullcrewNameAt(int index);
    string getFullcrewAttributesAt(int index);
    string getcrewnameAt(int index); // get the name of your selected crew
    string getcrewattributesAt(int index); //get the skiils of your selected crew



    void readCrew(string filename);
    void setselectedCrew(int index);
    void setname(string username);
    void sethp(int hp);
    void setfuel(double fuel);
    void setmoney(int money);
    void setweponsAt(int index,string value);
    void settranslator(int translator);
    void setMedicalKit(int medkit);
    void setSpacesuit(int spaceSuit);
    void setSpacesuithp(int spaceSuithp);
    void setHumansSaved(int HumansSaved);
    void setHumansKilled(int HumansKilled);
    void setHumansToSave(int HumansToSave);

    

    private:
    string _username;
    int _hp;
    double _fuel;
    int _money;
    const static int _size=2;
    string _wepons[_size];
    int _weponAmount;
    int _SpaceSuit;
    int _spaceSuithp;
    int _translator;
    int _medkit;
    const static int _size1=4;
    Crewmates _fullcrew[_size1];
    Crewmates _selectedcrew[_size];
    int _crewnumber=0;
    int _HumansSaved=0;
    int _HumansKilled=0;
    int _HumansToSave=0;
};

#endif