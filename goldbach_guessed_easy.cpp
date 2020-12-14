#include <iostream>
using namespace std;

bool fun(int num)
{
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0)	return false;
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i+=2)
	{
		for(int j=2;j<=i-2;j++)
		{
			if(fun(j)&&fun(i-j))
			{
				cout<<i<<'='<<j<<'+'<<i-j<<endl;
				break;
			}
		}
	}
	return 0;
}