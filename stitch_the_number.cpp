#include <iostream>
#include <string>
using namespace std;        // not done.

bool fun(string a1,string a2)
{
    int len1=a1.length();
    int len2=a2.length();
    int samec=0;
    for(int i=0;i<len1&&len2;i++)
    {
        if(a1[i]<a2[i]) return false;
        else if(a1[i]==a2[i])   samec++;
    }
    if(samec==len1)
    {
        for(int i=0;i<len2-len1;i++)
        {
            if(a2[len1+i]>a1[i])    return false;
        }
    }
    return true;
}

int main()
{
    int n;
    string temp,arr[23];
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(!fun(arr[j],arr[j+1]))
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)    cout<<arr[i];
    return 0;
}