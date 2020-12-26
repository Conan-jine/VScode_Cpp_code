#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> arr;
	char c;
	cin>>c;
	bool jge=false;
	while(c!='@')
	{
		if(c==')'&&arr.empty())
		{
			jge=false;
			arr.push(c);
		}
		else if(c==')'&&!arr.empty())
		{
			if(arr.top()=='(')	arr.pop();
		}
		if(c=='(')	arr.push(c);
		cin>>c;
	}
	if(arr.empty()) jge=true;
	if(jge)	cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;
	return 0;
}
