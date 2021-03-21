#include <iostream>
#include <deque>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;

deque<string> temp,my;

bool cmpString(string a, string b)
{
    int cnt=0;
    for(int i=0;i<a.size();i++)    if(a[i]!=b[i])  cnt++;
    if(cnt!=2)   return true;
    else    return false;
}

void addString(string a)
{
    deque<string>::iterator it;
    for(it=temp.begin();it!=temp.end();it++)
    {
        if(!cmpString(a,*it))   return;   
    }
    temp.push_back(a);
    return;
}

int main()
{
    string arr[520];
    int n,max=0;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        temp.clear();
        temp.push_back(arr[i]);
        for(int j=0;j<n;j++)
        {
            if(i==j)    continue;
            addString(arr[j]);
        }
        if(temp.size()>max)
        {
            max=temp.size();
            // my=temp;
        }
    }
    cout<<max<<endl;
    // for(deque<string>::iterator it=my.begin();it!=my.end();it++)    cout<<*it<<endl;
    return 0;
}