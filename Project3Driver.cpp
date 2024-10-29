#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
#include <cctype>
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

int split1(string inputString, char separator ,string arr[], int size)
{
    int j=0;
    int k=0;
    int splits=0;// tracks the amount of splits we have done;

if(inputString.empty()) // returns 0 in case of an ampty string 
    {
        return 0;
    }

    for(int i=0;i<inputString.length();i++)
    {
    if(k>=size) // if the string is split into more pieces than the array can handle it returns -1
    {
        return -1;
    }
        
        if(inputString[i]==separator) // takes care of splits if a separator is infornt of the word 
        {
            arr[k]=inputString.substr(j,i-j);
            k++;
            j=i+1;
        }
        else if(inputString[i]!=separator && k!=0 && i==(inputString.length()-1)) // takes care of the verry last split where no separator can be found 
        {
            arr[k]=inputString.substr(j,inputString.length()-j);
        }
        else if(k==0 && i==(inputString.length()-1)) // takes care of a string that is only composed of a single word
        {
            arr[k]=inputString;
        }
        else
        {
            continue;
        }
    }
    splits=k+1;
    return splits;
}

int randomNumbers1(int min, int max) // random number generator
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
srand(time(NULL));

//Generate all used classes and usees default constructors where needed to start game 
User player;
User();
player.readCrew("Crewmates.txt");

Planets NewPlanet;
Planets();

ResourceCenter Store;
ResourceCenter();

SpaceStore SpaceS;

Map NewMap;
Alien NewAlien;
PlayerStatus Status;
Alien();

LogBook NewBook;
string name;

cout<<"Enter your new name"<<endl;
cin.ignore();
getline(cin,name);
player.setname(name);
cout<<endl;

//all variables used durong the project initialized here 
int choice=0;
int gameChoice=0;
string garbage;
char alienChoice;
char UserChoice;
int secondChoice=0;
char mapChoice;
int amount=0;
int i=0;
int a=1;
int b=1;
int p=0;
int x=0;
int r=0;
int GoodTraitsFound=0;
int BadTraitsFound=0;
int page=0;
cout<<"Pick a crewmate to help you with your journey!"<<endl;
cout<<endl;

do
{
    b=1;
    for(int i=0;i<4;i++)//generates crewmate list 
    {  
        if(player.getcrewnameAt(0)==player.getFullcrewNameAt(i))
        {
            continue;
        }
        else
        {
            cout<<b<<"."<<player.getFullcrewNameAt(i)<<endl;
            cout<<"Ability: "<<player.getFullcrewAttributesAt(i)<<endl;
            b++;
        }
    }
    do
    { 
        cin>>choice;
        if(choice>b-1 || choice<1)
        {
            cout<<"Invalid input, please try again"<<endl;
            cout<<endl;
        }
    }while(choice>b-1 || choice<1);
    
    if(player.getcrewnameAt(0)=="Lola Doctor")
    {
        player.setselectedCrew(choice);
    }
    else if(player.getcrewnameAt(0)=="Nerys Fighter")
    {
        if(choice==1)
        {
            player.setselectedCrew(choice-1);
        }
        else
        {
            player.setselectedCrew(choice);
        }
    }
    else if(player.getcrewnameAt(0)=="Millie Tycoon")
    {
        if(choice==2 || choice==1)
        {
            player.setselectedCrew(choice-1);
        }
        else
        {
            player.setselectedCrew(choice);
        }
    }
    else
    {
        player.setselectedCrew(choice-1);
    }
   
       if(i==0)
    {
        cout<<"Great choice! "<<player.getcrewnameAt(0)<<" will bring a lot to your team. Pick your last crewmate."<<endl;
        cout<<endl;
        cout<<endl;
    }
    i++;  
    
}while(i!=2);

if(player.getcrewnameAt(0)=="Millie Tycoon" || player.getcrewnameAt(1)=="Millie Tycoon")//takse care of millie in players team 
{
    player.setfuel(player.getfuel()*2);
}  

cout<<endl;
cout<<endl;

cout<<"You have a very impressive crew. With your leadership, you will be sure to succeed"<<endl;
cout<<endl;
cout<<endl;

string filename="Instructions.txt"; //generates resource center instructions
ifstream fin;
string line;

fin.open(filename);

if(fin.is_open())
{
    while(getline(fin,line))
    {
        cout<<line<<endl;
    }
}
else
{
    cout<<"File with instructions not found"<<endl;
}
    cout<<"Press any key followed by enter to continue"<<endl;
    cin>>garbage;
    player=SpaceS.getSpacestore(player,Store,NewPlanet);

cout<<"Great purchase, Elon is sending a Cybertruck with your supplies to you right now."<<endl;

cout<<"Press any key followed by enter when you are ready to enter space and go to your first planet."<<endl;
cin>>garbage;
cout<<endl;
cout<<endl;
cout<<"3,2,1 . . . LIFTOFF! You are now in space. Hit enter to start exploring your first planet."<<endl;
player.setfuel(player.getfuel()-50000);

