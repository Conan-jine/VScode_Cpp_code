#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int score[120]={0},ans[120]={0},cnt=0;
    int n,m,temp;
    cin>>n>>m;
    for(int i=0;i<m;i++)    cin>>score[i];
    for(int i=0;i<m;i++)    cin>>ans[i];
    for(int i=0;i<n;i++)
    {
        cnt=0;
        for(int j=0;j<m;j++)
        {
            cin>>temp;
            if(temp==ans[j])    cnt+=score[j];
        }
        cout<<cnt<<endl;
    }
    return 0;
}