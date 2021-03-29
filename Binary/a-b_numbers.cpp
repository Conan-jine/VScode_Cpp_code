#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;

map<int, int> arr;
int num[200050];
long long n,key,cnt=0;

int main()
{
    cin>>n>>key;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        arr[num[i]]++;
    }
    for(int i=0;i<n;i++)    cnt+=arr[num[i]+key];
    cout<<cnt<<endl;
    return 0;
}