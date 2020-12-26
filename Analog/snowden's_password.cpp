#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

string arr[21]={"one", "two", "three", "four", "five", "six", "seven" ,"eight" ,"nine", "ten" ,"eleven" ,"twelve" ,"thirteen" ,"fourteen" ,"fifteen" ,"sixteen" , "eighteen" ,"nineteen" ,"twenty"};

int main()
{
	bool begin=true;
	priority_queue< int,deque<int>,greater<int> > a,b;
	string str;
	for(int i=0;i<6;i++)
	{
		cin>>str;
		for(unsigned j=0;j<str.size();j++)
		{
			if(str[j]>='A'&&str[j]<='Z')	str[j]+=32;
		}
		if(str=="a")	a.push(1);
		else if(str=="both")	a.push(2);
		else if(str=="another")	a.push(1);
		else if(str=="first")	a.push(1);
		else if(str=="second")	a.push(2);
		else if(str=="third")	a.push(3);
		else
		{
			for(int j=0;j<20;j++)
			{
				if(str==arr[j])
				{
					a.push(j+1);
					break;
				}
			}
		}
	}
	int num;
	while(!a.empty())
	{
		num=a.top();
		num=num*num%100;
		if(num!=0)	b.push(num);
		a.pop();
	}
	if(b.empty())	cout<<0<<endl;
	while(!b.empty())
	{
		if(!begin)	cout<<setw(2)<<setfill('0')<<b.top();
		else	cout<<b.top();
		b.pop();
		begin=false;
	}
	return 0;
}