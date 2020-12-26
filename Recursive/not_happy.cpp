#include <iostream>
using namespace std;

int main()
{
	int n,all=0,today,lastd=0;
	int inclass,outclass=0;
	cin>>n;
	while(n--)
	{
		cin>>inclass>>outclass;
		today=lastd+inclass+outclass-8;
		all+=today;
		lastd=today;
	}
	cout<<all<<endl;
	return 0;
}