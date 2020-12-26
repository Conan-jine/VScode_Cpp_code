#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a,string b)
{
    if(a.size()!=b.size())  return false;
    else
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])  return false;
        }
    }
    return true;
}

int main()
{
    int n;
    string cz,name1,name2;
    vector<string> arr;
    vector<string>::iterator it;
    cin>>n;
    while(n--)
    {
        cin>>cz;
        if(cmp(cz,"touch"))
        {
            cin>>name1;
            arr.push_back(name1);
        }
        else if(cmp(cz,"rename"))
        {
            cin>>name1>>name2;
            it=find(arr.begin(),arr.end(),name1);
            if(it!=arr.end())
            {
                *it=name2;
            }
        }
        else if(cmp(cz,"ls"))
        {
            for(it=arr.begin();it!=arr.end();it++)
            {
                cout<<*it<<endl;
            }
        }
        else if(cmp(cz,"rm"))
        {
            cin>>name1;
            it=find(arr.begin(),arr.end(),name1);
            if(it!=arr.end())   arr.erase(it);
        }
    }
    return 0;
}