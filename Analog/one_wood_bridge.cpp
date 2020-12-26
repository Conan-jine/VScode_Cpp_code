#include <iostream>
using namespace std;

int main()
{
    int maxnum=0,minnum=0;
    int x,y,temp;
    int len,num;
    cin>>len>>num;
    while(num--)
    {
        cin>>x;
        y=len-x+1;
        if(x<y) swap(x,y);
        if(x>maxnum)    maxnum=x;
        if(y>minnum)    minnum=y;
    }
    cout<<minnum<<' '<<maxnum<<endl;
    return 0;
}