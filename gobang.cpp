#include <iostream>
using namespace std;

char arr[25][25]={0};
bool aaa[25][25]={0};
int num[625][2]={0};
int n=0;
bool judge=0;

void fun(int x,int y,char c)
{
	int temp=0,mark=0;
	int a,b;
	for(int i=0;i<5;i++)
	{
		if(arr[x-i][y-i]==c)	temp++;
		else if(arr[x-i][y-i]=='.')
		{
			mark=1;
			a=x-i;
			b=y-i;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
	for(int i=0;i<5;i++)
	{
		if(arr[x-i][y]==c)	temp++;
		else if(arr[x-i][y]=='.')
		{
			mark=1;
			a=x-i;
			b=y;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
	for(int i=0;i<5;i++)
	{
		if(arr[x-i][y+i]==c)	temp++;
		else if(arr[x-i][y+i]=='.')
		{
			mark=1;
			a=x-i;
			b=y+i;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
	for(int i=0;i<5;i++)
	{
		if(arr[x+i][y-i]==c)	temp++;
		else if(arr[x+i][y-i]=='.')
		{
			mark=1;
			a=x+i;
			b=y-i;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
	for(int i=0;i<5;i++)
	{
		if(arr[x+i][y]==c)	temp++;
		else if(arr[x+i][y]=='.')
		{
			mark=1;
			a=x+i;
			b=y;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
	for(int i=0;i<5;i++)
	{
		if(arr[x+i][y+i]==c)	temp++;
		else if(arr[x+i][y+i]=='.')
		{
			mark=1;
			a=x+i;
			b=y+i;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
	for(int i=0;i<5;i++)
	{
		if(arr[x][y+i]==c)	temp++;
		else if(arr[x][y+i]=='.')
		{
			mark=1;
			a=x;
			b=y+i;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
	for(int i=0;i<5;i++)
	{
		if(arr[x][y-i]==c)	temp++;
		else if(arr[x][y-i]=='.')
		{
			mark=1;
			a=x;
			b=y-i;
		}
	}
	if(temp==4&&mark==1&&!aaa[a][b])
	{
		num[n][0]=a;
		num[n][1]=b;
		n++;
		aaa[a][b]=1;
		judge=1;
	}
	temp=0;
	mark=0;
}



int main()
{
	int black=0,white=0;
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]=='o')	white++;
			if(arr[i][j]=='x')	black++;
		}
	}
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			if(black==white)
			{
				fun(i,j,'x');
			}
			if(white<black)
			{
				fun(i,j,'o');
			}
		}
	}
	int temp=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(num[j][0]>num[j+1][0])
			{
				for(int k=0;k<2;k++)
				{
					temp=num[j][k];
					num[j][k]=num[j+1][k];
					num[j+1][k]=temp;
				}
			}
			if(num[j][0]==num[j+1][0])
			{
				if(num[j][1]>num[j+1][1])
				{
					temp=num[j][1];
					num[j][1]=num[j+1][1];
					num[j+1][1]=temp;
				}
			}
		}
	}
	if(judge)
	{
		for(int i=0;i<n;i++)
		{
			cout<<num[i][0]<<' '<<num[i][1]<<endl;
		}
	}
	if(!judge)	cout<<"tie"<<endl;
	return 0;
}