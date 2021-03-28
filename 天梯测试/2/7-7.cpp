#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // freopen("data.out","w",stdout);
    char c;
    int G=0,P=0,L=0,T=0;
    while(cin>>c)
    {
        if(c=='G' || c=='g')    G++;
        else if(c=='P' || c=='p')   P++;
        else if(c=='L' || c=='l')   L++;
        else if(c=='T' || c=='t')   T++;
    }
    while(G>0 || P>0 || L>0 || T>0)
    {
        if(G>0)
        {
            cout<<'G';
            G--;
        }
        if(P>0)
        {
            cout<<'P';
            P--;
        }
        if(L>0)
        {
            cout<<'L';
            L--;
        }
        if(T>0)
        {
            cout<<'T';
            T--;
        }
    }
    return 0;
}