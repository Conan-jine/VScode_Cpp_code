#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int c1=1,c2=0,c3=0,c4=0;
	int x=0,y=0;
	int arr[11][11];
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)	arr[i][j]=1;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)	arr[i][j]=0;
	}
	for(int i=0;i<n*n;i++)
	{
		if(c1==1)
		{
			arr[x][y]=i+1;
			y++;
			if(arr[x][y]!=0)
			{
				y--;
				x++;
				c2=1;
				c1=0;
			}
		}
		else if(c2==1)
		{
			arr[x][y]=i+1;
			x++;
			if(arr[x][y]!=0)
			{
				x--;
				y--;
				c3=1;
				c2=0;
			}
		}
		else if(c3==1)
		{
			arr[x][y]=i+1;
			y--;
			if(arr[x][y]!=0)
			{
				y++;
				x--;
				c4=1;
				c3=0;
			}
		}
		else if(c4==1)
		{
			arr[x][y]=i+1;
			x--;
			if(arr[x][y]!=0)
			{
				x++;
				y++;
				c1=1;
				c4=0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<setw(3)<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;
}
	