#include <iostream>
#include <algorithm>
using namespace std;

char arr[12][12];
int times=0;
bool vis[12][12][12][12]={0};
bool vist[12][12][12][12]={0};

int main()
{
    int li,lj,pi,pj;
    int px=-1,py=0,lx=-1,ly=0;
    for(int i=0;i<12;i++)   arr[0][i]=arr[11][i]=arr[i][0]=arr[i][11]='*';
    for(int i=1;i<11;i++)
    {
        for(int j=1;j<11;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='F')
            {
                li=i;
                lj=j;
            }
            else if(arr[i][j]=='C')
            {
                pi=i;
                pj=j;
            }
        }
    }
    while(pi!=li||pj!=lj)
    {
        if(vis[li][lj][lx][ly] && vist[pi][pj][px][py] && times>100000 )
        {
            cout<<0<<endl;
            return 0;
        }
        vis[li][lj][lx][ly]=1;
        vist[pi][pj][px][py]=1;
        if(arr[px+pi][py+pj]=='*')
        {
            swap(px,py);
            if(px==0)   py=-py;
        }
        else
        {
            pi+=px;
            pj+=py;
        }
        if(arr[lx+li][ly+lj]=='*')
        {
            swap(lx,ly);
            if(lx==0)   ly=-ly;
        }
        else
        {
            li+=lx;
            lj+=ly;
        }
        times++;
    }
    cout<<times<<endl;
    return 0;
}