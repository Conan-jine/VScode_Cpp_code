#include <iostream>
using namespace std;

int main()
{
	int times;
	int n,*arr;
	int BIG=-1;
	bool t=true;
	cin>>times;
	while(times--)
	{
		cin>>n;
		t=true;
		arr=new int [n];
		BIG=-1;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]>BIG)	BIG=arr[i];
		}
		if(arr[0]==BIG&&arr[0]>arr[1])
		{
			cout<<1<<endl;
			t=false;
		}
		else if(arr[n-1]==BIG&&arr[n-1]>arr[n-2])
		{
			cout<<n<<endl;
			t=false;
		}
		else
		{
			for(int i=1;i<n-1;i++)
			{
				if(arr[i]>arr[i-1]||arr[i]>arr[i+1])
				{
					cout<<i+1<<endl;
					t=false;
					break;
				}
			}
		}
		if(t)	cout<<-1<<endl;
		delete [] arr;
	}
	return 0;
}
