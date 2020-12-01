#include <iostream>
using namespace std;

int main()
{
    char c;
    int arr[100000],len=0,sum=0;;
    while(true)
    {
        sum=0;
        len=0;
        cout<<"Please type a series of numbers :(type 0 to end)"<<endl;
        while(true)
        {
            cin>>arr[len];
            if(arr[len]==0) break;
            len++;
        }
        for(int i=0;i<=len;i++)
        {
            sum=sum+arr[i];
        }
        cout<<"Sum = "<<sum<<endl<<endl;
        while(true)
        {
            cout<<"Calculate another sum? [Y/N] ";
            cin>>c;
            if(c=='Y')  break;
            else if(c=='N') return 0;
            else    continue;
        }
    }
    return 0;
}