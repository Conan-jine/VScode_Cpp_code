#include <iostream>
#include <cmath>
// 未解
using std::cin;
using std::cout;
using std::endl;

long long x,y,len,k;

void sv(int x, int y, int a, int b, int len)
{
    if(len==1)  return;
    if(x-a <= len/2-1 && y-b <= len/2-1)
    {
        cout<<a+len/2<<' '<<b+len/2<<' '<<1<<endl;
        sv(x,y,a,b,len/2);
        sv(a+len/2-1,b+len/2,a,b+len/2,len/2);
        sv(a+len/2,b+len/2-1,a+len/2,b,len/2);
        sv(a+len/2,b+len/2,a+len/2,b+len/2,len/2);
    }
    else if(x-a <= len/2-1 && y-b > len/2-1)
    {
        cout<<a+len/2<<' '<<b+len/2-1<<' '<<2<<endl;
        sv(a+len/2-1,b+len/2-1,a,b,len/2);
        sv(x,y,a,b+len/2,len/2);
        sv(a+len/2,b+len/2-1,a+len/2,b,len/2);
        sv(a+len/2,b+len/2,a+len/2,b+len/2,len/2);
    }
    else if(x-a > len/2-1 && y-b <= len/2-1)
    {
        cout<<a+len/2-1<<' '<<b+len/2<<' '<<3<<endl;
        sv(a+len/2-1,b+len/2-1,a,b,len/2);
        sv(a+len/2-1,b+len/2,a,b+len/2,len/2);
        sv(x,y,a+len/2,b,len/2);
        sv(a+len/2,b+len/2,a+len/2,b+len/2,len/2);
    }
    else
    {
        cout<<a+len/2-1<<' '<<b+len/2-1<<' '<<4<<endl;
        sv(a+len/2-1,b+len/2-1,a,b,len/2);
        sv(a+len/2-1,b+len/2,a,b+len/2,len/2);
        sv(a+len/2,b+len/2-1,a+len/2,b,len/2);
        sv(x,y,a+len/2,b+len/2,len/2);
    }
}

int main()
{
    cin>>k>>x>>y;
    len=pow(2,k);
    sv(x,y,1,1,len);
    return 0;
}