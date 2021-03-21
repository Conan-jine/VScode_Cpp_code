#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void output(int num)
{
    if(num==0)  cout<<'0';
    else if(num<10)  cout<<'0';
    cout<<num;
}

int main()
{
    int n,H,M,D;
    char c;
    cin>>n;
    while(n--)
    {
        cin>>D>>H>>c>>M;
        if(D==1)
        {
            M+=H%2*60;
            cout<<D<<' ';
            output(H/2);
            cout<<":";
            output(M/2);
            cout<<endl;
        }
        else if(D>=2)
        {
            M+=H%2*60;
            H/=2;
            H+=12*(D-1);
            D=1;
            while(H>=24)
            {
                D++;
                H-=24;
            }
            cout<<D<<' ';
            output(H);
            cout<<":";
            output(M/2);
            cout<<endl;
        }
        else
        {
            cout<<D<<' ';
            output(H);
            cout<<":";
            output(M);
            cout<<endl;
        }
    }
    return 0;
}