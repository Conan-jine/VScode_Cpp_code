#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int m,n;

bool machine[25][8000]={0};          // 记录每台机器的运行时段
bool workpieceTime[25][8000]={0};    // 记录每个器件的被操作时段

int targetMac[25][25]={0};           // 记录每个器件工序所用机器
int needTime[25][25]={0};            // 记录每个器件工序所用时间

int my_queue[420]={0};               // 记录给定的安排顺序
int my_wp[25]={0};                   // 记录器件需要执行的工序

bool timeEnough(int choice1, int choice2, int begin, int len);                    // 判断机器和器件该时间段是否可用
void mark(bool arr[][8000], int choice, int begin, int len);        // 标记该段时间已用

int main()
{
    cin>>m>>n;
    for(int i=0;i<n*m;i++)  cin>>my_queue[i];
    for(int i=1;i<=n;i++)    for(int j=0;j<m;j++)    cin>>targetMac[i][j];
    for(int i=1;i<=n;i++)    for(int j=0;j<m;j++)    cin>>needTime[i][j];
    for(int i=0;i<n*m;i++)
    {
        for(int j=0;j<8000;j++)
        {
            if(timeEnough(targetMac[my_queue[i]][my_wp[my_queue[i]]],my_queue[i],j,needTime[my_queue[i]][my_wp[my_queue[i]]]))
            {
                mark(machine,targetMac[my_queue[i]][my_wp[my_queue[i]]],j,needTime[my_queue[i]][my_wp[my_queue[i]]]);
                mark(workpieceTime,my_queue[i],j,needTime[my_queue[i]][my_wp[my_queue[i]]]);
                my_wp[my_queue[i]]++;
                break;
            }
        }
    }
    int len=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=7999;j>=0;j--)
        {
            if(machine[i][j]==false)    continue;
            else
            {
                len=len>j ? len : j;
                break;
            }
        }
    }
    cout<<len+1<<endl;
}

bool timeEnough(int choice1, int choice2, int begin, int len)
{
    for(int i=0;i<len;i++)  if(machine[choice1][i+begin] || workpieceTime[choice2][i+begin])   return false;
    return true;
}

void mark(bool arr[][8000], int choice, int begin, int len)
{
    for(int i=0;i<len;i++)  arr[choice][i+begin]=true;
}