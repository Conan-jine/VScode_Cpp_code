#include <iostream>
using namespace std;

int main()
{
	int arr[30000]={0};
	int n,k,mark=0,temp;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		arr[temp]++;
	}
	int len=0;
	for(int i=0;i<30000;i++)
	{
		if(arr[i]>=1)
		{
			len++;
			if(len==k)
			{
				temp=i;
				mark=1;
				break;
			}
		}
	}
	if(mark==0)	cout<<"NO RESULT"<<endl;
	else	cout<<temp<<endl;
	return 0;
}