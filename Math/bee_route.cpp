#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string dp[1010];

void search(int num)
{
    if(dp[num].size()==0 && num>1)
    {
        search(num-1);
        search(num-2);
        for(int i=0;i<dp[num-2].size();i++) dp[num]+=dp[num-1][i]-'0'+dp[num-2][i];
        for(int i=dp[num-2].size();i<dp[num-1].size();i++)  dp[num]+=dp[num-1][i];
        for(int i=0;i<dp[num].size();i++)
        {
            if(dp[num][i]>'9')
            {
                if(i==dp[num].size()-1) dp[num]+='0';
                dp[num][i+1]+=(dp[num][i]-'0')/10;
                dp[num][i]=(dp[num][i]-'0')%10+'0';
            }
        }
    }
}
int main()
{
    int a,b;
    dp[0]=dp[1]="1";
    cin>>a>>b;
    search(b-a);
    reverse(dp[b-a].begin(),dp[b-a].end());
    cout<<dp[b-a]<<endl;
    return 0;
}