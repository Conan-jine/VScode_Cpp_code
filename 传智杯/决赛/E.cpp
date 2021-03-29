#include <iostream>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::map;
using std::pair;

int n,m,cnt=0;
map<int, int> money,cost;

int main()
{
    cin>>n>>m;
    int temp;
    map<int, int>::iterator buy,sail;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        money[temp]++;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>temp;
        cost[temp]++;
    }
    while( !money.empty() && !cost.empty())
    {
        buy=money.begin();
        sail=cost.begin();
        if((*buy).first>=(*sail).first)
        {
            if( (*buy).second==1 )  money.erase(buy);
            else    (*buy).second--;
            if( (*sail).second==1 ) cost.erase(sail);
            else    (*sail).second--;
            cnt++;
        }
        else    money.erase(money.begin());
    }
    cout<<cnt<<endl;
    return 0;
}