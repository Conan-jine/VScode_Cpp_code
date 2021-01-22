#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char c,e;
    string str;
    while(cin>>str)
    {
        c=str[0];
        e=str[str.size()-1];
        if(e=='.')  str.erase(str.end()-1);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            str.append("ay");
        }
        else
        {
            str+=c;
            str.erase(str.begin());
            str.append("ay");
        }
        cout<<str;
        if(e=='.')  cout<<'.';
        else    cout<<' ';
    }
}