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
#include "LogBook.h"
using namespace std;
using namespace std::this_thread;     
using namespace std::chrono_literals;

//Builds log book based in current player stats , thats why we need to pass in the player stats saved in the various classes 
void LogBook::getLogBook(int pages,User player,Planets NewPlanet)
{
  int a=0;
  cout<<player.getname()<<"'s Log Book page #"<<pages<<": Planet "<<NewPlanet.getPlanetname()<<endl;
  cout<<"Planet size (in diameter of 1000 kms): " <<NewPlanet.getplanetsize()<<endl;
  cout<<"Planet's carrying capacity (in millions): "<<NewPlanet.getcarryngCapacity()<<endl;
  cout<<"Habitable traits discovered: ";
  for(int i=0;i<3;i++)
  {
    
      if(NewPlanet.gethabitabletratitsAt(i)!="")
      {
        if(i!=0)
        {
          cout<<", ";
        }

        cout<<NewPlanet.gethabitabletratitsAt(i)<<" ";
      }
      else
      {
          continue;
      }
  }
  cout<<endl;
  cout<<"Non-habitable traits discovered: ";
  for(int i=0;i<3;i++)
  {
      if(NewPlanet.getnonhabitabletraitsAt(i)!="")
      {
        if(i!=0)
        {
          cout<<", ";
        }
        cout<<NewPlanet.getnonhabitabletraitsAt(i)<<" ";
      }
      else
      {
          continue;
      }
  }
  cout<<endl;
  if(NewPlanet.getfriendlyAlien()!="")
  {
    cout<<"Friendly alien assessment: "<<NewPlanet.getfriendlyAlien()<<endl;   
  }
  else
  {
    cout<<"Friendly alien assessment: information not yet accuried or no Alien present in planet"<<endl;  
  }
  cout<<endl;
}