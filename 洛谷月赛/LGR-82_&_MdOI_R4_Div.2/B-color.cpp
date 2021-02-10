#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool judge,visit[200020];
char arr[2][100010];
int times,n;

int main()
{
    cin>>times;
    while(times--)
    {
        cin>>n;
        judge=false;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
                visit[i*n+j]=false;
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]=='0')  continue;
                if(arr[i][j]=='1')
                {
                    if(j-1>=0)
                    {
                        if(arr[i][j-1]=='0' && !visit[i*n+j-1])
                        {
                            visit[i*n+j-1]=true;
                            judge=false;
                            continue;
                        }
                        else    judge=true;
                    }
                    if(i+1<2)
                    {
                        if(arr[i+1][j]=='0' && !visit[i*n+n+j])
                        {
                            visit[i*n+n+j]=true;
                            judge=false;
                            continue;
                        }
                        else    judge=true;
                    }
                    if(i-1>=0)
                    {
                        if(arr[i-1][j]=='0' && !visit[i*n-n+j])
                        {
                            visit[i*n-n+j]=true;
                            judge=false;
                            continue;
                        }
                        else    judge=true;
                    }
                    if(j+1<n)
                    {
                        if(arr[i][j+1]=='0' && !visit[i*n+j+1])
                        {
                            visit[i*n+j+1]=true;
                            judge=false;
                            continue;
                        }
                        else    judge=true;
                    }
                    if(judge)   break;
                }
            }
            if(judge)   break;
        }
        if(judge)   cout<<"++"<<endl;
        else    cout<<"RP"<<endl;
    }
    return 0;
}