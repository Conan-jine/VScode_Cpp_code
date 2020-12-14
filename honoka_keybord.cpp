#include <iostream>
using namespace std;

int main()
{
	int n;
	char arr[100000];
	(cin>>n).get();
	cin>>arr;
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]=='V'&&arr[i+1]=='K')
		{
			arr[i]=' ';
			arr[i+1]=' ';
			sum++;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]=='V'&&arr[i+1]!=' ')
		{
			sum++;
			break;
		}
		else if(arr[i]!=' '&&arr[i+1]=='K')
		{
			sum++;
			break;
		}
	}
	cout<<sum<<endl;
	return 0;
}