// End of stage 1 generating map attributes and random placemenet 
do
{
    // new planet generation with all numbers taken care of 
    NewPlanet.generatename("four_letter_words.txt");
    NewPlanet.generatesize();
    NewPlanet.generatecapacity();
    int temp=randomNumbers1(0,7);
    int temp1=randomNumbers1(2,6);
    int temp2=randomNumbers1(0,1);
    NewPlanet.setPlanetsExplored(NewPlanet.getPlanetsExplored()+1);
    page++;
    r=0;
    for(int i=0;i<temp;i++)//site generation 
    {
        int col=randomNumbers1(0,11);
        int row=randomNumbers1(0,11);
        int type=randomNumbers1(1,6);
        if(NewMap.spawnSite(col,row,type)==-1)
        {
            temp++;
        }   
    }
    if(temp2==1)//npc generation 
    {
        do
        {
            int col=randomNumbers1(0,11);
            int row=randomNumbers1(0,11);
            choice=NewMap.spawnNPC(col,row);
            
        }while(choice==-1);
    }
    for(int i=0;i<temp1;i++)//missfortune generation minimum 4 
    {
        int col=randomNumbers1(0,11);
        int row=randomNumbers1(0,11);
        int type1=randomNumbers1(1,100);
        if(type1<=50)
        {
          if(NewMap.spawnMisfortune(col,row,1)==-1)
            {
                temp1++;
            }  
        }
        else if(type1>50 && type1<=65)
        {
            if(NewMap.spawnMisfortune(col,row,2)==-1)
            {
                temp1++;
            }  
        }
        else if(type1>65 && type1<=80)
        {
            if(NewMap.spawnMisfortune(col,row,3)==-1)
            {
                temp1++;
            }  
        }
        else
        {
            if(NewMap.spawnMisfortune(col,row,4)==-1)
            {
                temp1++;
            }  
        }
    }
    int size=2;
    for(int i=0;i<size;i++)//misfortune alien generation 
    {
        int col=randomNumbers1(0,11);
        int row=randomNumbers1(0,11);
        if(NewMap.spawnMisfortune(col,row,1)==-1)
        {
            size++;
        }
    }
    
    do
    {
        //displays menu 
        cout<<"Planet name: "<<NewPlanet.getPlanetname()<<endl;
        NewMap.displayMap();
        cout<<"select one:"<<endl;
        cout<<"1. Move"<<endl;
        cout<<"2. View status"<<endl;
        cout<<"3. View log book"<<endl;
        cout<<"4. Resource center"<<endl;
        cout<<"5. Report planet as habitable"<<endl;
        cout<<"6. Enter wormhole to next planet"<<endl;
        cout<<"7. Give up"<<endl;
        cin>>choice;

        if(choice>7 || choice<1)
        {
            cout<<"Invalid input please try again"<<endl; 
        }
        else if(choice==1)
        {
            do
            {
                NewMap.displayMap();
                cout<<"Select one: w. up s. down d. right a. left m. menu"<<endl;
                
                do
                {
                    cin>>mapChoice; 
                  if(mapChoice!='w' && mapChoice!='s' && mapChoice!='a' && mapChoice!='d' && mapChoice!='m' )
                  {
                    cout<<"Invalid input try again."<<endl;   
                  }   
                }while(mapChoice!='w' && mapChoice!='s' && mapChoice!='a' && mapChoice!='d' && mapChoice!='m' );
                 
                if(NewMap.executeMove(mapChoice)==-1)
                {
                    cout<<"Out of range of map."<<endl;
                }
                else if(NewMap.isMisfortuneLocaton() && mapChoice!='m')
                {
                    if(NewMap.getMisfortuneType()==1)//alien atack, defense or forefit 
                    {
                        NewAlien.generateAlienname("Aliens.txt");
                        cout<<"You just ran into "<<NewAlien.getAlienName()<<" Think you can beat this dangerous alien for helping save humanity?"<<endl;
                        NewMap.revealMisfortune(NewMap.getPlayerRowPosition(),NewMap.getPlayerColPosition(),'*');
                        cout<<"What do you wish to do?"<<endl;
                        cout<<"1. Attack"<<endl;
                        cout<<"2. Forefit"<<endl;
                        cin>>secondChoice;

                        if(secondChoice>2 || secondChoice<1)
                        {
                            cout<<"Invalid input try again."<<endl;
                        }
                        else if(secondChoice==2)
                        {
                            if(player.getWeponum()>0)
                            {
                                if(player.getWeponsAt(0)!="")
                                {
                                    player.setweponsAt(0,"");
                                }
                                else
                                {
                                    player.setweponsAt(1,"");
                                }
                                cout<<"Really?! You chose to forfeit the battle? This is disappointing! You lost a weapon due to this decision. Hopefully, you git gud before you encounter the next alien."<<endl;
                            }
                            else
                            {
                                if(player.getmoney()==0)
                                {
                                    //Youll often see these chuncks of code where the player dies,this could have been done in a class much faster and efficeint but i alredy have over 8 classes 
                                    player.sethp(0);
                                    player.setSpacesuithp(0);
                                    double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                                    cout<<"You dont have enough money nor a wepon so you died while triyng to forefit"<<endl;
                                    cout<<"Game over you died"<<endl;
                                    cout<<endl;
                                    cout<<"Here is a summary of how you did:"<<endl;

                                    string filename="results.txt";
                                    ofstream fout;
                                    ios::app;

                                    fout.open(filename,ios::app);

                                    if(fout.is_open())
                                    {
                                        cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                        cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                        cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                        cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                        cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                        cout<<"Total Score: "<<score<<endl;
                                        fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                        fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                        fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                        fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                        fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                        fout<<"Total Score: "<<score<<endl;
                                        fout<<endl;

                                        if(score>=100)
                                        {
                                            cout<<"congratulations you got the highes obtaniable score"<<endl;
                                        }
                                        else
                                        {
                                            cout<<"Play again to see if you can do better!"<<endl;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"File with instructions not found"<<endl;
                                        break;
                                    }
                                    return 0;
                                }
                                else
                                {
                                    if(player.getmoney()<1000)
                                    {
                                        player.setmoney(0);
                                    }
                                    else
                                    {
                                        player.setmoney(player.getmoney()-10000);
                                    }
                                    cout<<"Really?! You chose to forfeit the battle? This is disappointing! Since you do not have a weapon, you just lost a huge chunk of money from your account. Hopefully, you git gud before you encounter the next alien."<<endl;
                                }
                            }
                        }
                        else if(secondChoice==1)// option for attacking 
                        {
                            if(player.getmoney()>=1000 && player.getWeponum()==0)// player has no wepon but dose have money 
                            {
                                cout<<"You do not have a weapon to fight! Lets visit the resource center and buy a weapon!"<<endl;
                                 do
                                {
                                    cout<<"1. Light Saber"<<endl;
                                    cout<<"2. Blaster"<<endl;
                                    cout<<"3. Beam Gun"<<endl;
                                    cout<<"4. Go back to menu"<<endl;
                                    cin>>secondChoice;

                                    if(secondChoice==1 && player.getWeponsAt(0)=="Light Saber" || player.getWeponsAt(1)=="Light Saber")
                                    {   
                                    cout<<"You alredy have a Ligt Saber,choose another wepon or exit"<<endl; 
                                    }
                                    else if(secondChoice==2 && player.getWeponsAt(0)=="Blaster" || player.getWeponsAt(1)=="Blaster")
                                    {
                                        cout<<"You alredy have a Blaster,choose another wepon or exit"<<endl;
                                    }
                                    else if(secondChoice==3 && player.getWeponsAt(0)=="Beam gun" || player.getWeponsAt(1)=="Beam gun")
                                    {
                                        cout<<"You alredy have a Beam gun,choose another wepon or exit"<<endl;
                                    }
                                    else if(secondChoice!=4)
                                    {
                                        cout<<"Hom many " <<Store.getweponstypeAt(secondChoice-1)<< "s would you like to buy"<<"("<<Store.getweponspriceAt(secondChoice-1)<<"$ each)"<<endl;

                                        do
                                        {
                                            cin>>amount;
                                            if(amount>player.getWeponum() || amount<1)
                                            {
                                                cout<<"You cannot have more than two weapons at the same time, re-enter a valid quantity."<<endl;
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
                                                    for(int i=0;i<amount;i++)
                                                    {
                                                        player.setweponsAt(i,Store.getweponstypeAt(secondChoice));
                                                    }
                                                    if(player.getmoney()-amount*Store.getweponspriceAt(secondChoice-1)<0)
                                                    {
                                                        cout<<"Insufficient funds please try again."<<endl;
                                                    }
                                                    else
                                                    {
                                                        player.setmoney(player.getmoney()-amount*Store.getweponspriceAt(secondChoice-1));
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
                                        }while(amount>player.getWeponum() || amount<1);
                                    }
                                }while(secondChoice!=4);
                            }
                            else if(player.getmoney()<1000 && player.getWeponum()==0) // player has no money or wepon so he automatically dies 
                            {
                                player.sethp(0);
                                player.setSpacesuithp(0);
                                double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                                cout<<"You neither have a weapon nor enough money to buy a weapon. Consequently, the alien attacked and defeated you. You could not retreat :("<<endl;
                                cout<<"You have died due to health loss. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space."<<endl;
                                cout<<"Game Over"<<endl;
                                cout<<endl;
                                cout<<"Here is a summary of how you did:"<<endl;

                                string filename="results.txt";
                                ofstream fout;
                                ios::app;

                                fout.open(filename,ios::app); // builds results and stores them in file 

                                if(fout.is_open())
                                {
                                
                                    cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                    cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                    cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                    cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                    cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                    cout<<"Total Score: "<<score<<endl;
                                    fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                    fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                    fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                    fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                    fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                    fout<<"Total Score: "<<score<<endl;
                                    fout<<endl;

                                    if(score>=100)
                                    {
                                        cout<<"congratulations you got the highes obtaniable score"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Play again to see if you can do better!"<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"File with instructions not found"<<endl;
                                    break;
                                }
                                return 0;
                            }
                                a=1;
                                cout<<"Let's attack! Choose a weapon from your arsenal quickly and attack before the enemy advances!"<<endl;
                                for(int i=0;i<2;i++)
                                {
                                    if(player.getWeponsAt(i)=="")
                                    {
                                       continue; 
                                    }
                                    else
                                    {
                                        cout<<a<<". "<<player.getWeponsAt(i)<<endl;
                                        a++;   
                                    }
                                }
                                cin>>secondChoice;
                                int wepontype=0;
                                int fighterPresent=0;
                                int r1=randomNumbers1(1,6);
                                int r2=randomNumbers1(1,6);
                                if(player.getWeponsAt(secondChoice-1)=="Light Saber")
                                {
                                    wepontype=1;
                                }
                                else if((player.getWeponsAt(secondChoice-1)=="Beam Gun"))
                                {
                                    wepontype=2;
                                }
                                else
                                {
                                    wepontype=3;
                                }

                                if(player.getcrewnameAt(0)=="Nerys Fighter")// takes care of fighter crew in players team 
                                {
                                    fighterPresent=1;
                                }

                                int BattleOutcome=(r1*wepontype)*(1+fighterPresent)-(r2*NewPlanet.getPlanetsExplored());//generates battle outcome 
                                if(BattleOutcome<=0) //looses battle 
                                {
                                    cout<<"Aggh! You lost the battle! "<<NewAlien.getAlienName()<<" seems to be hard for you! Tough times. Unfortunately, you experience the following due to this loss:"<<endl;
                                    player.setSpacesuithp(player.getspaceSuithp()-100*((100-20*player.getspaceSuit())/100));
                                    cout<<"1. Your health was decreased by 30%."<<endl;
                                    cout<<"2. 2. Your suit health decreased by 40%."<<endl;
                                    cout<<"3. You lost a";
                                    if(player.getWeponsAt(secondChoice-1)=="")
                                    {
                                        cout<<player.getWeponsAt(secondChoice)<<", the weapon you used for attacking the alien."<<endl;
                                        player.setweponsAt(secondChoice-1,"");
                                    }
                                    else
                                    {
                                        cout<<player.getWeponsAt(secondChoice-1)<<", the weapon you used for attacking the alien."<<endl;
                                        player.setweponsAt(secondChoice-1,"");  
                                    }   
                                    player.sethp(player.gethp()-100*0.3);

                                    if(player.gethp()<=60 && player.getmedicalkit()>0)
                                    {
                                        cout<<"Your health dropped under 60% so you used a medical kit to heal yourself"<<endl;
                                        player.sethp(100);
                                        player.setMedicalKit(player.getmedicalkit()-1);   
                                    }

                                    if(player.getWeponsAt(0)=="Lola Doctor" || player.getWeponsAt(1)=="Lola Doctor")// if we have lola as a team member we heal ourselves 5%
                                    {
                                        player.sethp(player.gethp()+100*0.05);
                                    }
                                    if(player.gethp()<=0 || player.getspaceSuithp()<=0)
                                    {
                                        player.sethp(0);
                                        player.setSpacesuithp(0);
                                        double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                                        cout<<"You have died due to health loss or your space suit broke. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space."<<endl;
                                        cout<<"Game over<<endl;"<<endl;
                                        cout<<endl;
                                        cout<<"Here is a summary of how you did:"<<endl;

                                        string filename="results.txt"; //result generation 
                                        ofstream fout;
                                        ios::app;

                                        fout.open(filename,ios::app);

                                        if(fout.is_open())
                                        {
                                            cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                            cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                            cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                            cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                            cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                            cout<<"Total Score: "<<score<<endl;
                                            fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                            fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                            fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                            fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                            fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                            fout<<"Total Score: "<<score<<endl;
                                            fout<<endl;

                                            if(score>=100)
                                            {
                                                cout<<"congratulations you got the highes obtaniable score"<<endl;
                                            }
                                            else
                                            {
                                                cout<<"Play again to see if you can do better!"<<endl;
                                            }
                                        }
                                        else
                                        {
                                            cout<<"File with instructions not found"<<endl;
                                            break;
                                        }
                                        return 0;    
                                    } 

                                }
                                else //wins battle 
                                {
                                    int gun=randomNumbers1(0,2);
                                    if(player.getWeponum()==1)
                                    {
                                        if(player.getWeponsAt(0)=="")
                                        {
                                            player.setweponsAt(0,Store.getweponstypeAt(gun));
                                        }
                                        else
                                        {
                                            player.setweponsAt(1,Store.getweponstypeAt(gun));
                                        }
                                       cout<<"You defeated "<<NewAlien.getAlienName()<<" Great Job! You won a "<<Store.getweponstypeAt(gun)<< ". But you lost 10% of space suit health while fighting." <<endl; 
                                    }
                                    else
                                    {
                                         cout<<"You defeated "<<NewAlien.getAlienName()<<" Great Job! You saw the enemy's weapon lying down but you cannot carry with you as you already have 2 weapons. Unfortunately, you lost 10% of space suit health while fighting." <<endl;  
                                    }
                                    player.setSpacesuithp(player.getspaceSuithp()-(100*0.1));
                                } 
                        }
                    }
                    else if(NewMap.getMisfortuneType()==2)//Water storm misfortune 
                    {
                        NewMap.revealMisfortune(NewMap.getPlayerRowPosition(),NewMap.getPlayerColPosition(),'*');
                        cout<<"You got rushed by a wether storm and lost 10% of your health and an adiitional "<<(50-10*player.getspaceSuit())<<"% of your space suit"<<endl;
                        player.sethp(player.gethp()-100*0.1);
                        player.setSpacesuithp(player.getspaceSuithp()-100*(50-10*player.getspaceSuit())/100);

                        if(player.gethp()<=60 && player.getmedicalkit()>0)
                        {
                            cout<<"Your health dropped under 60% so you used a medical kit to heal yourself"<<endl;
                            player.sethp(100);
                            player.setMedicalKit(player.getmedicalkit()-1);   
                        }

                        if(player.gethp()<=0 || player.getspaceSuithp()<=0)
                        {
                            double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                            player.sethp(0);
                            player.setSpacesuithp(0);
                            cout<<"You have died due to health loss or your space suit broke. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space."<<endl;
                            cout<<"Game Over"<<endl;
                            cout<<endl;
                            cout<<"Here is a summary of how you did:"<<endl;

                            string filename="results.txt";
                            ofstream fout;
                            ios::app;

                            fout.open(filename,ios::app);

                            if(fout.is_open())
                            {
                                cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                cout<<"Total Score: "<<score<<endl;
                                fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                fout<<"Total Score: "<<score<<endl;
                                fout<<endl;

                                if(score>=100)
                                {
                                    cout<<"congratulations you got the highes obtaniable score"<<endl;
                                }
                                else
                                {
                                    cout<<"Play again to see if you can do better!"<<endl;
                                }
                            }
                            else
                            {
                                cout<<"File with instructions not found"<<endl;
                                break;
                            }
                            return 0;
                        } 
                    }
                    else if(NewMap.getMisfortuneType()==3)  // carter misffortune 
                    {

                        NewMap.revealMisfortune(NewMap.getPlayerRowPosition(),NewMap.getPlayerColPosition(),'o');
                        player.sethp(player.gethp()-100*0.5);
                        player.setSpacesuithp(player.getspaceSuithp()-100*((50-10*player.getspaceSuit())/100));
                        cout<<"You have fallen intro a crater, consecuentley you have lost 50% of your health and an additional "<<50-10*player.getspaceSuit()<<"% of your Space Suit"<<endl;

                        if(player.gethp()<=60 && player.getmedicalkit()>0)
                        {
                            cout<<"Your health dropped under 60% so you used a medical kit to heal yourself"<<endl;
                            player.sethp(100);
                            player.setMedicalKit(player.getmedicalkit()-1);   
                        }

                        if(player.gethp()<=0 || player.getspaceSuithp()<=0)
                        {
                            player.sethp(0);
                            player.setSpacesuithp(0);
                            double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                            cout<<"You have died due to health loss or your space suit broke. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space."<<endl;
                            cout<<"Game Over"<<endl;
                            cout<<endl;
                            cout<<"Here is a summary of how you did:"<<endl;

                            string filename="results.txt";
                            ofstream fout;
                            ios::app;

                            fout.open(filename,ios::app);

                            if(fout.is_open())
                            {
                                cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                cout<<"Total Score: "<<score<<endl;
                                fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                fout<<"Total Score: "<<score<<endl;
                                fout<<endl; 

                                if(score>=100)
                                {
                                    cout<<"congratulations you got the highes obtaniable score"<<endl;
                                }
                                else
                                {
                                    cout<<"Play again to see if you can do better!"<<endl;
                                }
                            }
                            else
                            {
                                cout<<"File with instructions not found"<<endl;
                                break;
                            }
                            return 0;
                        } 
                    }
                    else    // space sickness misfortune 
                    {
                        NewMap.revealMisfortune(NewMap.getPlayerRowPosition(),NewMap.getPlayerColPosition(),'*');
                        player.sethp(player.gethp()-100*0.3);
                        cout<<"Oh no! You have space sickness. Your health decreased by 30%"<<endl;

                        if(player.gethp()<=60 && player.getmedicalkit()>0)
                        {
                            cout<<"Your health dropped under 60% so you used a medical kit to heal yourself"<<endl;
                            player.sethp(100);
                            player.setMedicalKit(player.getmedicalkit()-1);   
                        }

                        if(player.gethp()<=0 || player.getspaceSuithp()<=0)
                        {
                            player.sethp(0);
                            player.setSpacesuithp(0);
                            double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                            cout<<"You have died due to health loss or your space suit broke. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space."<<endl;
                            cout<<"Game Over"<<endl;
                            cout<<endl;
                            cout<<"Here is a summary of how you did:"<<endl;

                            string filename="results.txt";
                            ofstream fout;
                            ios::app;

                            fout.open(filename,ios::app);

                            if(fout.is_open())
                            {
                                cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                cout<<"Total Score: "<<score<<endl;
                                fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                fout<<"Total Score: "<<score<<endl;
                                fout<<endl;

                                if(score>=100)
                                {
                                    cout<<"congratulations you got the highes obtaniable score"<<endl;
                                }
                                else
                                {
                                    cout<<"Play again to see if you can do better!"<<endl;
                                }
                            }
                            else
                            {
                                cout<<"File with instructions not found"<<endl;
                                break;
                            }
                            return 0;   
                        } 
                    }
                }
                else if(NewMap.isSiteLocation() && mapChoice!='m')// sites with question generation and trait assignment 
                {
                    string filename="Questions.txt"; // generates questions and awnsers 
                    ifstream fin;
                    string line;
                    string _arr[2];
                    string _arr1[4];
                    string _Question[86];
                    string _Awnsers[86][4];
                    int q=0;

                    fin.open(filename);

                    if(fin.is_open())
                    {
                        while(getline(fin,line))
                        {
                            split1(line,';',_arr,2);
                            _Question[q]=_arr[0];
                            split1(_arr[1],',',_arr1,4);
                            for(int i=0;i<4;i++)
                            {
                             _Awnsers[q][i]=_arr1[i]; 
                            }
                            
                            q++;
                            
                        }
                    }
                    else
                    {
                        cout<<"File with instructions not found"<<endl;
                        break;
                    }

                    temp=randomNumbers1(0,85);
                    cout<<_Question[temp]<<endl;

                    for(int i=0;i<4;i++)
                    {
                        int j=i+1;
                        cout<<j<<". "<<_Awnsers[temp][i]<<endl;
                    }

                    do
                    {
                        cin>>secondChoice;

                        if(secondChoice!=1)
                        {
                            cout<<"You have awnsered incorrectly you may not enter"<<endl;
                            cout<<" Reduced your health by 1% because of frustration."<<endl;
                            player.sethp(player.gethp()-100*0.01);

                            
                                if(player.gethp()<=0 || player.getspaceSuithp()<=0)
                                {
                                    player.sethp(0);
                                    player.setSpacesuithp(0);
                                    double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                                    cout<<"You have died due to health loss or your space suit broke. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space."<<endl;
                                    cout<<"Game Over"<<endl;
                                    cout<<endl;
                                    cout<<"Here is a summary of how you did:"<<endl;

                                    string filename="results.txt";
                                    ofstream fout;
                                    ios::app;

                                    fout.open(filename,ios::app);

                                    if(fout.is_open())
                                    {
                                        
                                        cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                        cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                        cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                        cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                        cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                        cout<<"Total Score: "<<score<<endl;
                                        fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                                        fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                                        fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                                        fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                                        fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                                        fout<<"Total Score: "<<score<<endl;
                                        fout<<endl; 

                                        if(score>=100)
                                        {
                                            cout<<"congratulations you got the highes obtaniable score"<<endl;
                                        }
                                        else
                                        {
                                            cout<<"Play again to see if you can do better!"<<endl;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"File with instructions not found"<<endl;
                                        break;
                                    }
                                    return 0;
                                }
                        }     
                    }while(secondChoice!=1);    // if correct awnser is given 
                    
                        cout<<"correct! here are the traits you found"<<endl;
                        int trait=NewMap.getSiteTrait();
                        cout<<trait<<endl;
                        if(trait==1)
                        {
                            cout<<"congratulations, you have found a clean water supply. This is a great sign. This discovery has been added to your log book."<<endl;
                            if(NewPlanet.gethabitabletratitsAt(0)!="Water" && NewPlanet.gethabitabletratitsAt(1)!="Water" && NewPlanet.gethabitabletratitsAt(2)!="Water")
                            {   
                                 
                                NewPlanet.sethabitabletraitAt(GoodTraitsFound,"Water");
                                GoodTraitsFound++;
                            }
                        }
                        else if(trait==2)
                        {
                            cout<<"congratulations, you have found oxigen in this planet. This is a great sign. This discovery has been added to your log book. "<<endl;
                            if(NewPlanet.gethabitabletratitsAt(0)!="Oxigen" && NewPlanet.gethabitabletratitsAt(1)!="Oxigen" && NewPlanet.gethabitabletratitsAt(2)!="Oxigen")
                            {
                                
                                NewPlanet.sethabitabletraitAt(GoodTraitsFound,"Oxigen");
                                GoodTraitsFound++;
                            }
                        }
                        else if(trait==3)
                        {
                            cout<<"congratulations ,you have found Fertile Soil. This is a great sign. This discovery has been added to your log book."<<endl;
                            if(NewPlanet.gethabitabletratitsAt(0)!="Fertile Soil" && NewPlanet.gethabitabletratitsAt(1)!="Fertile Soil" && NewPlanet.gethabitabletratitsAt(2)!="Fertile Soil")
                            {
                                
                                NewPlanet.sethabitabletraitAt(GoodTraitsFound,"Fertile Soil");
                                GoodTraitsFound++;
                            }
                        }
                        else if(trait==4)
                        {
                            cout<<"You have tun into a facility and noctie that the planet has a bad atmosphere. This is not a promising sign... This discovery has been added to your log book."<<endl;
                            if(NewPlanet.getnonhabitabletraitsAt(0)!="Bad atmosphere" && NewPlanet.getnonhabitabletraitsAt(1)!="Bad atmosphere" && NewPlanet.getnonhabitabletraitsAt(2)!="Bad atmosphere")
                            {
                                NewPlanet.setnonhabitabletraitAt(BadTraitsFound,"Bad atmosphere");
                                BadTraitsFound++;
                            }
                        }
                        else if(trait==5)
                        {
                            cout<<"Oh oh, you have run into a tocix gas resivoir. This is not a promising sign... This discovery has been added to your log book."<<endl;
                            if(NewPlanet.getnonhabitabletraitsAt(0)!="Toxic Gas" && NewPlanet.getnonhabitabletraitsAt(1)!="Toxic Gas" && NewPlanet.getnonhabitabletraitsAt(2)!="Toxic Gas")
                            {
                                NewPlanet.setnonhabitabletraitAt(BadTraitsFound,"Toxic Gas");
                                BadTraitsFound++;
                            }
                        }
                        else if (trait==6)
                        {
                            cout<<"After exploring for a while you start to notice the extreme temperature. This is not a promising sign... This discovery has been added to your log book."<<endl;
                            if(NewPlanet.getnonhabitabletraitsAt(0)!="Exterme Temperature" && NewPlanet.getnonhabitabletraitsAt(1)!="Exterme Temperature" && NewPlanet.getnonhabitabletraitsAt(2)!="Exterme Temperature")
                            {
                                NewPlanet.setnonhabitabletraitAt(BadTraitsFound,"Exterme Temperature");
                                BadTraitsFound++;
                            }
                        }
                }
                else if(NewMap.isNPCLocation() && mapChoice!='m')// friendly alien with rock paper scissors game and planet info 
                {
                    cout<<"You just ran into a friendly alien"<<endl;
                    if(player.gettranslator()==0)
                    {
                        cout<<"You do not have a translator and cannot communicate with this alien. This alien may have useful information for you or money to offer, you can purchase a translator from the store if you would like to talk to them."<<endl;
                        break;
                    }
                    else
                    {   
                        cout<<"You can communicate with this alien. You can defeat them in rock, paper, scissors three times and gain $200 (c) or you can ask them about the habitability of this planet (a). The chance of the alien telling the truth is 70%. You can only pick one option."<<endl;
                        do
                        {
                            cin>>UserChoice;
                            if(UserChoice!='a' && UserChoice!='c')
                            {
                                cout<<"invalid Option choose a or c"<<endl;
                            }
                        }while(UserChoice!='a' && UserChoice!='c');

                        if(UserChoice=='c')
                        {
                            do
                            {
                                temp=randomNumbers1(0,2);
                                if(temp==0)
                                {
                                    alienChoice='r';
                                }
                                else if(temp==1)
                                {
                                    alienChoice='p';
                                }
                                else
                                {
                                    alienChoice='s';
                                }
                                cout<<"Choose: rock(r), paper(p) or scissors(s)"<<endl;
                                cin>>UserChoice;
                                if(UserChoice!='r' && UserChoice!='p' && UserChoice!='s')
                                {
                                    cout<<"Invalid Choice, Try again."<<endl;
                                }
                                else if(UserChoice==alienChoice)
                                {
                                    if(alienChoice=='s')
                                    {
                                        cout<<"The Alien choose scissors"<<endl;
                                        cout<<"its a draw"<<endl;
                                    }
                                    else if(alienChoice=='p')
                                    {
                                        cout<<"The Alien choose paper"<<endl;
                                        cout<<"its a draw"<<endl;  
                                    }
                                    else
                                    {
                                        cout<<"The Alien choose rock"<<endl;
                                        cout<<"its a draw"<<endl;
                                    }
                                }
                                else
                                {
                                   if(alienChoice=='s')
                                    {
                                        cout<<"The Alien choose scissors"<<endl;
                                        if(UserChoice=='r')
                                        {
                                            cout<<"You win this round"<<endl;
                                            p++;
                                        }
                                        else
                                        {
                                            cout<<"You loose this round"<<endl;
                                            x++;
                                        }
                                    }
                                    else if(alienChoice=='p')
                                    {
                                        cout<<"The Alien choose paper"<<endl;
                                        if(UserChoice=='s')
                                        {
                                            cout<<"You win this round"<<endl;
                                            p++;
                                        }
                                        else
                                        {
                                            cout<<"You loose this round"<<endl;
                                            x++;
                                        }  
                                    }
                                    else
                                    {
                                        cout<<"The Alien choose rock"<<endl;
                                        if(UserChoice=='p')
                                        {
                                            cout<<"You win this round"<<endl;
                                            p++;
                                        }
                                        else
                                        {
                                            cout<<"You loose this round"<<endl;
                                            x++;
                                        }
                                    } 
                                }

                            }while(p!=2 && x!=2);// checks who won 2  games 

                            if(p==2)//wins 200 
                            {
                                cout<<"Congratulations! You defeated the alien and won $200"<<endl;
                                player.setmoney(player.getmoney()+200);
                            }
                            else
                            {
                                cout<<"You failed to deafeat the alien! You don't get any money or intel."<<endl;
                            }
                            p=0;
                            x=0;
                        }
                        else
                        {
                            string filename="alien_conversation.txt"; // generates conversation 
                            ifstream fin;
                            string line;
                            string _arr[2];
                            string _type[10];
                            int q=0;
                            int t=1;

                            fin.open(filename);

                            if(fin.is_open())
                            {
                                while(getline(fin,line))
                                {
                                    split1(line,',',_arr,2);
                                    _type[q]=_arr[1];
                                    q++;   
                                }
                            }
                            else
                            {
                                cout<<"File with instructions not found"<<endl;
                                break;
                            }

                            temp=randomNumbers1(1,10);
                            if(NewMap.isHabitable())
                            {
                                if(player.getcrewnameAt(0)=="Chuck Intimidator") // if chuck is present probabilities chnage 
                                {
                                    if(temp>2)
                                    {
                                        NewPlanet.setfriendlyAlien("habitable");
                                        cout<<"Hello human! I have looked around this planet and think this would make a great home for you."<<endl;
                                        cout<<"How would you like to respond"<<endl;
                                        for(int i=5;i<10;i++)
                                        {
                                            cout<<t<<". "<<_type[i]<<endl;
                                            t++;
                                        }
                                        do
                                        {
                                           cin>>secondChoice;
                                            if(secondChoice>=5 || secondChoice<0)
                                            {
                                                cout<<"Invalid input"<<endl;
                                            }
                                            else
                                            {
                                                cout<<_type[secondChoice+4]<<endl;   
                                            }
                                        }while(secondChoice>=5 || secondChoice<0);
                                    }
                                    else
                                    {
                                        NewPlanet.setfriendlyAlien("non-habitable");
                                        cout<<"Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else."<<endl;
                                        cout<<"How would you like to respond"<<endl;
                                        for(int i=0;i<5;i++)
                                        {
                                            cout<<t<<". "<<_type[i]<<endl;
                                            t++;
                                        }
                                        do
                                        {
                                            cin>>secondChoice;
                                            if(secondChoice>=5 || secondChoice<0)
                                            {
                                                cout<<"Invalid input"<<endl;
                                            }
                                            else
                                            {
                                                cout<<_type[secondChoice-1]<<endl;       
                                            }
                                        }while(secondChoice>=5 || secondChoice<0);
                                    }
                                }
                                else
                                {
                                    if(temp>3)
                                    {
                                        NewPlanet.setfriendlyAlien("habitable");
                                        cout<<"Hello human! I have looked around this planet and think this would make a great home for you."<<endl;
                                        cout<<"How would you like to respond"<<endl;
                                        for(int i=5;i<10;i++)
                                        {
                                            cout<<t<<". "<<_type[i]<<endl;
                                            t++;
                                        }
                                        do
                                        {
                                            cin>>secondChoice;
                                            if(secondChoice>=5 || secondChoice<0)
                                            {
                                                cout<<"Invalid input"<<endl;
                                            }
                                            else
                                            {
                                                cout<<_type[secondChoice+4]<<endl;   
                                            }
                                        }while(secondChoice>=5 || secondChoice<0);    
                                    }
                                    else
                                    {
                                        NewPlanet.setfriendlyAlien("non-habitable");
                                        cout<<"Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else."<<endl;
                                        cout<<"How would you like to respond"<<endl;
                                        for(int i=0;i<5;i++)
                                        {
                                            cout<<t<<". "<<_type[i]<<endl;
                                            t++;
                                        }
                                        do
                                        {
                                            cin>>secondChoice;
                                            if(secondChoice>=5 || secondChoice<0)
                                            {
                                                cout<<"Invalid input"<<endl;
                                            }
                                            else
                                            {
                                                cout<<_type[secondChoice-1]<<endl;       
                                            }
                                        }while(secondChoice>=5 || secondChoice<0);
                                    }
                                }
                            }
                            else
                            {
                                if(temp<=3)
                                {
                                    NewPlanet.setfriendlyAlien("habitable");
                                    cout<<"Hello human! I have looked around this planet and think this would make a great home for you."<<endl;
                                    cout<<"How would you like to respond"<<endl;
                                    for(int i=5;i<10;i++)
                                    {
                                        cout<<t<<". "<<_type[i]<<endl;
                                        t++;
                                    }
                                    do
                                    {
                                        cin>>secondChoice;
                                        if(secondChoice>=5 || secondChoice<0)
                                        {
                                            cout<<"Invalid input"<<endl;
                                        }
                                        else
                                        {
                                            cout<<_type[secondChoice+4]<<endl;   
                                        }
                                    }while(secondChoice>=5 || secondChoice<0);
                                }
                                else
                                {
                                    NewPlanet.setfriendlyAlien("non-habitable");
                                    cout<<"Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else."<<endl;
                                    cout<<"How would you like to respond"<<endl;
                                    for(int i=0;i<5;i++)
                                    {
                                        cout<<t<<". "<<_type[i]<<endl;
                                        t++;
                                    }
                                    do
                                    {
                                        cin>>secondChoice;
                                        if(secondChoice>5 || secondChoice<0)
                                        {
                                            cout<<"Invalid input"<<endl;
                                        }
                                        else
                                        {
                                            cout<<_type[secondChoice-1]<<endl;       
                                        }
                                    }while(secondChoice>5 || secondChoice<0);
                                }   
                            }
                        }
                    }
                }
                if(mapChoice!='m')
                {
                  player.setmoney(player.getmoney()+50);  
                }
            }while(mapChoice!='m');
        }
        else if(choice==2)//gets player status 
        {
            Status.getplayerStatus(player,Store,NewPlanet);
        }
        else if(choice==3)//get log book with its respectivepage number 
        {
            NewBook.getLogBook(page,player,NewPlanet);
        }
        else if(choice==4)// gets resource center to buy resources 
        {
            player=SpaceS.getSpacestore(player,Store,NewPlanet);
            cout<<"Great purchase, Elon is sending a Falcon rocket with your supplies to you right now."<<endl;
        }
        else if(choice==5)// reports planet and displays message of choice 
        {
            NewBook.getLogBook(page,player,NewPlanet);
            cout<<"Reporting this planet is irreversible. If the planet is in fact habitable, you will save "<<NewPlanet.getcarryngCapacity()<<" million people! If it's not, the people sent to this planet will die."<<endl;
            cout<<"Ready to report? [y/n]"<<endl;
            do
            {
                cin>>UserChoice;
                if(UserChoice!='y' && UserChoice!='n')
                {
                    cout<<"Invalid choice, try again"<<endl;
                }
                else if(UserChoice=='y')
                {
                    if(r!=0)
                    {
                        cout<<"You have alredy reported this planet, you cant report it again"<<endl;
                        break;
                    }
                    
                   if(NewMap.isHabitable())
                   {
                        player.setHumansSaved(NewPlanet.getcarryngCapacity()+player.getHumansSaved());
                        player.setHumansToSave(player.getHumansToSave()-NewPlanet.getcarryngCapacity());
                        NewPlanet.setaccuratePlanetsExplored(NewPlanet.getaccuratePlanetsExplored()+1);
                        if(player.getHumansToSave()<=0)
                        {
                            if(player.getHumansToSave()<0)
                            {
                                player.setHumansSaved(player.getHumansSaved()+player.getHumansToSave());
                            }
                            player.setHumansToSave(0);
                        }
                        else
                        {
                            cout<<"Congratulations! You have saved "<<NewPlanet.getcarryngCapacity()<<" million people! Planet"<<NewPlanet.getPlanetname()<<" is their new home. You have "<<player.getHumansToSave()<<" million people to save left."<<endl;
                        }  
                   }
                   else
                   {
                       player.setHumansKilled(NewPlanet.getcarryngCapacity()+player.getHumansKilled());
                       player.setHumansToSave(player.getHumansToSave()-NewPlanet.getcarryngCapacity());
                       NewPlanet.setinaccuratePlanetsExplored(NewPlanet.getinaccuratePlanetsExplored()+1);
                       if(player.getHumansToSave()<=0)
                        {
                            if(player.getHumansToSave()<0)
                            {
                                player.setHumansKilled(player.getHumansKilled()+player.getHumansToSave());
                            }
                            player.setHumansToSave(0);
                        }

                       cout<<"Your choice has led to tragedy. "<<NewPlanet.getcarryngCapacity()<<" million people were sent to planet "<<NewPlanet.getPlanetname()<<" and died due to its in-hospitable conditions. You still have "<<player.getHumansToSave()<<" million people left to save, so keep exploring."<<endl;
                   }

                   if(player.getHumansToSave()<=0)
                   {
                        double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                        cout<<"All of humanity has left Earth! Your mission is over."<<endl;
                        cout<<"Game Over"<<endl;
                        cout<<endl;
                        cout<<"Here is a summary of how you did:"<<endl;

                        string filename="results.txt";
                        ofstream fout;
                        ios::app;

                        fout.open(filename,ios::app);

                        if(fout.is_open())
                        {
                            cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                            cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                            cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                            cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                            cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                            cout<<"Total Score: "<<score<<endl;
                            fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                            fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                            fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                            fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                            fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                            fout<<"Total Score: "<<score<<endl;
                            fout<<endl;

                            if(score>=100)
                            {
                                cout<<"congratulations you got the highes obtaniable score"<<endl;
                            }
                            else
                            {
                                cout<<"Play again to see if you can do better!"<<endl;
                            }
                        }
                        else
                        {
                            cout<<"File with instructions not found"<<endl;
                            break;
                        }
                     return 0;
                   }
                r++;
                }
            }while(UserChoice!='y' && UserChoice!='n');
        }
        else if(choice==6)// enters wormhole to next planet , takes care of fuel and planet generation 
        {
            cout<<"Are you sure you want to enter this wormhole? You will start a new page in your log book and you will lose fuel."<<endl;
            cout<<"Enter wormhole? [y/n]"<<endl;

            do
            {
                cin>>UserChoice;
                if(UserChoice!='y' && UserChoice!='n')
                {
                    cout<<"Invalid choice , try again"<<endl;
                }
                else if(UserChoice=='y')
                {
                    for(int i=0;i<3;i++)
                    {
                        NewPlanet.sethabitabletraitAt(i,"");
                        NewPlanet.setnonhabitabletraitAt(i,"");
                    }
                    if(player.getfuel()<NewPlanet.getfuelneeded())
                    {
                        cout<<"You dont have enough fuel to get to the next planet try buying more in the resource center"<<endl;
                        cout<<"You need at least: "<<NewPlanet.getfuelneeded()<<" gallons of fuel"<<endl;
                        choice=1;
                    }
                    else
                    {
                        player.setfuel(player.getfuel()-NewPlanet.getfuelneeded());
                        NewPlanet.generatefuel();
                        NewMap.resetMap();
                        cout<<"Flying to next planet:"<<endl;
                        cout<<endl;
                    }
                }
                else
                {
                    choice==1;
                }

            }while(UserChoice!='y' && UserChoice!='n');
        }
        else if(choice==7)// give up option 
        {
            cout<<"Are you sure you want to give up? [y/n]"<<endl;
            do
            {
                cin>>UserChoice;
                if(UserChoice!='y' && UserChoice!='n')
                {
                    cout<<"invalid option try again."<<endl;
                }
                if(UserChoice=='y')
                {
                    double score=(((player.getHumansSaved()-player.getHumansKilled())/8000)*(NewPlanet.getaccuratePlanetsExplored()+(NewPlanet.getPlanetsExplored()-(NewPlanet.getinaccuratePlanetsExplored()+NewPlanet.getinaccuratePlanetsExplored())))/(NewPlanet.getPlanetsExplored()*100));
                    cout<<"It is disappointing to hear that you have quit, humanity was depending on you."<<endl;
                    cout<<"Game Over"<<endl;
                    cout<<endl;
                    cout<<"Here is a summary of how you did:"<<endl;

                    string filename="results.txt";
                    ofstream fout;
                    ios::app;

                    fout.open(filename,ios::app);

                    if(fout.is_open())
                    {
                        cout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                        cout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                        cout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                        cout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                        cout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                        cout<<"Total Score: "<<score<<endl;
                        fout<<"Planets explored: "<<NewPlanet.getPlanetsExplored()<<endl;
                        fout<<"Planets accuratley reported habitable: "<<NewPlanet.getaccuratePlanetsExplored()<<endl;
                        fout<<"Planets inaccuratley reported habitable: "<<NewPlanet.getinaccuratePlanetsExplored()<<endl;
                        fout<<"Humans saved (in millions): "<<player.getHumansSaved()<<endl;
                        fout<<"Humans perished (in millions): "<<player.getHumansKilled()<<endl;
                        fout<<"Total Score: "<<score<<endl;
                        fout<<endl;

                        if(score>=100)
                        {
                            cout<<"congratulations you got the highes obtaniable score"<<endl;
                        }
                        else
                        {
                            cout<<"Play again to see if you can do better!"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"File with instructions not found"<<endl;
                        break;
                    }
                    return 0;
                }
                else
                {
                    choice=1;
                }
            }while(UserChoice!='y' && UserChoice!='n');  
        }
    }while(choice!=6 && choice!=7);
}while(choice==6);
}