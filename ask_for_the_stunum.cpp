#include <iostream>
using namespace std;

int arr[2000010];

int main()
{
    int n,m,num;
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<m;i++)
    {
        cin>>num;
        cout<<arr[num-1]<<endl;
    }
    return 0;
}