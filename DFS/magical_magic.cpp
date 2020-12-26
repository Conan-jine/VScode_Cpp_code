#include <iostream>
using namespace std;

int arr[39][39]={0};

void fun(int k,int max,int x,int y)
{
	if(k==max*max+1)	return;
	if(x==0&&y!=max-1)
	{
		arr[max-1][y+1]=k+1;
		fun(k+1,max,max-1,y+1);
	}
	else if(y==max-1&&x!=0)
	{
		arr[x-1][0]=k+1;
		fun(k+1,max,x-1,0);
	}
	else if(x==0&&y==max-1)
	{
		arr[x+1][y]=k+1;
		fun(k+1,max,x+1,y);
	}
	else
	{
		if(arr[x-1][y+1]==0)
		{
			arr[x-1][y+1]=k+1;
			fun(k+1,max,x-1,y+1);
		}
		else
		{
			arr[x+1][y]=k+1;
			fun(k+1,max,x+1,y);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	arr[0][n/2]=1;
	fun(1,n,0,n/2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j!=0)	cout<<' ';
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;
}
