#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str="abc-de";
	string addstr="abd";
	str.erase(str.begin()+3);
	str.insert(str.begin()+3,addstr.begin(),addstr.end());
	cout<<str<<endl;
	return 0;
}