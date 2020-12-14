#include <iostream>
using namespace std;

int main()
{
	int n,k,done=0;
	cin>>n>>k;
	int sum=0;
	while(n+done>=k)
	{
		sum+=n;
		done+=n;
		n=done/k;
		done%=k;
	}
	cout<<sum+n<<endl;
	return 0;
}
