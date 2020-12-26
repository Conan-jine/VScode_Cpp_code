#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string name;
	cin>>n;
	while(n--)
	{
		name.clear();
		cin>>name;
		if(name=="WYS")	cout<<"KXZSMR"<<endl;
		else if(name=="CQ")	cout<<"CHAIQIANG"<<endl;
		else if(name=="LC")	cout<<"DRAGONNET"<<endl;
		else if(name=="SYT"||name=="SSD"||name=="LSS"||name=="LYF")	cout<<"STUDYFATHER"<<endl;
		else	cout<<"DENOMINATOR"<<endl;
	}
	return 0;
}