#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,m,temp=0;
    int sum=0,cnt=100000;
    char arr[52][52];
    int W[52]={0},B[52]={0},R[52]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!='W')  W[i]++;     // 注意不能用else if，各种情况是独立的
            if(arr[i][j]!='B') B[i]++;
            if(arr[i][j]!='R') R[i]++;
        }
    }
    sum+=W[0]+R[n-1];
    for(int i=1;i<n-1;i++)
    {
        for(int j=n-2;j>=i;j--)
        {
            temp=0;
            for(int k=1;k<i;k++)    temp+=W[k];
            for(int k=n-2;k>j;k--)  temp+=R[k];
            for(int k=i;k<=j;k++)   temp+=B[k];
            if(temp<cnt)    cnt=temp;
        }
    }
    cout<<sum+cnt<<endl;
    return 0;
}