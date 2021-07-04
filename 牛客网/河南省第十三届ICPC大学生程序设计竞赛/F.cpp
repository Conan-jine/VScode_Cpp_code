#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n,m;
char arr[1010][1010];

int main()
{
    cin>>n>>m;
    int hang,lie,disx,disy;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='#')
            {
                hang=i;
                lie=j;
            }
        }
    }
    // 从行得列
    for(int i=1;i<=n;i++)   if(arr[i][lie]=='*')  disy=i-hang;  
    // 从列得行
    for(int j=1;j<=m;j++)   if(arr[hang][j]=='*')   disx=lie-j;

    cout<<disx<<' '<<disy<<endl;
    return 0;
}
/*
10 10
........*.
........*.
........*.
........*.
........*.
........*.
........*.
**********
....#...*.
........*.
*/