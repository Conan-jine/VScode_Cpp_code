#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char months[13][4]={"",
"JAN",
"FEB",
"MAR",
"APR",
"MAY",
"JUN",
"JUL",
"AUG",
"SEP",
"OCT",
"NOV",
"DEC"};
int month[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
// 0,31,28,31,30,31,30,31,31,30,31,30,31
int judge(char a,char b,char c)
{
    for(int i=1;i<13;i++)
    {
        if(months[i][0]==a&&months[i][1]==b&&months[i][2])  return i;
    }
    return 0;
}

int main()
{
    char xx,yy,zz;
    int d,m,y,all=0;
    cin>>d;
    cin>>xx>>yy>>zz;
    m=judge(xx,yy,zz);
    cin>>y;
    if(y<1582)
    {
        all+=(y-1)*365+(y-1)/4;
        all+=month[m];
        all+=d-1;
        if(y%4==0&&m>2)  all++;
    }
    else if(y==1582)
    {
        all+=1581*365+1581/4;
        all+=month[m];
        if((m==10&&d>14)||m>10) all-=10;
        all+=d-1;
    }
    else
    {
        all+=1581*365+1581/4+355;
        for(int i=1583;i<y;i++)
        {
            if( i%4==0 && (i%100!=0||i%400==0) )  all+=366;
            else all+=365;
        }
        all+=month[m];
        all+=d-1;
        if(y%4==0&&(y%100!=0||y%400==0)&&m>2)    all++;
    }
    cout<<all<<endl;
    return 0;
}