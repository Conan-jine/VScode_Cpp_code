#include <iostream>
#include <string>
using namespace std;

struct puzzles
{
	bool face;
	string name;
};

int main()
{
	puzzles *arr;
	int n,times,loc=0;
	bool f;
	int steps;
	cin>>n>>times;
	arr=new puzzles [n];
	for(int i=0;i<n;i++)	cin>>arr[i].face>>arr[i].name;
	while(times--)
	{
		cin>>f>>steps;
		if(f==arr[loc].face)	loc-=steps;
		else loc+=steps;
		while(loc<0)	loc+=n;
		while(loc>=n)	loc-=n;
	}
	cout<<arr[loc].name<<endl;
	return 0;
}