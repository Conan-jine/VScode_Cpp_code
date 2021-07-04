#include <iostream>

using std::min;
using std::cin;
using std::cout;
using std::endl;

int n;
char arr[1000010];

int main()
{
    int cost=0;
    char minc='Z';
    cin>>n;
    cin>>arr;
    if(arr[1]<arr[0])
    {
        cost++;
        arr[0]=arr[1];
    }
    for(int i=2;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            if(arr[i]<arr[i-2]) arr[i]=arr[i-1];
            else    arr[i-1]=arr[i];
            cost++;
        }
    }
    cout<<cost<<endl;
    return 0;
}