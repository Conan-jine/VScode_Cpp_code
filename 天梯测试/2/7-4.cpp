#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct my_arr
{
    bool handsome=true;
    bool ask=false;
}arr[100000];

void output(int num)
{
    int t=10000;
    while(num<t)
    {
        cout<<'0';
        t/=10;
    }
    if(num!=0)  cout<<num;
}

int main()
{
    // freopen("data.out","w",stdout);
    bool head=false;
    int n,k,temp;
    cin>>n;
    while(n--)
    {
        cin>>k;
        if(k==1)
        {
            cin>>temp;
            continue;
        }
        else
        {
            for(int i=0;i<k;i++)
            {
                cin>>temp;
                arr[temp].handsome=false;
            }
        }
    }
    cin>>n;
    while(n--)
    {
        cin>>temp;
        if(arr[temp].ask)   continue;
        else if(arr[temp].handsome)
        {
            arr[temp].ask=true;
            if(head)    cout<<' ';
            output(temp);
            head=true;
        }
    }
    if(!head)   cout<<"No one is handsome"<<endl;
    return 0;
}