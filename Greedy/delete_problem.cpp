#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string num;
    string::iterator it;
    cin>>num;
    int needSub,arr[256]={0},len=num.size();
    cin>>needSub;
    for(int i=0;i<num.size();i++)   arr[i]=num[i]-'0';
    while(needSub--)
    {
        // cout<<arr[loc]<<' '<<arr[loc+1]<<endl;
        for(int i=0;i<len;i++)
        {
            if(arr[i]>arr[i+1])
            {
                for(int j=i;j<len;j++)  arr[j]=arr[j+1];
                break;
            }
        }
        len--;
    }

    for(int i=0;i<len;i++)
    {
        if(arr[i]!=0)
        {
            for(int j=i;j<len;j++)  cout<<arr[j];
            return 0;
        }
        if(i==len-1)    cout<<0<<endl;
    }
    return 0;
}