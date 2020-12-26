#include <iostream>
using namespace std;

int fun(int num)
{
	if(num!=1)	return num*fun(num-1);
	else	return 1;
}

int main()
{
	int n;
	cin>>n;
	cout<<fun(n);
	return 0;
}