#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int my_div(int num, int x)
{
    int q=num>0 ? 1 : num;
    while(q*x<=num) q++;
    return num-(q-1)*x;
}

int main()
{
    // freopen("data.out","w",stdout);
    int arr[1010],num1,num2,maxNum=0,minNum=1000000000;
    int len=0;
    bool judge;
    while(1)
    {
        len=0;
        maxNum=0;
        minNum=1000000000;
        while(cin>>arr[len])
        {
            if(arr[len]==0) break;
            if(maxNum<arr[len]) maxNum=arr[len];
            if(minNum>arr[len]) minNum=arr[len];
            len++;
        }
        if(len==0)  break;
        for(int x=maxNum+abs(minNum);x!=0;x--)
        {
            judge=true;
            for(int i=1;i<len;i++)
            {
                // cout<<my_div(arr[i-1],x)<<' ';
                if(my_div(arr[i-1],x)==my_div(arr[i],x))    continue;
                else    judge=false;
                break;
            }
            // cout<<endl;
            if(judge)
            {
                cout<<x<<endl;
                break;
            }
        }
    }
    return 0;
}