#ifndef TOWNS_H
#define TOWNS_H
#include <string>

struct Town
{
    std::string name;
    int water;
    int electric;
    int internet;
    int waste;
    int travel;
    int sum;
    Town(){};
        Town(std::string nameOne, int waterOne,int electricOne, int internetOne,int wasteOne, int travelOne)
        {
            water=waterOne;
            name=nameOne;
            internet=internetOne;
            waste=wasteOne;
            travel=travelOne;
        }
};
class Towns
{
    public:
        Towns();
        virtual ~Towns();
        void addTown(std::string name, int water,int electric,int internet,int waste, int travel,int index);
        void recommend(int cost);
        void sumcosts();
        void displayCostSums();
        void findTown(std::string name);
        void printTownNames();
        void findrentCost(int roommates,int rent, std::string name);
        void removeArray();
        void deleteCity(std::string name);
        void Goodbye();
    protected:
    private:
    Town *townArray[6];
};

#endif // TOWNS_H
