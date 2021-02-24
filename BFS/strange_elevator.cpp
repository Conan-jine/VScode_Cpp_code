#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

struct node
{
    int loc;
    int times;
};

int n,a,b;
int arr[250];
bool visit[250];
queue<node> q;

int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    node x,begin={a,0};
    q.push(begin);
    while(q.size())
    {
        x=q.front();
        q.pop();
        if(x.loc==b)    break;
        if(x.loc+arr[x.loc]<=n && !visit[x.loc+arr[x.loc]])
        {
            q.push(node({x.loc+arr[x.loc],x.times+1}));
            visit[x.loc+arr[x.loc]]=true;
        }
        if(x.loc-arr[x.loc]>=1 && !visit[x.loc-arr[x.loc]])
        {
            q.push(node({x.loc-arr[x.loc],x.times+1}));
            visit[x.loc+arr[x.loc]]=true;
        }
    }
    if(x.loc==b)    cout<<x.times<<endl;
    else    cout<<-1<<endl;   
    return 0;
}