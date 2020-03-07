#include <iostream>
#include <string>
using namespace std;

class Ship
{
    char *str;
    char *year;
public:
    Ship();
    void getData();
    virtual void printData();
};

Ship:: Ship()
{
    str=new char[10];
    year=new char[4];
}


void Ship:: getData()
{
    cout<<"Enter the name of the ship ";
    cin.getline(str,sizeof(str));
    cout<<"Enter the year it was built ";
    cin>>year;
}

void Ship:: printData()
{
    cout<<"The name of the Ship is "<<str;
    cout<<"\n The ship was built in "<<year;
}

class CruiseShip:public Ship
{
    int pass_no;
public:
    CruiseShip()
    {
        pass_no=0;
    }
    void getData();
    void printData();
};

void CruiseShip::getData()
{
    cout<<"\nEnter the max number of passengers ";
    cin>>pass_no;
}

void CruiseShip::printData()
{
    cout<<"\nThe max number of passengers is "<<pass_no;
}

class CargoShip:public Ship
{
    int tonnage;
public:
    CargoShip()
    {
        tonnage=0;
    }
    void getData();
    void printData();
};

void CargoShip::getData()
{
    cout<<"\nEnter the maximum capacity in tonnes ";
    cin>>tonnage;
}

void CargoShip::printData()
{
    cout<<"The maximum capacity is "<<tonnage;
}

int main()
{
    Ship *ship;
    CruiseShip cruise;
    CargoShip cargo;
    
    ship=&cargo;
    ship->getData();
    ship->printData();
    cargo.getData();
    cargo.printData();
    return 0;
}