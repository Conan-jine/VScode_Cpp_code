#include <iostream>
#include <string>

int main()
{
    int n,x,y,i=3;
    int target[3][4];
    int now[3][3];
    int sum=0,num=0;
    std::string name1,name2;
    while(i--)
    {
        std::cin>>name1>>name2;
        if(name1=="sy") x=0;
        else if(name1=="wzh")   x=1;
        else if(name1=="cyw")   x=2;
        if(name2=="sy") y=0;
        else if(name2=="wzh")   y=1;
        else if(name2=="cyw")   y=2;
        target[x][0]=y;
        std::cin>>target[x][1]>>target[x][2]>>target[x][3];
        std::cin>>now[x][0]>>now[x][1]>>now[x][2];
    }
    std::cin>>n;
    for(int i=0;i<3;i++)
    {
        sum=0;
        if(i==target[i][0])
        {
            if(now[i][0]<target[i][1]) sum+=25;
        }
        else if(now[i][0]<now[target[i][0]][0]) sum+=25;
        if(now[i][0]<target[i][1]) sum+=25;
        if(now[i][1]>target[i][2]) sum+=25;
        if(now[i][2]>target[i][3]) sum+=25;
        if(sum>=n && sum!=0)  num++;
    }
    if(n==0)    std::cout<<3<<std::endl;
    else    std::cout<<num<<std::endl;
    return 0;
}