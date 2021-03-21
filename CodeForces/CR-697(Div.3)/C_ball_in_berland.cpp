#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,a,b,k,sum=0;
    int boys[200002]={0};
    int girls[200002]={0};
    cin>>n;
    while(n--)
    {
        sum=0;
        cin>>a>>b>>k;
        for(int i=0;i<k;i++)    scanf("%d",&boys[i]);
        for(int i=0;i<k;i++)    scanf("%d",&girls[i]);
        for(int i=0;i<k-1;i++)
        {
            for(int j=i+1;j<k;j++)
            {
                if(boys[i]!=boys[j] && girls[i]!=girls[j])  sum++;
            }
        }
        printf("%d\n",sum);
    }
}