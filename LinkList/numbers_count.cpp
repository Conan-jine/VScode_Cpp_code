#include <iostream>
#include <string>
#include <deque>
using namespace std;

int fun(string a)
{
	int sum=0;
	for(unsigned int i=0;i<a.length();i++)
	{
		if(a[i]=='2')	sum++;
	}
	return sum;
}

int main()
{
	string temp;
	deque<string> arr;
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		arr.push_front(std::to_string(i));
	}
	deque<string>::iterator it;
	while(!arr.empty())
	{
		temp=arr.front();
		sum+=fun(temp);
		arr.pop_front();
	}
	cout<<sum<<endl;
	return 0;
}