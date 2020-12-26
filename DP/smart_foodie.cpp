#include <iostream>
using namespace std;

int n,MAX=0;
int arr[1010]={0};
int len[1010]={0};

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        len[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>=arr[j])  len[i]=len[i]>len[j]+1?len[i]:len[j]+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(len[i]>MAX)  MAX=len[i];
    }
    cout<<MAX<<endl;
    return 0;
}