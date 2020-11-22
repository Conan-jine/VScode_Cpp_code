#include <iostream>
#include <string>
using namespace std;

string arr1[8]={"000","001","010","011","100","101","110","111"};
string arr2[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

string _16to2(string str)
{
    string arr="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='A') arr+=arr2[int(str[i]-'A'+10)];
        else    arr+=arr2[int(str[i]-'0')];
    }
    return arr;
}

void _2to8(string str)
{
    int n=3,oldlen;
    while(n<str.size()) n+=3;
    oldlen=str.size();
    string temp;
    for(int i=0;i<n-oldlen;i++) str="0"+str;
    // cout<<str<<endl;
    for(int i=0;i<str.size();i+=3)
    {
        temp=str.substr(i,3);
        // cout<<"temp="<<temp<<endl;
        for(int j=0;j<8;j++)
        {
            if(temp==arr1[j])
            {
                if(!(i==0&&j==0))    cout<<j;
                break;
            }
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    string num;
    cin>>n;
    while(n--)
    {
        cin>>num;
        num=_16to2(num);
        // cout<<num<<endl;
        _2to8(num);
    }
}