#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

struct my_arr
{
    int sno;
    int h;
    int m;
    bool S;
    bool E;
}arr[1200];

int times,sumTime=0;
int n;

int main()
{
    // freopen("data.out","w",stdout);
    int lastH,lastM;
    int nowH,nowM;
    int num,lastSumTime,nowSumTime;
    cin>>n;
    lastSumTime=lastH=lastM=0;
    char c,STATE;
    while(n)
    {
        cin>>num>>STATE>>nowH>>c>>nowM;
        nowSumTime=nowH*60+nowM;
        if(num==0)
        {
            if(times==0)    cout<<0<<' '<<0<<endl;
            else cout<<times<<' '<<round(double(sumTime)/times)<<endl;
            times=0;
            sumTime=0;
            for(int i=0;i<1200;i++) arr[i].S=arr[i].E=false;
            n--;
        }
        if(STATE=='S')
        {
            arr[num].h=nowH;
            arr[num].m=nowM;
            arr[num].S=true;
        }
        if(STATE=='E' && arr[num].S==true)
        {
            times++;
            sumTime+=nowH*60+nowM-arr[num].h*60-arr[num].m;
            arr[num].S=false;
            arr[num].E=false;
        }
        lastSumTime=nowSumTime;
    }
    return 0;
}