#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct my_arr
{
    int up=0;
    int down=0;
}server1,server2;

int main()
{
    int times,n,temp;
    cin>>times;
    while(times--)
    {
        cin>>n;
        while(n--)
        {
            cin>>temp;
            if(temp==1 || temp==3)  server1.up++;
            else    server2.down++;
        }
        cout<<server1.up<<endl;
        server1.up=server2.down=0;
    }
    return 0;
}