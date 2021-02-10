#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // freopen("data.out","w",stdout);
    string str;
    long long num,len,locNum;
    cin>>str>>num;
    len=str.size();
    locNum=len;
    while(num>len)
    {
        locNum=len;
        while(num>locNum)   locNum<<=1;
        locNum>>=1;
        if(num==locNum+1LL)    num=locNum;
        else    num=num-locNum-1LL;
    }
    cout<<str[num-1];
    return 0;
}