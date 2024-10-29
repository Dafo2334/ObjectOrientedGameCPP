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

//buolds status inteface based on currrent player stats , needs classes to be passed by reference to be able to get nececarry data 
void PlayerStatus::getplayerStatus(User player,ResourceCenter store,Planets NewPlanet)
{
    cout<<"Health:"<<endl;
    cout<<endl;
    if(player.gethp()==100)
    {
        cout<<"____________________ "<<player.gethp()<<"%"<<endl;  
    }
    else if(player.gethp()<100 && player.gethp()>=75)
    {
        cout<<"_______________      "<<player.gethp()<<"%"<<endl;     
    }
    else if (player.gethp()<75 && player.gethp()>=50)
    {
        cout<<"_____________        "<<player.gethp()<<"%"<<endl;   
    }
    else if(player.gethp()<50 && player.gethp()>=25)
    {
        cout<<"________             "<<player.gethp()<<"%"<<endl; 
    }
    else if(player.gethp()>15)
    {
        cout<<"____                 "<<player.gethp()<<"%"<<endl;  
    }
    else
    {
        cout<<"_                    "<<player.gethp()<<"%"<<endl;
    }
    
    cout<<"Space Suit Health: "<<endl;
    cout<<endl;
    if(player.getspaceSuithp()==100)
    {
        cout<<"____________________ "<<player.getspaceSuithp()<<"%"<<endl;  
    }
    else if(player.getspaceSuithp()<100 && player.getspaceSuithp()>=75)
    {
        cout<<"_______________      "<<player.getspaceSuithp()<<"%"<<endl;     
    }
    else if (player.getspaceSuithp()<75 && player.getspaceSuithp()>=50)
    {
        cout<<"_____________        "<<player.getspaceSuithp()<<"%"<<endl;   
    }
    else if(player.getspaceSuithp()<50 && player.getspaceSuithp()>=25)
    {
        cout<<"________             "<<player.getspaceSuithp()<<"%"<<endl; 
    }
    else if(player.getspaceSuithp()>15)
    {
        cout<<"____                 "<<player.getspaceSuithp()<<"%"<<endl;  
    }
    else
    {
        cout<<"_                    "<<player.getspaceSuithp()<<"%"<<endl;
    }
    cout<<"Fuel Tank:"<<endl;
    if((player.getfuel()/4000)==100)
    {
        cout<<"____________________ "<<(player.getfuel()/4000)<<"%"<<endl;  
    }
    else if((player.getfuel()/4000)<100 && (player.getfuel()/4000)>=75)
    {
        cout<<"_______________      "<<(player.getfuel()/4000)<<"%"<<endl;     
    }
    else if ((player.getfuel()/4000)<75 && (player.getfuel()/4000)>=50)
    {
        cout<<"_____________        "<<(player.getfuel()/4000)<<"%"<<endl;   
    }
    else if((player.getfuel()/4000)<50 && (player.getfuel()/4000)>=25)
    {
        cout<<"________             "<<(player.getfuel()/4000)<<"%"<<endl; 
    }
    else if((player.getfuel()/4000)>15)
    {
        cout<<"____                 "<<(player.getfuel()/4000)<<"%"<<endl;  
    }
    else
    {
        cout<<"_                    "<<(player.getfuel()/4000)<<"%"<<endl;
    }
cout<<endl;
cout<<endl;


cout<<"Planets Explored: "<<NewPlanet.getPlanetsExplored()<<endl;
cout<<"Planets accurately reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
cout<<"Planets inaccurately reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;

cout<<endl;
cout<<endl;


cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;

cout<<endl;
cout<<endl;

int LightSaber=0;
int Blaster=0;
int BeamGun=0;
cout<<"-Money - $"<<player.getmoney()<<endl;
cout<<"-Wepons - "<<player.getWeponum()<<endl;
if(player.getWeponsAt(0)=="Light Saber" || player.getWeponsAt(1)=="Light Saber")
{
    LightSaber=1;
}
if(player.getWeponsAt(0)=="Blaster" || player.getWeponsAt(1)=="Blaster")
{
    Blaster=1;
}
if(player.getWeponsAt(0)=="Beam gun" || player.getWeponsAt(1)=="Beam gun")
{
    BeamGun=1;
}
cout<<"  1. Lightsaber - "<<LightSaber<<endl;
cout<<"  2. Blaster - "<<Blaster<<endl;
cout<<"  3. Beam gun - "<<BeamGun<<endl;
cout<<"- Translator - "<<player.gettranslator()<<endl;
cout<<"- Space Suit Grade #"<<player.getspaceSuit()<<endl;
cout<<"- Medical Kits - "<<player.getmedicalkit()<<endl;
cout<<"- Fuel - "<<player.getfuel()<<" Gallons"<<endl;

cout<<endl;
cout<<endl;
}