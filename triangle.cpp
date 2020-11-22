#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	bool end=false;
	int arr[14100];
	for(int i=1;i<=14100;i++)	arr[i]=i*i;
	cin>>n;
	n=n*n;
	for(int i=1;i*i<n;i++)
	{
		for(int j=1;j*j<n;j++)
		{
			if(n==arr[i]+arr[j])
			{
				cout<<i<<' '<<j<<endl;
				end=true;
				break;
			}
		}
		if(end)	break;
	}
	return 0;
}