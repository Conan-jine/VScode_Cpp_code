#include <iostream>
using namespace std;

int main()
{
    int M,S,T;
    int time=0,s1=0,s2=0;
    cin>>M>>S>>T;
    while(T--)
    {
        time++;
        s1+=17;
        if(M>9)
        {
            s2+=60;
            M-=10;
        }
        else    M+=4;
        if(s2>s1)   s1=s2;
        // cout<<time<<' '<<s1<<endl;
        if(s1>S)    break;
    }
    if(s1>=S)   cout<<"Yes"<<endl<<time<<endl;
    else    cout<<"No"<<endl<<s1<<endl;
    return 0;
}