#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char arr[2048][1024];
int n;

int main()
{
    cin>>n;
    int A=4,B=2;
    for(int i=0;i<2048;i++)
    {
        for(int j=0;j<1024;j++) arr[i][j]=' ';
    }
    arr[1][1]='/';
    arr[1][2]='_';
    arr[1][3]='_';
    arr[1][4]='\\';
    arr[2][2]='/';
    arr[2][3]='\\';
    for(int t=1;t<n;t++)
    {
        for(int i=1;i<=B;i++)
        {
            for(int j=1;j<=A;j++)
            {
                arr[i][j+A]=arr[i][j];
                arr[i+B][j+A/2]=arr[i][j];
            }
        }
        A*=2;
        B*=2;
    }
    for(int i=B;i>0;i--)
    {
        for(int j=1;j<=A;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}