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

int main()
{
    srand(time(NULL)); // to get different seed everytime 

User Daniel;
User(); // always use defaukt constructors to populate the classes accordingly 
Daniel.readCrew("Crewmates.txt");
Daniel.setselectedCrew(1);
Daniel.setselectedCrew(2);
Daniel.setname("Daniel");
cout<<Daniel.getWeponum()<<endl;

cout<<"User info"<<endl;
cout<<"name :"<< Daniel.getname()<<endl;
cout<<"health :"<< Daniel.gethp()<<endl;
cout<<"avaliable fuel :"<< Daniel.getfuel()<<endl;
cout<<"wepons :"<< Daniel.getWeponsAt(0)<<endl;
cout<<"space suit grade :" <<Daniel.getspaceSuit()<<endl;
cout<<"Crewmates :"<<endl;
for(int i=0;i<2;i++)
{
  cout<<Daniel.getcrewnameAt(i)<<endl;
}
cout<<endl;
cout<<"Crew Attributes:"<<endl;
for(int i=0;i<2;i++)
{
  cout<<Daniel.getcrewattributesAt(i)<<endl;
}
cout<<endl;

Planets Planet1;
Planets();// always use defaukt constructors to populate the classes accordingly 

cout<<"Planet info"<<endl;
Planet1.generatename("four_letter_words.txt");
Planet1.generatesize();
Planet1.generatecapacity();
Planet1.generatefuel();

cout<<"Planet name :"<<Planet1.getPlanetname()<<endl;
cout<<"Planet size :"<<Planet1.getplanetsize()<<endl;
cout<<"Planet capacity :"<<Planet1.getcarryngCapacity()<<endl;
cout<<"Fuel needed :"<<Planet1.getfuelneeded()<<endl;
Planet1.generatefuel();
cout<<"Fuel needed for next planet:"<<Planet1.getfuelneeded()<<endl;
cout<<endl;

ResourceCenter RecCenter;
ResourceCenter();// always use defaukt constructors to populate the classes accordingly 

cout<<"Resource Center Items"<<endl;
for(int i=0;i<3;i++)
{
    cout<<RecCenter.getweponstypeAt(i)<<" costs :"<<RecCenter.getweponspriceAt(i)<<endl;
}
for(int i=0;i<4;i++)
{
   cout<<"Space suit grade "<<RecCenter.getspacesuitgradeAt(i)<<" is $"<<RecCenter.getspacesuitpriceAt(i)<<endl; 
}
cout<<"fuel costs for 10k gallons : "<<RecCenter.getfuel()<<endl;
cout<<"translator cost :"<<RecCenter.gettranslator()<<endl;
cout<<"medkit cost :"<<RecCenter.getmedkit()<<endl;

}