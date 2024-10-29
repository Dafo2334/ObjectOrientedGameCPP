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
#include "SpaceStore.h"
using namespace std;

    // takes values of the player, resaource center and planet to build the store, needs to return user since it modifies it 
User SpaceStore::getSpacestore(User player,ResourceCenter Store,Planets NewPlanet)
{
    int choice=0;
    int secondChoice=0;
    int amount=0;
    int i=0;
    int a=1;
    do
{
    cout<<"Which item do you wish to buy?"<<endl;
    cout<<"1. Weapon"<<endl;
    cout<<"2. Translator"<<endl;
    cout<<"3. Space suit"<<endl;
    cout<<"4. Medical Kits"<<endl;
    cout<<"5. Fuel"<<endl;
    cout<<"6. Purchase and Leave"<<endl;
    cin>>choice;

    if(player.getmoney()==0)
    {
        cout<<"You have run out of money, explore to get more"<<endl;
    }
    else if(choice>6 || choice<1)
    {
        cout<<"Re-enter a valid option."<<endl;
    }
    else if (choice == 1)
    {
        do
        {
            cout<<"1. Light Saber"<<endl;
            cout<<"2. Blaster"<<endl;
            cout<<"3. Beam Gun"<<endl;
            cout<<"4. Go back to menu"<<endl;
            cin>>secondChoice;

            if(secondChoice>4 || secondChoice<1)
            {
                cout<<"Invalid Choice"<<endl;
            }
            else if(secondChoice==1 && (player.getWeponsAt(0)=="Light Saber" || player.getWeponsAt(1)=="Light Saber"))
            {   
               cout<<"You alredy have a Ligt Saber,choose another wepon or exit"<<endl; 
            }
            else if(secondChoice==2 && (player.getWeponsAt(0)=="Blaster" || player.getWeponsAt(1)=="Blaster"))
            {
                cout<<"You alredy have a Blaster,choose another wepon or exit"<<endl;
            }
            else if(secondChoice==3 && (player.getWeponsAt(0)=="Beam gun" || player.getWeponsAt(1)=="Beam gun"))
            {
                cout<<"You alredy have a Beam gun,choose another wepon or exit"<<endl;
            }
            else if(secondChoice!=4)
            {
                cout<<"Hom many " <<Store.getweponstypeAt(secondChoice-1)<< "s would you like to buy"<<"("<<Store.getweponspriceAt(secondChoice-1)<<"$ each)"<<endl;

                do
                {
                    cin>>amount;
                    if(amount>2)
                    {   
                        cout<<"You cannot have more than two weapons at the same time, re-enter a valid quantity."<<endl;
                    }
                    else if(amount<=0)
                    {
                        cout<<"Invalid quantity entered"<<endl;
                    }
                    else if(2<=player.getWeponum())
                    {
                        cout<<"Your wepon slots are full.Cannot purchase any more wepons"<<endl;
                        break;
                    }
                    else
                    {
                        if(player.getWeponum()==0)
                        {
                            
                            if(player.getmoney()-amount*Store.getweponspriceAt(secondChoice-1)<0)
                            {
                                cout<<"Insufficient funds please try again."<<endl;
                            }
                            else
                            {
                                player.setmoney(player.getmoney()-amount*Store.getweponspriceAt(secondChoice-1));
                                player.setweponsAt(0,Store.getweponstypeAt(secondChoice-1));
                            }
                        }
                        else
                        {
                            if(player.getmoney()-amount*Store.getweponspriceAt(secondChoice-1)<=0)
                            {
                                cout<<"Insufficient funds please try again."<<endl;
                            }
                            else
                            {
                                player.setweponsAt(1,Store.getweponstypeAt(secondChoice-1));
                                player.setmoney(player.getmoney()-amount*Store.getweponspriceAt(secondChoice-1));
                            }
                        }
                    cout<<"You have "<<player.getmoney()<<" left."<<endl;
                    }
                }while(amount>2 || amount<=0);
            }
        }while(secondChoice!=4);
    }
    else if (choice==2)
        {
            cout<<"Would you like to purchase a translator device ($5,000)? 1 for yes, 0 for no."<<endl;
            cin>>secondChoice;

            if(player.getmoney()-Store.gettranslator()<0)
            {
                cout<<"You have insufficeint funds."<<endl;
            }
            else if(secondChoice==1 && player.gettranslator()==0)
            {
                player.settranslator(1);
                player.setmoney(player.getmoney()-Store.gettranslator());
                cout<<"You have "<<player.getmoney()<<"$ left."<<endl;
            }
            else if(player.gettranslator()==1)
            {
                cout<<"You cant hold any more translators"<<endl;
            }
        }
    else if(choice==3)
    {
        if(player.getspaceSuit()==5)
        {
            cout<<"you alredy have the highest grade spaceSuit"<<endl;
        }
        else
        {
           cout<<"Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%."<<endl;
     for(int i=player.getspaceSuit()-1;i<4;i++)
     {
        cout<<a<<". Space suit grade "<<Store.getspacesuitgradeAt(i)<<" is "<<Store.getspacesuitpriceAt(i)<<"$"<<endl;
        a++;
     }
        do
        {
            cin>>secondChoice;
            if(secondChoice>a || secondChoice<1 || secondChoice>4)
            {
                cout<<"Invalid input, please try again"<<endl;
            }
            else if(player.getmoney()-Store.getspacesuitpriceAt(secondChoice-1)<0)
            {
                cout<<"You have insufficeint funds."<<endl;
            }
            else
            {
                player.setSpacesuit(secondChoice+1);
                cout<<"Your spacecuit is now a grade "<<secondChoice+1<<"."<<endl;
                player.setmoney(player.getmoney()-Store.getspacesuitpriceAt(secondChoice-1));
                cout<<"You have "<<player.getmoney()<<"$ left."<<endl;   
            }
        }while(secondChoice>a || secondChoice<1);
        a=1; 
        }
    }
    else if(choice==4)
    {
      cout<<"How many medical kits would you like to purchase ($2,000 each)? You currently have "<<player.getmedicalkit()<<", and can at most have 5."<<endl;

        cin>>secondChoice;
        if (player.getmedicalkit()==5)
        {
            cout<<"You cant buy any more medicalkits"<<endl;
        }
        else if(player.getmoney()-secondChoice*Store.getmedkit()<0)
        {
            cout<<"You have insufficeint funds."<<endl;
        }
        else if(player.getmedicalkit()+secondChoice>5)
        {
            cout<<"You have to many medkits try to buy a smaller amount"<<endl;
        }
        else
        {   
            player.setMedicalKit(secondChoice);
            player.setmoney(player.getmoney()-secondChoice*Store.getmedkit());
            cout<<"You have "<<player.getmoney()<<"$ left."<<endl; 
        }

    }
    else if(choice==5)
    {
        cout<<"You have "<<player.getfuel()<<" gallons of fuel. Your spacecraft can hold 400k gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s."<<endl; 
        do
        {
            cin>>secondChoice;
            if(player.getfuel()==400000)
            {
                cout<<"The fuel tank is already at capacity! So you cannot buy more."<<endl;
            }
            else if(secondChoice%100!=0)
            {
                cout<<"Input must be a multiple of 1000"<<endl;
            }
            else if(player.getmoney()-(secondChoice/10000)*Store.getfuel()<0)
            {
               cout<<"You have insufficeint funds."<<endl;
            }
            else
            {
                player.setfuel(player.getfuel()+secondChoice);
                player.setmoney(player.getmoney()-(secondChoice/10000)*Store.getfuel());
                cout<<"You have "<<player.getmoney()<<"$ left."<<endl; 
            } 
        }while(secondChoice%100!=0);
    }
}while(choice!=6);
return player;
}