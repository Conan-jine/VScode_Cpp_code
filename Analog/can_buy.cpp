#include <iostream>
using namespace std;

int arr[1000000]={0};

int main()
{
	int n,m,sum=0;
	cin>>m>>n;
	int loc=2,lucky=3,len=0;
	for(int i=2;i<1000000;i+=2)	arr[i]=1;
	while(1)
	{
		len=0;
		for(int i=1;i<n;i++)
		{
			if(arr[i]==0)
			{
				len++;
				if(len%lucky==0)	arr[i]=1;
			}
		}
		len=0;
		loc++;
		for(int i=1;;i++)
		{
			if(arr[i]==0)	len++;
			if(len==loc)
			{
				lucky=i;
				break;
			}
		}
		if(lucky>=n) break;
		
	}
	for(int i=m+1;i<n;i++)
	{
		if(arr[i]==0)	sum++;
	}
	cout<<sum<<endl;
	return 0;
}