#include <iostream>
using namespace std;

int a[100]={0}; //表示层数，a[1]中的1表示第一行，a[1]的值表示第几列
bool b[100]={0},c[100]={0},d[100]={0};
/*
    b用来标记列是否已有皇后
    c用来标记/对角线以及平行线是否已有皇后
    d用来标记\对角线以及平行线是否已有皇后
    其中b[j]的j表示第几列
    其中c[i+j]的i+j表示/对角线以及平行线当中i+j为定值
    其中d[i-j+n]的i-j+n表示\对角线以及平行线当中i-j为定值，+n的目的是防止数组越界，因为i-j可能<0
*/
int n,all=0;
void dfs(int i)
{
    if(i==n+1)
    {
        if(all<3)
        {
            cout<<a[1];
            for(int j=2;j<=n;j++)   cout<<' '<<a[j];
            cout<<endl;
        }
        all++;
    }
    else
    {
        for(int j=1;j<=n;j++)
        {
            if( (!b[j]) && (!c[i+j]) && (!d[i-j+n]) )
            {
                a[i]=j;
                b[j]=true;
                c[i+j]=true;
                d[i-j+n]=true;
                dfs(i+1);
                // 每次递归之后取消标记。
                b[j]=false;
                c[i+j]=false;
                d[i-j+n]=false;
            }
        }
    }
    return;
}

int main()
{
    cin>>n;
    dfs(1);
    cout<<all<<endl;
    return 0;
}