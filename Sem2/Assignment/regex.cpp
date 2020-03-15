#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string str;
    while(true)
    {
        cin>>str;
        regex e("abc",regex_constants::icase);      // . any character except new line
        //regex e("abc?");                            // ? Zero or one preceding character
        //regex e("abc*");                            // * Zero or more preceding character
        //regex e("abc+");                            // +  one or more preceding character
        //regex e("ab[cd]*");                           //[....] Any character inside the square bracket
        //regex e("ab^[cd]*");                        
        //regex e("ab[cd]{3}");                           //,  or more preceding character
        //regex e("abc|de[fg]");
        //regex e("[[:w:]]+@[[:w:]]+\.com");             // [[:w:]] word character: digit,number or underscore


        //bool match=regex_match(str,e);
        bool match=regex_search(str,e);

        cout<<(match? "Matched" : "Not Matched")<<endl<<endl;
    }

    return 0;
}