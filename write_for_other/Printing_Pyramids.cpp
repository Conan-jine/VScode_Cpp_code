#include <iostream>
using namespace std;

void printSpace(int row);

int main()
{
    int i,n,maxnum,rowMaxNum,row=1;
    // n 表示金字塔的高度
    // rwo 表示第几行
    // maxnum 表示金字塔的最大数字
    // rowMaxNum 表示每一行最后一个数字，可用公式计算得出，等差数列的前n项和
    // columnSpace 表示每一行前面需要打印的空格，保证金字塔的形状
    // 虽然说因为数字有1位 2位（10~99） 3位（100~999）会导致金字塔变形
    cout<<"Please input the height of Pyramid: ";
    cin>>n;
    maxnum=n*(n+1)/2;
    rowMaxNum=row*(row+1)/2;
    printSpace(n-1);
    for(int i=1;i<=maxnum;i++)
    {
        cout<<i<<' ';
        if(i>=rowMaxNum)
        {
            row++;
            cout<<endl;
            printSpace(n-row);
            rowMaxNum=row*(row+1)/2;
        }
    }
}

void printSpace(int row)
{
    int rowSpace=row;
    for(int i=0;i<rowSpace;i++)
    {
        cout<<' ';
    }
}