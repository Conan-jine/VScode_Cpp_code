#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	deque<string> arr,str,str1;
	string temp;
	while(cin>>temp)
	{
		str.push_back(temp);
		if(cin.get()=='\n')	break;
	}
	str1=str;
	while(cin>>temp)
	{
		arr.push_back(temp);
		if(cin.get()=='\n')	break;
	}
	for(unsigned int i=0;i<str.size();i++)	sort(str[i].begin(),str[i].end());
	for(unsigned int i=0;i<arr.size();i++)	sort(arr[i].begin(),arr[i].end());
	for(unsigned int i=0;i<str.size();i++)
	{
		for(unsigned int j=0;j<arr.size();j++)
		{
			if(str[i]==arr[j])
			{
				cout<<str1[i]<<' ';
				break;
			}
		}
	}
	return 0;
}