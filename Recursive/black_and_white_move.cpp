#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string white="",black="",sum="";
string arr[5]=
{
    "ooo--***o*",
    "ooo*o**--*",
    "o--*o**oo*",
    "o*o*o*--o*",
    "--o*o*o*o*",
};
int n;

void output(bool choice)
{
    if(choice)
    {
        sum+="o*";
        white.pop_back();
        black.pop_back();
    }
    cout<<white;
    if(choice)  cout<<"--";
    cout<<black;
    if(!choice) cout<<"--";
    cout<<sum<<endl;
}

int main()
{
    bool c=false;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        white.push_back('o');
        black.push_back('*');
    }
    for(int i=0;i<2*n-7;i++)
    {
        output(c);
        c=!c;
    }
    for(int i=0;i<5;i++)   cout<<arr[i]<<sum<<endl;
    return 0;
}