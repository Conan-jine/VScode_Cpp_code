#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char arr[300];
	cin>>arr;
	int n=strlen(arr);
	int boys=0,girls=0;
	for(int i=0;i<n-3;i++)
	{
		if(arr[i]=='g'&&arr[i+1]=='i'&&arr[i+2]=='r'&&arr[i+3]=='l')
		{
			girls++;
			arr[i]=arr[i+1]=arr[i+2]=arr[i+3]='.';
		}
	}
	for(int i=0;i<n-2;i++)
	{
		if(arr[i]=='b'&&arr[i+1]=='o'&&arr[i+2]=='y')
		{
			boys++;
			arr[i]=arr[i+1]=arr[i+2]='.';
		}
		else if(arr[i]=='g'&&arr[i+1]=='i'&&arr[i+2]=='r')
		{
			girls++;
			arr[i]=arr[i+1]=arr[i+2]='.';
		}
		else if(arr[i]=='i'&&arr[i+1]=='r'&&arr[i+2]=='l')
		{
			girls++;
			arr[i]=arr[i+1]=arr[i+2]='.';
		}
	}
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]=='b'&&arr[i+1]=='o')
		{
			boys++;
			arr[i]=arr[i+1]='.';
		}
		else if(arr[i]=='o'&&arr[i+1]=='y')
		{
			boys++;
			arr[i]=arr[i+1]='.';
		}
		else if(arr[i]=='g'&&arr[i+1]=='i')
		{
			girls++;
			arr[i]=arr[i+1]='.';
		}
		else if(arr[i]=='i'&&arr[i+1]=='r')
		{
			girls++;
			arr[i]=arr[i+1]='.';
		}
		else if(arr[i]=='r'&&arr[i+1]=='l')
		{
			girls++;
			arr[i]=arr[i+1]='.';
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]=='b'||arr[i]=='o'||arr[i]=='y')
		{
			boys++;
			arr[i]='.';
		}
		else if(arr[i]=='g'||arr[i]=='r'||arr[i]=='i'||arr[i]=='l')
		{
			girls++;
			arr[i]='.';
		}
	}
	cout<<boys<<endl<<girls<<endl;
	return 0;
}