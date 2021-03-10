#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string arr1,arr2;
int len,arr[51][50]={0};
int ori[50],rel[50];

void fun()
{
    for(int i=0;i<25;i++)
    {
        for(int j=49;j>25;j--)
        {
            arr[i][j-i]=ori[49-i]*ori[j];
        }
    }
    for(int i=0;i<50;i++)
    {
        rel[i]=0;
        for(int j=0;j<50;j++)
        {
            rel[i]+=arr[j][i];
        }
        rel[i]%=10;
    }
}


int main()
{
    // freopen("test.out","w",stdout);
    int m=0,cnt=0;
    bool judge=false;
    cin>>arr1;
    if(arr1=="2" || arr1=="3" || arr1=="7" || arr1=="8" || arr1.size()%2==0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    ori[50-arr1.size()/2-1]=1;
    cnt=pow(10,arr1.size()/2)-1;
    while(1)
    {
        cnt++;
        m=0;
        judge=false;
        for(int i=0;i<50;i++)   for(int j=0;j<50;j++)   arr[i][j]=0;
        fun();
        for(int i=0;i<50;i++)
        {
            rel[i]=0;
            for(int j=0;j<50;j++)
            {
                rel[i]+=arr[j][i];
            }
            rel[i]%=10;
        }
        arr2.assign("");
        for(int i=0;i<50;i++)
        {
            if(rel[i]!=0)   judge=true;
            if(judge==true)
            {
                for(int j=i;j<50;j++)   arr2+='0'+rel[j];
                // cout<<arr2<<endl;
                if(arr2==arr1)
                {
                    // for(int k=0;k<50;k++)
                    // {
                    //     if(ori[k]!=0)
                    //     {
                    //         for(int l=k;k<50;k++)   cout<<ori[l];
                    //         cout<<endl;
                    //         return 0;
                    //     }
                    // }
                    cout<<cnt<<endl;
                    return 0;
                }
                else    break;
            }
        }
        ori[49]++;
        while(ori[49-m]>9)
        {
            ori[49-m-1]+=1;
            ori[49-m]-=10;
            m++;
        }
    }
    // for(int i=0;i<50;i++)   cout<<rel[i];
    return 0;
}