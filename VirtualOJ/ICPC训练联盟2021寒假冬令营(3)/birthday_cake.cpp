#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    bool judge=false;
    int n,arr[120][2]={0},cnt,num;
    while(cin>>n)
    {
        if(n==0)    break;
        judge=false;
        for(int i=0;i<2*n;i++)    cin>>arr[i][0]>>arr[i][1];
        for(int x=-500;x<=500;x++)
        {
            for(int y=-500;y<=500;y++)
            {
                if(x==0 && y==0)    continue;
                num=0;
                cnt=0;
                for(int i=0;i<2*n;i++)
                {
                    if(arr[i][0]*x+arr[i][1]*y>0)   cnt++;
                    else if(arr[i][0]*x+arr[i][1]*y<0)  num++;
                    else    break;
                }
                if(cnt==n && cnt==num)
                {
                    cout<<x<<' '<<y<<endl;
                    judge=true;
                    break;
                }
            }
            if(judge)   break;
        }
    }
    return 0;
}