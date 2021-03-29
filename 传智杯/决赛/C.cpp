#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int T;
int n,m,cnt=0;

int cmpFind(string a, string b)
{
    int cnt=0,temp=0;
    for(int i=0;i<n;i++) a[i]=tolower(a[i]);
    for(int i=0;i<m;i++) b[i]=tolower(b[i]);
    for(int i=0;i<m-n+1;i++)
    {
        if(a[0]==b[i])
        {
            temp=0;
            for(int j=0;j<n;j++)
            {
                if(a[j]==b[i+j])    temp++;
                else    break;
            }
            if(temp==n)  cnt++;
        }
    }
    return cnt;
}

int main()
{
    // freopen("data.out","w",stdout);
    string arr1,arr2;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        cin>>arr1>>arr2;
        cnt=cmpFind(arr1,arr2);
        cout<<cnt<<endl;
    }
    return 0;
}