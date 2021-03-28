#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int n;
string str,arr[120];

int main()
{
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    cin>>n;
    getchar();
    getline(cin,str);
    int t=n;
    while(t<str.size()) t+=n;
    for(int i=0;i<t;i++)
    {
        if(i<str.size())    arr[i%n]+=str[i];
        else    arr[i%n]+=' ';
        
    }
    for(int j=0;j<n;j++)
    {   
        reverse(arr[j].begin(),arr[j].end());
        cout<<arr[j]<<endl;
    }
    return 0;
}