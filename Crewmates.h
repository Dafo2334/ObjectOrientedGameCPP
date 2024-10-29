#include <iostream>
#include <string>
using namespace std;


#ifndef CREWMATES_H
#define CREWMATES_H

class Crewmates
{
    public:
    //default constructors
    Crewmates();
    Crewmates(string crewname,string attributes);

    //getters
    string getcrewname();
    string getcrewattributes();

    //setters
    void setcrewmatename(string crewname);
    void setcrewnameattributes(string attributes);
    


    private:
    string _crewname;
    string _attributes;
   
};

#endif