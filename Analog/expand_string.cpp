#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    char c;
    string str;
    string addstr;
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    cin>>str;
    for(int i=1;i<str.size();i++)
    {
        addstr.assign("");
        if(str[i]=='-' && isalpha(str[i+1]) && isalpha(str[i-1]) && str[i+1]-str[i-1]>0 && str[i+1]-str[i-1]<26)
        {
            c=str[i-1]+1;
            while(c<str[i+1])
            {
                for(int j=0;j<p2;j++)
                {
                    if(p1==1)   addstr+=tolower(c);
                    else if(p1==2)  addstr+=toupper(c);
                    else if(p1==3)  addstr+='*';
                }
                c++;
            }
            if(p3==2)   reverse(addstr.begin(),addstr.end());
            str.erase(str.begin()+i);
            str.insert(str.begin()+i,addstr.begin(),addstr.end());
        }
        else if(str[i]=='-' && isdigit(str[i+1]) && isdigit(str[i-1]) && str[i+1]-str[i-1]>0 && str[i+1]-str[i-1]<10)
        {
            c=str[i-1]+1;
            while(c<str[i+1])
            {
                for(int j=0;j<p2;j++)
                {
                    if(p1==3)   addstr+='*';
                    else    addstr+=c;
                }
                c++;
            }
            if(p3==2)   reverse(addstr.begin(),addstr.end());
            str.erase(str.begin()+i);
            str.insert(str.begin()+i,addstr.begin(),addstr.end());
        }
    }
    cout<<str<<endl;
    return 0;
}