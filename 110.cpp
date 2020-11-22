#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double arr[20],brr[20],num=136;
	for(int i=0;i<15;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<15;i++)
	{
		cout<<pow(arr[i]/num,2)<<endl;
	}
}