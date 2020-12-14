#include <iostream>
#include <string>
using namespace std;

int main()
{
	int times;
	long long unsigned int position;
	string begin;
	int choice;
	string str;
	int a,b;
	int x;
	string ins;
	string son;
	cin>>times;
	cin>>begin;
	while(times--)
	{
		cin>>choice;
		if(choice==1)
		{
			cin>>str;
			begin+=str;
			cout<<begin<<endl;
		}
		else if(choice==2)
		{
			cin>>a>>b;
			begin=begin.substr(a,b);
			cout<<begin<<endl;
		}
		else if(choice==3)
		{
			cin>>x>>ins;
			begin.insert(x,ins);
			cout<<begin<<endl;
		}
		else if(choice==4)
		{
			cin>>son;
			position=begin.find(son);
			if(position!=begin.npos)	cout<<position<<endl;
			else	cout<<-1<<endl;
		}
	}
	return 0;
}