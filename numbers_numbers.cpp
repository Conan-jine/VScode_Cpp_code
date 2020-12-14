#include <iostream>
using namespace std;

int main()
{
	int a,b,c,mark=0;
	int k;
	cin>>k;
	for(int i=10000;i<=30000;i++)
	{
		a=i/100;
		b=i%1000;
		c=i/10%1000;
		if(a%k==0&&b%k==0&&c%k==0)
		{
			cout<<i<<endl;
			mark=1;
		}
	}
	if(!mark)	cout<<"No"<<endl;
	return 0;
}