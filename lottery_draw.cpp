#include <iostream>
using namespace std;

int main()
{
	int arr[7],sum[7]={0};
	int n,temp,allnum=0;
	cin>>n;
	int arr1[34]={0};
	for(int i=0;i<7;i++)	cin>>arr[i];
	while(n--)
	{
		allnum=0;
		for(int i=0;i<34;i++)	arr1[i]=0;
		for(int i=0;i<7;i++)
		{
			cin>>temp;
			arr1[temp]++;
		}
		for(int i=0;i<7;i++)
		{
			if(arr1[arr[i]]>0)	allnum++;
		}
		if(allnum!=0)	sum[allnum-1]++;
	}
	for(int i=6;i>=0;i--)	cout<<sum[i]<<' ';
	return 0;
}