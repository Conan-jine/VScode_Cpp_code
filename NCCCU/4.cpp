#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int arr[10000];
    int num,i=0;
    while(scanf("%d",&num)!=EOF)
    {
        arr[i]=num;
        i++;
    }
    int headnum=arr[i-1];
    cout<<"head"<<headnum<<endl;
}