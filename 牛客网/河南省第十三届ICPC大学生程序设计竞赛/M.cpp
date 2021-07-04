#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int n,m,k;
bool resist[100010];
int arr[100010][2];

int main()
{
    int cost=0;
    int temp,left,right;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)    cin>>arr[i][0]>>arr[i][1];
    for(int i=1;i<=k;i++)
    {
        cin>>temp;
        resist[temp]=true;
    }
    for(int i=0;i<m;i++)
    {
        left=arr[i][0];
        right=arr[i][1];
        while(!resist[left])    left--;
        while(!resist[right])   right++;
        cost+=right-left;
    }
    cout<<cost<<endl;
    return 0;
}