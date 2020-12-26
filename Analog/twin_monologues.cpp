#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    int x=0,y=0,z=0;
    char c;
    cin>>c;
    string str;
    cin>>str;
    int arr[128]={0};
    char strs[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for(int i=int('1');i<=int('9');i++)   arr[i]=i-int('0');
    for(int i=int('A');i<=int('F');i++) arr[i]=i-int('A')+10;
    // for(int i=0;i<128;i++)  if(arr[i]!=0)   cout<<arr[i]<<' ';
    // cout<<endl;
    // cout<<"str="<<str<<endl;
    x+=arr[int(str[0])]*16+arr[int(str[1])];
    y+=arr[int(str[2])]*16+arr[int(str[3])];
    z+=arr[int(str[4])]*16+arr[int(str[5])];
    // cout<<"x="<<x<<' '<<"y="<<y<<' '<<"z="<<z<<endl;
    x=255-x;
    y=255-y;
    z=255-z;
    // cout<<"x="<<x<<' '<<"y="<<y<<' '<<"z="<<z<<endl;
    cout<<'#';
    cout<<strs[x/16]<<strs[x%16];
    cout<<strs[y/16]<<strs[y%16];
    cout<<strs[z/16]<<strs[z%16];
    return 0;
}