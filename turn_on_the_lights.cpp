#include <iostream>
using namespace std;

bool arr[2000005]={0};

int main()
{
	int n,t;
	double a;
	cin>>n;
	while(n--)
	{
		cin>>a>>t;
		for(int i=1;i<=t;i++)
		{
			arr[int(a*i)]=!arr[int(a*i)];
		}
	}
	for(int i=1;;i++)
	{
		if(arr[i]==true)
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}