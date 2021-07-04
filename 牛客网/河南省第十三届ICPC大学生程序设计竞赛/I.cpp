#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int times;
char arr[10];

int main()
{
    int temp,cnt,now;
    bool no;
    cin>>times;
    while(times--)
    {
        for(int i=1;i<=8;i++)   cin>>arr[i];
        cnt=0;
        now=1;
        for(int i=1;i<=8;i++)
        {
            temp=(now+2)%8+1;
            if(arr[now]=='0' && arr[temp]=='1') cnt++;
            now=temp;
        }
        if(cnt==1 || cnt==0)  cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
    }
    return 0;
}