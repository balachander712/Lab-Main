#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    char data[100];
    
    ofstream outfile;
    outfile.open("file.dat");

    cout<<"Writing into the file "<<endl;
    cout<<"Enter your name ";
    cin.getline(data,100);


    outfile << data << endl;

    cout<<"Enter your age "<<endl;
    cin>>data;
    cin.ignore();

    outfile << data << endl;

    outfile.close();

    ifstream infile;
    infile.open("file.dat");

    cout<<"Reading from the file "<<endl;
    infile >> data;

    cout << data <<endl;

    infile >> data;
    cout << data << endl;

    infile.close();


    return 0;
}