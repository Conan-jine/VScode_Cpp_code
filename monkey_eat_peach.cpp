#include <iostream>
using namespace std;

int main()
{
	int sum=1;
	int n;
	cin>>n;
	n--;
	while(n--)
	{
		sum=(sum+1)*2;
	}
	cout<<sum<<endl;
	return 0;
}