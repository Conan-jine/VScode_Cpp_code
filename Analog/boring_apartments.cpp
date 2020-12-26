#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int len,num=0;
	char c;
	string str;
	int times;
	cin>>times;
	while(times--)
	{
		num=0;
		cin>>str;
		len=str.size();
		c=str[0];
		num=int(c-'0')*10+len*(len+1)/2;
		cout<<num-10<<endl;
	}
	return 0;
}
