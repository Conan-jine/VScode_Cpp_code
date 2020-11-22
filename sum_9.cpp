#include <iostream>
using namespace std;

int main()
{
	int n,t;
	cin>>n;
	int sum=0,all=0;
	for(int i=9;i<=n;i++)
	{
		t=i;
		sum=0;
		while(t)
		{
			sum+=t%10;
			t/=10;
		}
		if(sum==9)	all++;
	}
	cout<<all<<endl;
}