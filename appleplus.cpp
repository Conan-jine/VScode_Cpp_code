#include <iostream>
using namespace std;

int main()
{
	double arr[1000]={0};
	int n,all;
	cin>>n>>all;
	int a,b,L,maxnum=0;
	cin>>a>>b;
	L=a+b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a>L)	continue;
		else
		{
			arr[b]+=1;
			if(b>maxnum)	maxnum=b;
		}
	}
	n=0;
	for(int i=0;i<=maxnum;i++)
	{
		if(all>0)
		{
			for(int j=1;j<=arr[i];j++)
			{
				all-=i;
				if(all>=0)	n++;
				else break;
			}
		}
		if(all<0)	break;
	}
	cout<<n;
	return 0;
}