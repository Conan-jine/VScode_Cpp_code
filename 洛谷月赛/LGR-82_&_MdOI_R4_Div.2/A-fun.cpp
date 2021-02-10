#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,m,type;
    int sumQ=0,Ans=0;
    bool t[110]={0},q[110]={0};
    cin>>n>>m>>type;
    for(int i=0;i<n;i++)    cin>>t[i];
    for(int i=0;i<n;i++)    cin>>q[i];
    for(int i=0;i<n;i++)
    {
        if(t[i] && q[i])    sumQ++;
    }
    if(sumQ<m)  cout<<n<<endl;
    else    cout<<n-sumQ+m<<endl;
    return 0;
}