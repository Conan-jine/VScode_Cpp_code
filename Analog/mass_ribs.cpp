#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

bool arr[99999999]={0};

void fun(int num)
{
    for(int i=2;i*num<99999999;i++) arr[i*num]=1;
}

int main()
{
    cout<<clock()<<endl;
    for(int i=4;i<99999999;i+=2)    arr[i]=1;
    for(int i=3;i<99999999;i++)
    {
        if(!arr[i]) fun(i);
        else continue;
    }
    cout<<clock()<<endl;
}