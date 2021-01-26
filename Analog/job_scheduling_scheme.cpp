#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int m,n;

bool machine[ 25 ][ 8000 ]={0};             // 记录每台机器的运行时段
bool workpieceTime[ 25 ][ 8000 ]={0};       // 记录每个器件的被操作时段

int targetMac[ 25 ][ 25 ]={0};              // 记录每个器件工序所用机器
int needTime[ 25 ][ 25 ]={0};               // 记录每个器件工序所用时间

int my_queue[ 420 ]={0};                    // 记录给定的安排顺序
int my_wp[ 25 ]={0};                        // 记录器件需要执行的工序
int my_wpStartT[ 25 ]={0};                  // 记录下一道工序开始的时间

bool timeEnough(int choice1, int choice2, int begin, int len);              // 判断机器和器件该时间段是否可用
void mark(bool arr[  ][ 8000 ], int choice, int begin, int len);            // 标记该段时间已用

/*
    true 表示在用 false 表示不在用
    各数组下标代表的意思：
    1. machine[i][j]            表示机器 i 在 j 时刻是否已用    （连续几个时刻即为时间）
    2. workpieceTime[i][j]      表示器件 i 在 j 时刻是否在加工
    3. targetMac[i][j]          表示器件 i 的第 j 道工序所需要使用的机器
    4. needTime[i][j]           表示器件 i 的第 j 道工序所需要使用的时间
    5. my_queue[i]              表示给定的安排顺序中 第 i 位是哪个器件
    6. my_wp[i]                 表示器件 i 目前需要加工第几个工序 （题目给的数据是按照位置告诉你这是第几道工序的，所以这里我全都是用下标 0 代表工序 1, 下标 1 代表工序 2, 以此类推）
    7. my_wpStartT[i]           表示器件 i 的当前工序需要在哪个时刻开始 （器件的每个工序都访问这个数组，以此来确定应该从哪个时刻开始，每次工序完成后也会刷新数组的值
*/

int main()
{
    cin>>m>>n;
    for(int i=0;i<n*m;i++)  cin>>my_queue[ i ];
    for(int i=1;i<=n;i++)    for(int j=0;j<m;j++)    cin>>targetMac[ i ][ j ];
    for(int i=1;i<=n;i++)    for(int j=0;j<m;j++)    cin>>needTime[ i ][ j ];
    for(int i=0;i<n*m;i++)
    {
        for(int j=my_wpStartT[my_queue[ i ]];j<8000;j++)    // j不从0开始是因为，第二道工序必须在第一道工序之后
        {   
            // 判断机器在该时间段是否能用
            // 判断器件在该时间段是否可加工
            if(timeEnough(targetMac[ my_queue[ i ] ][ my_wp[ my_queue[ i ] ] ],my_queue[ i ],j,needTime[ my_queue[ i ] ][ my_wp[ my_queue[ i ] ] ]))
            {
                // cout<<"machine:"<<my_queue[i]<<"  start time:"<<j<<endl;
                // 标记已用的时间段
                mark(machine,targetMac[ my_queue[ i ] ][ my_wp[ my_queue[ i ] ] ],j,needTime[ my_queue[ i ] ][ my_wp[ my_queue[ i ] ] ]);
                mark(workpieceTime,my_queue[ i ],j,needTime[ my_queue[ i ] ][ my_wp[ my_queue[ i ] ] ]);
                my_wpStartT[ my_queue[ i ] ]=j+needTime[ my_queue[ i ] ][ my_wp[ my_queue[ i ] ] ];     // 刷新数组的值，确保下一道工序是在上一道工序之后
                my_wp[ my_queue[ i ] ]++;                                                               // 器件必须先完成第一道工序才能进行第二道工序，这里对工序往后推
                break;
            }
        }
    }
    int len=0;
    // 判断哪个机器用时最长
    for(int i=1;i<=m;i++)
    {
        for(int j=7999;j>=0;j--)
        {
            if(machine[ i ][ j ]==false)    continue;
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
    for(int i=0;i<len;i++)  if(machine[ choice1 ][ i+begin ] || workpieceTime[ choice2 ][ i+begin ])   return false;
    return true;
}

void mark(bool arr[  ][ 8000 ], int choice, int begin, int len)
{
    for(int i=0;i<len;i++)  arr[ choice ][ i+begin ]=true;
}