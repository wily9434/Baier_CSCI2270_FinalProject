#include <iostream>
#include "Towns.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream inFile;
    int choice=0;
    int waterCost;
    int electricCost;
    int internetCost;
    int wasteCost;
    int travelCost;
    int budget;
    int index=0;
    string TownName;
    string data;
    string pieceofData;
    Towns Boulderarea;
    inFile.open("HousingCosts.txt");
    if (inFile.good())
    {
        getline(inFile,data);
        while (getline(inFile,data))
        {
            stringstream newStringStream(data);
            getline(newStringStream,pieceofData,',');
            TownName=pieceofData;
            getline(newStringStream,pieceofData,',');
            istringstream(pieceofData)>>waterCost;
            getline(newStringStream,pieceofData,',');
            istringstream(pieceofData)>>electricCost;
            getline(newStringStream,pieceofData,',');
            istringstream(pieceofData)>>internetCost;
            getline(newStringStream,pieceofData,',');
            istringstream(pieceofData)>>wasteCost;
            getline(newStringStream,pieceofData,',');
            istringstream(pieceofData)>>travelCost;
            Boulderarea.addTown(TownName,waterCost,electricCost,internetCost,wasteCost,travelCost,index);
            index++;
        }
    }
    Boulderarea.sumcosts();
    while (choice !=7)
    {
        cout<<"Welcome to the Boulder Area utility price comparison tool!"<<endl;
        cout<<"1. Recommend a town based on budget."<<endl;
        cout<<"2. Print the names of the towns."<<endl;
        cout<<"3. Display the utility costs of each town for one person."<<endl;
        cout<<"4. Find a town and its average monthly utility cost for one person."<<endl;
        cout<<"5. Find the estimated price given rent and roommates."<<endl;
        cout<<"6. Remove a city from the list."<<endl;
        cout<<"7. Quit."<<endl;
        cin>>choice;
        if (choice==2)
        {
            Boulderarea.printTownNames();
        }
        else if (choice==3)
        {
            Boulderarea.displayCostSums();
        }
        else if (choice==1)
        {
            cout<<"Please enter your utility budget"<<endl;
            cin>>budget;
            Boulderarea.recommend(budget);
        }
        else if (choice==4)
        {
                string name;
            cout<<"Please enter the town name"<<endl;
             cin>>name;
             Boulderarea.findTown(name);
        }
        else if (choice==5)
        {
            string name;
            int rent;
            int roommates;
            cout<<"Please enter the town name."<<endl;
             cin>>name;
            cout<<"Please enter the number of roommates, including yourself."<<endl;
            cin>>roommates;
            cout<<"Please enter the projected rent."<<endl;
            cin>>rent;
            Boulderarea.findrentCost(roommates,rent,name);
        }
        else if (choice==6)
        {
            string name;
            cout<<"Please enter the town name."<<endl;
            cin>>name;
            Boulderarea.deleteCity(name);
        }
        else if (choice==7)
        {
            Boulderarea.Goodbye();
                    }
    }
    return 0;
}
