#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int A,B;
    int a=0,b=0;
    int n;
    int x1,x2,y1,y2;
    cin>>A>>B;
    cin>>n;
    while(n--)
    {
        cin>>x1>>x2>>y1>>y2;
        if(x1+y1==x2 && x1+y1==y2)  continue;
        if(x1+y1!=x2 && x1+y1!=y2)  continue;
        if(x1+y1==x2)   a++;
        if(x1+y1==y2)   b++;
        if(a>A)
        {
            cout<<'A'<<endl<<b<<endl;
            return 0;
        }
        if(b>B)
        {
            cout<<'B'<<endl<<a<<endl;
            return 0;
        }
        // cout<<a<<' '<<b<<endl;
    }
    return 0;
}