#include <iostream>
// Wrong Answer
using std::cin;
using std::cout;
using std::endl;

bool judge,onlyNeg,onlyC,onlyZero;
int n,m,c,s;
int arr[100020],temp[100020];
int negNum;

int main()
{
    freopen("data.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        c=-1;
        judge=onlyC=onlyNeg=onlyZero=false;
        cin>>n;
        for(int i=0;i<n;i++)    cin>>arr[i];
        for(int i=1;i<n;i++)    temp[i]=arr[i]-arr[i-1];
        for(int i=1;i<n;i++)
        {
            if(temp[i]==0)  onlyZero=true;
            if(temp[i]>0)
            {
                c=temp[i];
                onlyC=true;
                // onlyZero=false;
            }
            if(temp[i]<0)
            {
                m=arr[i-1]+c-arr[i];
                negNum=temp[i];
                onlyNeg=true;
                // onlyZero=false;
            }
            if(temp[i]>0 && c!=temp[i] || temp[i]<0 && negNum!=temp[i] || onlyZero && temp[i]!=0)
            {
                cout<<"-1"<<endl;
                judge=true;
                break;
            }
        }
        if(judge)   continue;
        
        if(onlyZero && !onlyC && !onlyNeg || onlyC && !onlyZero && !onlyNeg || onlyNeg && !onlyZero && !onlyC)  cout<<0<<endl;
        else if(arr[0]>=m)   cout<<"-1"<<endl;
        else    cout<<m<<' '<<c<<endl;
    }
    return 0;
}