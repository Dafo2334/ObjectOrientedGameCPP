#include <iostream>
#include <string>
using namespace std;


#ifndef RESOURCECENTER_H
#define RESOURCECENTER_H

// this class is only here to get the vales and strings assigned with each category , the space store executes the build of the store 
class ResourceCenter
{
    public:
    // default constructor
    ResourceCenter();

    //only getters since we dont change values of this 
    int getweponspriceAt(int index);
    string getweponstypeAt(int index);
    int gettranslator();
    int getmedkit();
    int getspacesuitpriceAt(int index);
    int getspacesuitgradeAt(int index);
    int getfuel();

    

    private:
    const static int _size=3;
    int _weponsprice[_size];
    string _weponType[_size];
    int _translator;
    int _medkit;
    const static int _size1=4;
    int _Spacesuitprice[_size1];
    int _Spacesuitgrade[_size1];
    int _fuel;
};

#endif

//user1.setmoney(money-resource1.getwepons(1))