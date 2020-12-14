#include <iostream>
using namespace std;

int fun(int *arr, int loc, int len)
{
	int sum=0;
	for(int i=loc;i<loc+len;i++)	sum+=arr[i];
	return sum;
}

int main()
{
	int n,m,temp,MIN=10000000;
	cin>>n>>m;
	int arr[3005];
	for(int i=0;i<n;i++)	cin>>arr[i];
	for(int i=0;i<n-m+1;i++)
	{
		temp=fun(arr,i,m);
		if(temp<MIN)	MIN=temp;
	}
	cout<<MIN<<endl;
	return 0;
}