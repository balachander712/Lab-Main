#include <iostream>
using namespace std;

class Number
{
    int intl_code;
    int std_code;
    int ph_no;
public:
    Number()
    {
        intl_code=0;
        std_code=0;
        ph_no=0;
    }
    phoneNo(const char *);
    friend ostream& operator<<(ostream&,const phoneNo&);
};

ostream& operator<<(ostream&,const phoneNo &
{
    
}

int main()
{
    char
    return 0;
}