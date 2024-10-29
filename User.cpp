#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Crewmates.h"
using namespace std;

int split(string inputString, char separator ,string arr[], int size)
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

User::User()
{
    _fuel=200000;
    _hp=100;
    _money=100000;
    
    _wepons[0]="Light Saber";
    _wepons[1]="";
    _SpaceSuit=1;
    _spaceSuithp=100;
    _translator=0;
    _medkit=0;
    _HumansKilled=0;
    _HumansSaved=0;
    _HumansToSave=8000;
    _spaceSuithp=100;

}

string User::getname()
{
    return _username;
}

int User::gethp()
{
    return _hp;
}

double User::getfuel()
{
    return _fuel;
}

int User::getmoney()
{
    return _money;
}

string User::getWeponsAt(int index)
{
    return _wepons[index];
}

int User::getWeponum()
{
    _weponAmount=0;
    if(getWeponsAt(0)!="")
    {
        _weponAmount++;
    }
    if(getWeponsAt(1)!="")
    {
       _weponAmount++; 
    }
return _weponAmount;
}

int User::getspaceSuit()
{
    return _SpaceSuit;
}

int User::getspaceSuithp()
{
    return _spaceSuithp;
}

int User::gettranslator()
{
    return _translator;
}

int User::getmedicalkit()
{
    return _medkit;
}

int User::getHumansSaved()
{
    return _HumansSaved;
}

int User::getHumansKilled()
{
    return _HumansKilled;
}

int User::getHumansToSave()
{
    return _HumansToSave;
}

int User::getcrewnumber()
{
  
if(_selectedcrew[0].getcrewname()=="") // assigns the value to the selected crew for the user
    {
      return _crewnumber;
    }
    else
    {
        return _crewnumber++;
    }
}

void User::readCrew(string filename) // reads the textfile containing the crew
{

    ifstream fin; //temproraray vriables that take track of each operation
    string line;
    string arr[_size];
    int a=0;
    int value=0;

    fin.open(filename);

    if(fin.is_open()) // always chechk if the file is open 
    {
        while(getline(fin,line))// conditions to fill the array as long as the array can still be filled 
        {
            value=split(line,';',arr,_size1);
            if(value!=0)
            {
                _fullcrew[a]=Crewmates(arr[0],arr[1]); // default constructor to make like easier
                a++;
            }
            else
            {
            continue;
            }
        }
    }
}  

void User::setselectedCrew(int index) // sorts into a smaller array the crew that we have 
{
    getcrewnumber();
    _selectedcrew[_crewnumber]=_fullcrew[index];
}

string User::getFullcrewNameAt(int index)
{
    return _fullcrew[index].getcrewname();
}

string User::getFullcrewAttributesAt(int index)
{
    return _fullcrew[index].getcrewattributes();
}

string User::getcrewnameAt(int index)
{
    return _selectedcrew[index].getcrewname();
}

string User::getcrewattributesAt(int index) // gets specific values of the crew 
{
    return _selectedcrew[index].getcrewattributes();
}

void User::setname(string username)
{
    _username=username;
}

void User::sethp(int hp)
{
    _hp=hp;
}

void User::setfuel(double fuel)
{
    _fuel=fuel;
}

void User::setmoney(int money)
{
    _money=money;
}

void User::setweponsAt(int index,string value)
{
    _wepons[index]=value;
}

void User::settranslator(int translator)
{
    _translator=translator;
}

void User::setMedicalKit(int medkit)
{
    _medkit=medkit;
}
void User::setSpacesuit(int spaceSuit)
{
    _SpaceSuit=spaceSuit;
}

void User::setSpacesuithp(int spaceSuithp)
{
    _spaceSuithp=spaceSuithp;
}

void User:: setHumansSaved(int HumansSaved)
{
    _HumansSaved=HumansSaved;
}

void User::setHumansKilled(int HumansKilled)
{
    _HumansKilled=HumansKilled;
}

void User::setHumansToSave(int HumansToSave)
{
    _HumansToSave=HumansToSave;
}
