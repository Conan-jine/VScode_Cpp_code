#include <iostream>
#include <string>
using namespace std;

int main()
{
    int times=0;
    string str1,str2;
    cin>>str1>>str2;
    bool arr1[1100]={0},arr2[1100]={0};
    for(int i=0;i<str1.size();i++)
    {
        if(str1[i]=='*')    arr1[i]=true;
        else    arr1[i]=false;
        if(str2[i]=='*')    arr2[i]=true;
        else    arr2[i]=false;
    }
    for(int i=0;i<str1.size()-1;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            arr1[i]=!arr1[i];
            arr1[i+1]=!arr1[i+1];
            times++;
        }
    }
    cout<<times<<endl;
    return 0;
}