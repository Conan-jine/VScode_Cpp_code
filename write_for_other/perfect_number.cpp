#include <iostream>
using namespace std;

int main()
{
    int sum=0,cnt=0;
    cout<<"The perfect numbers between 1 and 500: "<<endl;
    for(int i=1;i<=500;i++)
    {
        sum=0;
        // 这里有一个小小的优化，j<=i 改成 j<=i/2,意在减少循环次数，且不影响最终的结果
        for(int j=1;j<=i/2;j++) 
        {
            if(i%j==0)  sum=sum+j;
        }
        if(i==sum)  cout<<'\t'<<i;
    }
    return 0;
}