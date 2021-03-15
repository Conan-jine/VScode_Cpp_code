#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int A,B,a,b;
    cin>>A>>B>>a>>b;
    int length,weight;
    length=A/(2*a);
    weight=B/(2*b);
    if(A%(2*a)>=a)   length++;
    if(B%(2*b)>=b)   weight++;
    cout<<length*weight<<endl;
    return 0;
}