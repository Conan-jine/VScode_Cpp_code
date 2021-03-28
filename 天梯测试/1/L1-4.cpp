#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int i=1;
    string A,B,T;
    while(cin>>T)
    {
        if(T==".")  break;
        if(i==2)    A=T;
        if(i==14)   B=T;
        i++;
    }
    if(i>14)   cout<<A<<" and "<<B<<" are inviting you to dinner..."<<endl;
    else if(i>2)   cout<<A<<" is the only one for you..."<<endl;
    else    cout<<"Momo... No one is for you ..."<<endl;
    return 0;
}