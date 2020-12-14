#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arr;
	getline(cin,arr);
	unsigned int sum=arr.size();
	for(unsigned int i=0;i<arr.size();i++)
	{
		if(arr[i]==' ')	sum--;
	}
	cout<<sum<<endl;
	return 0;
}