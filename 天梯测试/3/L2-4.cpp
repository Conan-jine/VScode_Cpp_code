#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool map[520][520];
bool color[520];
int colorPain[520];
int lenColor,V,E,K;

bool check()
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(map[i][j] && colorPain[i]==colorPain[j]) return false;
        }
    }
    return true;
}

int main()
{
    int x,y,T;
    cin>>V>>E>>K;
    for(int i=0;i<E;i++)
    {
        cin>>x>>y;
        map[x][y]=true;
        map[y][x]=true;
    }
    cin>>T;
    while(T--)
    {
        lenColor=0;
        for(int i=1;i<=V;i++)    color[i]=false;
        for(int i=1;i<=V;i++)
        {
            cin>>colorPain[i];
            if(!color[colorPain[i]])    lenColor++;
            color[colorPain[i]]=true;
        }
        if(lenColor!=K) cout<<"No"<<endl;
        else if(check()) cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;        
    }
    return 0;
}