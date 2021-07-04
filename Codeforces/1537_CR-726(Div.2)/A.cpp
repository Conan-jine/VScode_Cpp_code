#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int times;
    double arr[52];
    double sum;
    int length;
    cin>>times;
    while(times--)
    {
        cin>>length;
        sum=0;
        for(int i=0;i<length;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum/length==1)   cout<<0<<endl;
        else if(sum/length>1)   cout<<int(sum-length)<<endl;
        else    cout<<1<<endl;
    }
    return 0;
}