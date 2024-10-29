#include <iostream>
#include <string>
#include "RescourceCenter.h"
using namespace std;

// default constructor 
ResourceCenter::ResourceCenter()
{
    _weponsprice[0]=1000;
    _weponType[0]="Light Saber";
    _weponsprice[1]=2000;
    _weponType[1]="Blaster";
    _weponsprice[2]=5000;
    _weponType[2]="Beam gun";
    _translator=5000;
    _medkit=2000;

    for(int i=1;i<_size1;i++)
    { 
        _Spacesuitprice[0]=5000;
        _Spacesuitprice[i]=_Spacesuitprice[i-1]+5000;

        _Spacesuitgrade[0]=2;
        _Spacesuitgrade[i]=i+2;
    }

    _fuel=1000;
}

int ResourceCenter::getweponspriceAt(int index)
{
    return _weponsprice[index];
}

string ResourceCenter::getweponstypeAt(int index)
{
    return _weponType[index];
}

int ResourceCenter::gettranslator()
{
    return _translator;
}

int ResourceCenter::getmedkit()
{
    return _medkit;
}

int ResourceCenter::getspacesuitpriceAt(int index)
{
    return _Spacesuitprice[index];
}

int ResourceCenter::getspacesuitgradeAt(int index)
{
    return _Spacesuitgrade[index];
}

int ResourceCenter::getfuel()
{
    return _fuel;
}