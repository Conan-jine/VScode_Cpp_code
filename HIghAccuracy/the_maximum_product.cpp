#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int numl=0,num[200]={0};
    string str="1";
    int arrl=0,arr[4000]={0};
    int n,fixn=2;
    cin>>n;
    while(n>=fixn)
    {
        num[numl++]=fixn;
        n-=fixn;
        fixn++;
    }
    for(int i=numl-1;i>=0 && n>0;i--)
    {
        num[i]++;
        n--;
        if(n<1)    break;
        if(n!=0 && i==0)    i=numl;
    }
    for(int i=0;i<numl;i++) cout<<num[i]<<' ';
    cout<<endl;
    while(num[arrl])
    {
        for(int i=0;i<str.size();i++)   arr[i]=(str[i]-'0')*num[arrl];
        for(int i=0;i<str.size();i++)
        {
            if(arr[i]>9 && i==str.size()-1) str+='0';
            arr[i+1]+=arr[i]/10;
            arr[i]=arr[i]%10;
            str[i]=arr[i]+'0';
        }
        arrl++;
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}