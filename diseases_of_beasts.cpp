#include <iostream>
using namespace std;

int main()
{
	unsigned long long x,n,temp=1;
	cin>>x>>n;
	while(n--)
	{
		temp=temp*(x+1);
	}
	cout<<temp<<endl;
	return 0;
}