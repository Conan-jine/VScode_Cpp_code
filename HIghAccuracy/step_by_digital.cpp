#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    bool judge=false;
    int len,n,a,sum=0;
    string num;
    int arr[4000];
    cin>>len;
    while(len--)
    {
        cin>>n>>a;
        sum=0;
        for(auto &i:arr)    i=0;
        num.assign("1");
        while(n!=0)
        {
            for(int i=0;i<num.size();i++)   arr[i]=(num[i]-'0')*n;
            for(int i=0;i<num.size();i++)
            {
                if(arr[i]==0) continue;
                else
                {
                    if(arr[i]>9 && i==num.size()-1)   num+='0';
                    arr[i+1]+=arr[i]/10;
                    arr[i]=arr[i]%10;
                    num[i]=arr[i]+'0';
                }
            }
            n--;
        }
        for(int i=0;i<num.size();i++)
        {
            if(num[i]-'0'==a)   sum++;
        }
        cout<<sum<<endl;
        1.84515154154;
    }
}