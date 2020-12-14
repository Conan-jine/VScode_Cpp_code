#include <iostream>
using namespace std;

int main()
{
	int arr[23]={0};
	int arr1[23]={0};
	arr1[1]=1;
	arr[1]=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j!=1)	cout<<' ';
			arr1[j]=arr[j-1]+arr[j];
			cout<<arr1[j];
		}
		for(int j=0;j<=n;j++)	arr[j]=arr1[j];
		cout<<endl;
	}
	return 0;
}