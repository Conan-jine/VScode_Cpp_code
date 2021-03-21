#include <iostream>
#include <queue>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;

int find11(string arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]=='1' && arr[i+1]=='1')    return i;
    }
    return -1;
}

bool find00(string arr, int loc)
{
    for(int i=loc;i<arr.size()-1;i++)
    {
        if(arr[i]=='0' && arr[i+1]=='0')    return true;
    }
    return false;
}

int main()
{
    // freopen("data.out","w",stdout);
    int t;
    bool judge=false;
    string arr;
    cin>>t;
    while(t--)
    {
        arr.assign("");
        cin>>arr;
        judge=false;
        if(arr.find('0')==string::npos || arr.find('1')==string::npos)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(find11(arr)!=-1)
        {
            if(find00(arr,find11(arr)))
            {
                cout<<"NO"<<endl;
                continue;
            }
        }
        cout<<"YES"<<endl;
    }    
    return 0;
}