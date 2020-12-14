#include <iostream>
using namespace std;

int main()
{
	int arr[21][21][21]={0};
	for(int i=0;i<21;i++)
	{
		for(int j=0;j<21;j++)
		{
			for(int k=0;k<21;k++)	arr[i][j][k]=1;
		}
	}
	int x,y,z;
	cin>>x>>y>>z;
	int len;
	cin>>len;
	int x1,x2,y1,y2,z1,z2;
	while(len--)
	{
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		for(int i=x1;i<=x2;i++)
		{
			for(int j=y1;j<=y2;j++)
			{
				for(int k=z1;k<=z2;k++)
				{
					arr[i][j][k]=0;
				}
			}
		}
	}
	int sum=0;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			for(int k=1;k<=z;k++)	sum+=arr[i][j][k];
		}
	}
	cout<<sum<<endl;
	return 0;
}