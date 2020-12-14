#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	stringstream str;
	str.clear();
	string temp;
	unsigned int len,n=0;
	int num=0;
	cin>>temp;
	len=temp.size();
	str<<temp;
	for(unsigned int i=1;i<len;i++)
	{
		cin>>temp;
		str<<temp;
	}
	str>>temp;
	//cout<<temp<<endl;
	cout<<len;
	len=temp.size();
	num=0;
	for(unsigned int i=0;i<len;i++)
	{
		if(num==int(temp[i]-'0'))	n++;
		else
		{
			cout<<' '<<n;
			n=1;
			num++;
			while(num>1)	num-=2;
		}
	}
	cout<<' '<<n;
	return 0;
}