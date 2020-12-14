#include <iostream>
using namespace std;

int num[10]={0};

int main()
{
	unsigned int n,m,temp;
	cin>>n>>m;
	for(unsigned int i=n;i<=m;i++)
	{
		temp=i;
		while(temp!=0)
		{
			num[temp%10]++;
			temp/=10;
		}
	}
	for(int i=0;i<10;i++)
	{
		cout<<num[i]<<' ';
	}
	return 0;
}