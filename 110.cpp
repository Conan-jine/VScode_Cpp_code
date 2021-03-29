#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int people[4][52]={0};
    int len[4];
    int n,m,temp;
    int lastPeo,nowPeo,needNum,num;
    bool judge;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        people[1][temp]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        people[2][temp]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        people[3][temp]++;
    }
    lastPeo=0;
    nowPeo=1;
    needNum=1;
    num=0;
    for(int i=1;i<4;i++)    len[i]=n;
    while(len[1] && len[2] && len[3])
    {
        if(lastPeo==nowPeo)
        {
            needNum=1;
            num=0;
        }
        judge=false;
        for(int cost=needNum;cost<=n;cost++)
        {
            for(int i=1;i<=m;i++)
            {
                if(cost==needNum)
                {
                    if(people[nowPeo][i]>=cost && i>num)
                    {
                        people[nowPeo][i]-=cost;
                        len[nowPeo]-=cost;
                        judge=true;
                        num=i;
                    }
                }
                else
                {
                    if(people[nowPeo][i]>=cost)
                    {
                        people[nowPeo][i]-=cost;
                        len[nowPeo]-=cost;
                        judge=true;
                        num=i;
                        needNum=cost;
                    }
                }
                if(judge)   break;
            }
            if(judge)   break;
        }
        if(judge)   lastPeo=nowPeo;
        nowPeo++;
        while(nowPeo>3) nowPeo-=3;
    }
    cout<<nowPeo-1<<endl;
    return 0;
}