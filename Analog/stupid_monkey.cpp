#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[27]={0};
	string str;
	cin>>str;
	for(unsigned int i=0;i<str.size();i++)
	{
		arr[int(str[i]-'a')]++;
	}
	int MAX=0,MIN=100;
	for(int i=0;i<27;i++)
	{
		if(arr[i]>MAX)	MAX=arr[i];
		if(arr[i]<MIN&&arr[i]!=0)	MIN=arr[i];
	}
	int num=MAX-MIN;
	if(num==1||num==0)
	{
		cout<<"No Answer"<<endl<<0<<endl;
	}
	else
	{
		for(int i=2;i*i<=num;i++)
		{
			if(num%i==0)
			{
				cout<<"No Answer"<<endl<<0<<endl;
				return 0;
			}
		}
		cout<<"Lucky Word"<<endl<<num<<endl;
	}
	return 0;
}