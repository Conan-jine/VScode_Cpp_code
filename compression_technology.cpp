#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n,num,judge=0,len=1;
	string temp;
	getline(cin,temp);
	stringstream str;
	str.clear();
	str<<temp;
	str>>n;
	while(str>>num)
	{
		for(int i=0;i<num;i++)
		{
			judge++;
			if(len%2==1)	cout<<0;
			else	cout<<1;
			if(judge==n)
			{
				cout<<endl;
				judge-=n;
			}
		}
		len++;
	}
	return 0;
}