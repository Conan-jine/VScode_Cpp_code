#include <iostream>
using namespace std;

int main()
{
	int *arr;
	int n,times;
	int num=0;
	bool timetoout=false;
	cin>>times;
	while(times--)
	{
		cin>>n;
		num=0;
		timetoout=false;
		arr=new int [n];
		for(int i=0;i<n;i++)	cin>>arr[i];
		for(int i=0;i<n;i++)
		{
			if(arr[i]==1)
			{
				for(int j=n-1;j>=0;j--)
				{
					if(arr[j]==1)
					{
						if(i==j)
						{
							cout<<0<<endl;
							timetoout=true;
							break;
						}
						else
						{
							for(int p=i;p<=j;p++)
							{
								if(arr[p]==0)	num++;
							}
							cout<<num<<endl;
							timetoout=true;
							break;
						}
					}
				}
			}
			if(timetoout)	break;
		}
		delete [] arr;
	}
}