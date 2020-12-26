#include <iostream>
using namespace std;

bool fun(int n)
{
	if(n<0)	return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)	return false;
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	for(int i=2;i<n-2;i++)
	{
		if(fun(i))
		{
			for(int j=i;j<n-2;j++)
			{
				if(fun(j))
				{
					if(fun(n-i-j)&&j<n-i-j)
					{
						cout<<i<<' '<<j<<' '<<n-i-j<<endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}