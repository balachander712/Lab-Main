#include <iostream>
#include <string>
using namespace std;

class Country
{
    string name;
    float area;
    float populationDensity;
    int population;

public:
    void read();
    void calculatePopulationDensity();
    void display();
    int getPopulation();
    float getArea();
    float getPopulationDensity();
};

int largestArea(Country *,int);
int largestPopulation(Country *,int);
int largestPopulationDensity(Country *,int);

int Country::getPopulation()
{
    return population;
}

float Country::getArea()
{
    return area;
}

float Country::getPopulationDensity()
{
    return populationDensity;
}
void Country::read()
{
    cout<<"Enter the name of the country ";
    cin>>name;
    cout<<"Enter the population of the country ";
    cin>>population;
    cout<<"Enter the area of the country ";
    cin>>area;
}

void Country::calculatePopulationDensity()
{
    populationDensity=population/area;
}
void Country::display()
{
    cout<<"The name of the country is "<<name<<endl;
    cout<<"The population of the country is "<<population<<endl;
    cout<<"The area of the country is "<<area<<endl;
    cout<<"The populaiton density of the country is "<<populationDensity;
}

int main()
{
    int num;
    cout<<"Enter the number of countries ";
    cin>>num;
    Country *C= new Country[num];

}
