#include <iostream>
using namespace std;

int main()
{
    int n,li,lj,row=0,col=0;
    int arr[111][111]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            arr[i][110]+=arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[110][i]+=arr[j][i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][110]%2==1)
        {
            row++;
            li=i;
        }
        if(arr[110][i]%2==1)
        {
            col++;
            lj=i;
        }
    }
    if(row==col && row==0)  cout<<"OK"<<endl;
    else if(row>1 || col>1) cout<<"Corrupt"<<endl;
    else if(row==col && row==1) cout<<li<<' '<<lj<<endl;
    return 0;
}