#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct node
{
    int loc;
    int key;
    int absKey;
    int nextLoc;
}arr[100020];

bool vis[100020];
node ori[100020];
node Arr[100020];
node deleteArr[100020];
int len,deleLen;

int main()
{
    int a,n,firstLoc;
    cin>>firstLoc>>n;
    // if(n==0)    return 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cin>>arr[a].key>>arr[a].nextLoc;
        arr[a].absKey=abs(arr[a].key);
        arr[a].loc=a;
    }
    int k=0;
    while(firstLoc!=-1)
    {
        ori[k++]=arr[firstLoc];
        firstLoc=arr[firstLoc].nextLoc;
    }
    len=0,deleLen=0;
    for(int i=0;i<k;i++)
    {
        if(!vis[ori[i].absKey])
        {
            Arr[len++]=ori[i];
            vis[ori[i].absKey]=true;
        }
        else    deleteArr[deleLen++]=ori[i];
    }
    for(int i=0;i<len;i++)
    {
        if(i!=len-1)    printf("%05d %d %05d\n",Arr[i].loc,Arr[i].key,Arr[i+1].loc);
        else    printf("%05d %d -1\n",Arr[i].loc,Arr[i].key);
    }
    for(int i=0;i<deleLen;i++)
    {
        if(i!=deleLen-1)    printf("%05d %d %05d\n",deleteArr[i].loc,deleteArr[i].key,deleteArr[i+1].loc);
        else    printf("%05d %d -1\n",deleteArr[i].loc,deleteArr[i].key);
    }
    return 0;
}