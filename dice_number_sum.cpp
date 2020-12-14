#include <iostream>
using namespace std;

int main()
{
	int arr[85]={0};
	int temp=0;
	int x1,x2,x3;
	cin>>x1>>x2>>x3;
	for(int i=1;i<=x1;i++)
	{
		for(int j=1;j<=x2;j++)
		{
			for(int k=1;k<=x3;k++)
			{
				temp=i+j+k;
				arr[temp]++;
			}
		}
	}
	int MAX=0,loc;
	for(int i=0;i<85;i++)
	{
		if(arr[i]>MAX)
		{
			MAX=arr[i];
			loc=i;
		}
	}
	cout<<loc<<endl;
	return 0;
}