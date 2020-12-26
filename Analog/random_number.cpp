#include <iostream>
using namespace std;

int main()
{
	int arr[1010]={0};
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		arr[num]++;
	}
	int sum=0;
	for(int i=0;i<1010;i++)
	{
		if(arr[i]>0)	sum++;
	}
	cout<<sum<<endl;
	for(int i=0;i<1010;i++)
	{
		if(arr[i]>0)	cout<<i<<' ';
	}
	return 0;
}