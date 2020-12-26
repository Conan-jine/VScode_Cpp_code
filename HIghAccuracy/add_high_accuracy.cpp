#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string a,b,t;
	int len1,len2;
	cin>>a;
	cin>>b;
	len1=a.size();
	len2=b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int arr[510]={0};
	for(int i=0;i<len1||i<len2;i++)
	{
		if(i>=len1&&i<len2)	arr[i]=int(b[i]-'0');
		else if(i>=len2&&i<len1)	arr[i]=int(a[i]-'0');
		else	arr[i]=int(a[i]-'0')+int(b[i]-'0');
	}
	for(int i=0;i<len1+1||i<len2+1;i++)
	{
		if(arr[i]>9)
		{
			arr[i]%=10;
			arr[i+1]+=1;
		}
	}
	bool jge=false;
	for(int i=(len1>len2?len1+1:len2+1);i>=0;i--)
	{
		if(arr[i]!=0)
		{
			jge=true;
		}
		if(jge)
		{
			cout<<arr[i];
		}
	}
	if(jge==false)	cout<<0<<endl;
	return 0;
}