#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int a,b;
    cin>>a>>b;
    string num=std::to_string(a*b);
    std::reverse(num.begin(),num.end());
    int len=num.size();
    int i=0;
    while(num[i]=='0')  i++;
    for(;i<len;i++) cout<<num[i];
    return 0;
}