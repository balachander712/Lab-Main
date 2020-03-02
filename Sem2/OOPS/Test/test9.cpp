#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
public:
    char *str;
    int size;
    MyString()
    {
        str= new char[20];
    }
    void getInput();
    void display();
    bool operator==(MyString);
    MyString operator +(MyString);
    void operator =(MyString);
    MyString operator ++(int);
    MyString operator --(int);
};

void MyString::getInput()
{
    cout<<"Enter the size of the string ";
    cin>>size;
    str=new char[size];
    cout<<"Enter the string ";
    cin>>str;
}

void MyString::display()
{
    cout<<str;
}

MyString MyString::operator+(MyString S)
{
    MyString x;
    strcpy(x.str,this->str);
    strcat(x.str,S.str);
    x.size=this->size+S.size;
    return x;
} 

bool MyString::operator==(MyString S)
{
    if(strcmp(this->str,S.str))
        return false;
    else
        return true;
}

void MyString:: operator=(MyString S)
{
    strcpy(this->str,S.str);
    this->size=S.size;
}
int main()
{
    MyString s1,s2,s3;
    s1.getInput();
    s2.getInput();
    if(s1==s2)
    {
        cout<<"Strings are equal ";
    }
    else
    {
        cout<<"Strings are not equal ";
    }
    s3=s1+s2;
    s3.display();
    return 0;
}