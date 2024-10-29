#include <iostream>
#include <string>
#include <fstream>
#include "Crewmates.h"
using namespace std;

//deafault constructors
Crewmates::Crewmates()
{
    _crewname="";
    _attributes="";
}

Crewmates::Crewmates(string crewname,string attributes)
{
    _crewname=crewname;
    _attributes=attributes;
}

//getters and setters
string Crewmates::getcrewname()
{
    return _crewname;
}

string Crewmates::getcrewattributes()
{
    return _attributes;
}

void Crewmates::setcrewmatename(string crewname)
{
    _crewname=crewname;
}

void Crewmates::setcrewnameattributes(string attributes)
{
    _attributes=attributes;
}
