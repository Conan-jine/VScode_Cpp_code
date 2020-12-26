#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    char c;
    double p,w,arr[1000]={0};
    double M,V,R,SUM=0,sum=0;
    int N;
    cin>>N;
    while(N--)
    {
        cin>>c;
        cin>>w;
        cin>>p;
        arr[int(c)]+=w;
        if(c!='R')  sum+=w/100*p;
        else if(c=='R')
        {
            if(w>200)   sum+=(w-200)/100*p;
        }
    }
    M=arr[int('M')];
    V=arr[int('V')];
    R=arr[int('R')];
    if(M/V<0.5 && R/(M+V+R)<0.5 && R/(M+V+R)>0.3)   sum*=0.9;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
    return 0;
}