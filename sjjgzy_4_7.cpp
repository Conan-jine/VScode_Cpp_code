#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S="(xyz)+*";
    string T=S;
    T[2]=S[5];
    T[5]=S[6];
    T[6]=S[2];
    cout<<T<<endl;
}