#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string arr[5010];

void count(string &A, string &B, string &C)
{
    int alen=A.size(),blen=B.size();
    for(int i=0;i<alen;i++) C+=A[i]-'0'+B[i];
    for(int i=alen;i<blen;i++)  C+=B[i];
    for(int i=0;i<C.size();i++)
    {
        if(C[i]>'9')
        {
            if(i==C.size()-1)   C+='0';
            C[i+1]+=(C[i]-'0')/10;
            C[i]=(C[i]-'0')%10+'0';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    arr[0]="1";
    arr[1]="1";
    for(int i=2;i<=n;i++)   count(arr[i-2],arr[i-1],arr[i]);
    reverse(arr[n].begin(),arr[n].end());
    cout<<arr[n]<<endl;
    return 0;
}