#include "Towns.h"
#include <iostream>
#include <cmath>

using namespace std;
Towns::Towns()
{
    //ctor
}

Towns::~Towns()
{
    //dtor
}

void Towns::addTown(std::string name, int water,int electric,int internet,int waste, int travel,int index)
{
    Town *tmp=new Town(name,water,electric,internet,waste,travel);
    townArray[index]=tmp;
}

void Towns::printTownNames()
{
    for (int i=0;i<6;i++)
    {
        if (townArray[i]!=NULL)
        cout<<townArray[i]->name<<endl;
    }
}

void Towns::displayCostSums()
{
    for (int i=0;i<6;i++)
    {
        if (townArray[i]!=NULL)
        cout<<townArray[i]->name<<":"<<"$"<<townArray[i]->sum<<endl;
    }
}

void Towns::recommend(int cost)
{
    Town *tmp=townArray[0];
    for (int i=1;i<6;i++)
        if (abs(cost-townArray[i]->sum)<abs(cost-tmp->sum))
            tmp=townArray[i];
    cout<<"The best town with your budget based on utility costs is "<<tmp->name<<endl;
}

void Towns::sumcosts()
{
    for (int i=0;i<6;i++)
    {
        townArray[i]->sum=townArray[i]->waste+townArray[i]->water+townArray[i]->travel+townArray[i]->electric+townArray[i]->internet;
    }
}

void Towns::findTown(std::string name)
{
    static bool foundCheck=false;
    {
        for (int i=0;i<6;i++)
        {
            if (name==townArray[i]->name)
                cout<<"The average utility cost in "<<name<<" is $"<<townArray[i]->sum<<"."<<endl;
            foundCheck=true;
        }
        if (foundCheck==false)
            cout<<"Town not found."<<endl;
    }
}
void Towns::findrentCost(int roommates, int rent, std::string name)
{
    if (roommates==0)
        roommates=1;
    static bool foundCheckTwo=false;
    {
        for (int i=0;i<6;i++)
        {
            if (name==townArray[i]->name)
                cout<<"The projected monthly cost for "<<name<<" per person is $"<<(rent+(townArray[i]->sum)*roommates)/roommates<<endl;
            foundCheckTwo=true;
        }
        if (foundCheckTwo==false)
            cout<<"Town not found."<<endl;
    }
}
void Towns::removeArray()
{
    for (int i=0;i<6;i++)
    {
        cout<<"Deleting "<<townArray[i]->name<<endl;
        townArray[i]=NULL;
        delete townArray[i];
    }
}

void Towns::deleteCity(std::string name)
{
    static bool foundCheckthree=false;
    for (int i=0;i<6;i++)
    {
        if (townArray[i]->name==name)
        {
            cout<<"Deleting "<<name<<endl;
            townArray[i]=NULL;
            delete townArray[i];
            foundCheckthree=true;
        }
    }
        if (foundCheckthree==false)
        {
            cout<<"City not found."<<endl;
        }
}

void Towns::Goodbye()
    {
        cout<<"Thank you for using my program, goodbye!"<<endl;
        removeArray();
    }
