#include <iostream>
using namespace std;

class Investment
{
    int init_value;
    int curr_value;
    int profit;
    int per_profit;
public:
    Investment();
    Investment(int,int);
    void setValues();
    void display();
};

Investment :: Investment()
{
    init_value=0;
    curr_value=0;
    profit=0;
    per_profit=0;
}

Investment :: Investment(int init_value,int curr_value)
{
    this->init_value=init_value;
    this->curr_value=curr_value;
}

void Investment::display()
{
    cout<<"The profit is "<<profit;
    cout<<"\nThe percentage profit is "<<per_profit;
}

void Investment::setValues()
{
    profit=curr_value-init_value;
    per_profit=profit/init_value;
}

class House
{
    string street_add;
    int sq_feet;
public:
    House();
    House(string,int);
    void display();
};

House :: House()
{
    street_add='/0';
    sq_feet=0;
}

House :: House(string street_add,int sq_feet)
{
    this->street_add=street_add;
    this->sq_feet=sq_feet;
}

void House::display()
{
    cout<<"The street address is "<<street_add<<endl;
    cout<<"The square feet is "<<sq_feet;
}

class HouseThatIsAnInvestment:public Investment,public House
{
    public:
    HouseThatIsAnInvestment()
    {
        cout<<"Constructor is called \n";
    }
    void display()
    {
        Investment::display();
        House::display();
    }
};


int main()
{
    Investment I(200,2000);
    House H("Coimbatore",1200);
    HouseThatIsAnInvestment B;
    B.display();
    return 0;
}