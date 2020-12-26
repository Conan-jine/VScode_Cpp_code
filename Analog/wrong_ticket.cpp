#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a=100010,z=-1,num;
	int arr[100010]={0};
	int times;
	int x=0,y=0;
	(cin>>times).get();
	while(times--)
	{
		while(cin>>num)
		{
			arr[num]++;
			if(num<a)	a=num;
			else if(num>z)	z=num;
			if(cin.get()=='\n')	break;
		}
	}
	for(int i=a;i<=z;i++)
	{
		if(arr[i]==0)	x=i;
		else if(arr[i]==2) y=i;
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}