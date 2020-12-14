#include <iostream>
#include <cmath>
using namespace std;

int arr[1025][1025]={0};

void fun(int a,int b,int len)
{
	if(len==1)	return;
	else
	{
		for(int i=a;i<a+len/2;i++)	for(int j=b;j<b+len/2;j++)	arr[i][j]=0;
		for(int i=a+len/2;i<a+len;i++)	for(int j=b+len/2;j<b+len;j++)	arr[i][j]=1;
		for(int i=a;i<a+len/2;i++)	for(int j=b+len/2;j<b+len;j++)	arr[i][j]=1;
		for(int i=a+len/2;i<a+len;i++)	for(int j=b;j<b+len/2;j++)	arr[i][j]=1;
		fun(a+len/2,b+len/2,len/2);
		fun(a,b+len/2,len/2);
		fun(a+len/2,b,len/2);
	}
}

int main()
{
	int n,len;
	cin>>n;
	len=pow(2,n);
	fun(1,1,len);
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)	cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}