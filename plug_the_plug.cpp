#include <iostream>
using namespace std;

int n;
int arr[110][110]={0};

void fun1(int x,int y)
{
	for(int i=x-2;i<=x+2;i++)
	{
		if(i>0&&i<=n)	arr[i][y]=1;
	}
	for(int i=y-2;i<=y+2;i++)
	{
		if(i>0&&i<=n)	arr[x][i]=1;
	}
	for(int i=x-1;i<=x+1;i+=2)
	{
		for(int j=y-1;j<=y+1;j+=2)
		{
			if(i>0&&i<=n&&j>0&&j<=n)	arr[i][j]=1;
		}
	}
}

void fun2(int x,int y)
{
	for(int i=x-2;i<=x+2;i++)
	{
		for(int j=y-2;j<=y+2;j++)
		{
			if(i>0&&i<=n&&j>0&&j<=n)	arr[i][j]=1;
		}
	}
}

int main()
{
	int len1,len2;
	cin>>n>>len1>>len2;
	int x,y;
	while(len1--)
	{
		cin>>x>>y;
		fun1(x,y);
	}
	while(len2--)
	{
		cin>>x>>y;
		fun2(x,y);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)	sum+=arr[i][j];
	}
	cout<<n*n-sum<<endl;
	return 0;
}