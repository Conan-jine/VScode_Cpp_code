#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::__gcd;

int main()
{
    int times;
    int Alen,Blen,Clen,minNum,maxNum,temp;
    int AMinNum,BMinNum;
    bool judge=false;
    cin>>times;
    while(times--)
    {
        cin>>Alen>>Blen>>Clen;
        AMinNum=pow(10,Alen-1);
        BMinNum=pow(10,Blen-1);
        ( Alen>Blen ? AMinNum:BMinNum) += pow(10,Clen-1);
        cout<<AMinNum<<' '<<BMinNum<<endl;
    }
    return 0;
}