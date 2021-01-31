#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,m;
    unsigned long long sum1=0,sum2=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sum1+=i<j?i:j;
            sum2+=i*j;
        }
    }
    cout<<sum1<<' '<<sum2-sum1<<endl;
    return 0;
}