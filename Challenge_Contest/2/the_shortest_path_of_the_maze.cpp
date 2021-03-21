#include <iostream>
// #include <utility>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::queue;

const int INF=100000000;

char maze[120][120];
int arr[120][120];
int n,m,beginX,beginY,endX,endY;

int addX[4]={-1,0,1,0};
int addY[4]={0,1,0,-1};

void bfs()
{
    queue< pair<int, int> > que;
    for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    arr[i][j]=INF;
    que.push(pair<int, int>(beginX,beginY));
    arr[beginX][beginY]=0;

    while(que.size())
    {
        pair<int, int> temp=que.front();
        que.pop();
        if(temp.first==endX && temp.second==endY)   break;
        // 如果需要知道全部的点的最短距离，就不需要break; 
        for()
    }
}

int main()
{
    
    return 0;
}