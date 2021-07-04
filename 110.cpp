#include<iostream>

using std::cin;
using std::cout;
using std::endl;
int a[1000];
int b[1000][50];

int main()

{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a[i];
		for(int j=0;j<a[i];j++)
			cin>>b[a[i]][j];
	}
	for(int i=0;i<t;i++)
	{
		int sum=0;
		for(int j=0;j<a[i];j++)
			sum+=b[a[i]][j];
		if(1.0*sum/a[i]==1)
			cout<<0;
		else if(sum<=0)
			cout<<1;
		else
			cout<<sum-a[i];
		if(i!=t-1)
			cout<<endl;
	}
	return 0;
}
