#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int tws(int num, int c);
int main()
{
    for(int i=2992;i<10000;i++)
    {
        if(tws(i,10)==tws(i,12) && tws(i,16)==tws(i,12))
            cout<<i<<endl;
    }
}

int tws(int num, int c)
{
    int sum=0,i=4;
    while(i--)
    {
        sum+=num%c;
        num/=c;
    }
    return sum;
}