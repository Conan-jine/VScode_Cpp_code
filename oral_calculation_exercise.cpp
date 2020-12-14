#include <iostream>
#include <string>
using namespace std;

int fun(int a,int b,int c)
{
	string x,y,z;
	x=to_string(a);
	y=to_string(b);
	z=to_string(c);
	return 2+x.size()+y.size()+z.size();
}

void count(string c,int a,int b)
{
	int result;
	if(c=="a")
	{
		result=a+b;
		cout<<a<<"+"<<b<<"="<<result<<endl;
		cout<<fun(a,b,result)<<endl;
	}
	else if(c=="b")
	{
		result=a-b;
		cout<<a<<"-"<<b<<"="<<result<<endl;
		cout<<fun(a,b,result)<<endl;
	}
	else if(c=="c")
	{
		result=a*b;
		cout<<a<<"*"<<b<<"="<<result<<endl;
		cout<<fun(a,b,result)<<endl;
	}
	return;
}

int main()
{
	string c,t;
	int times;
	int a,b;
	cin>>times;
	while(times--)
	{
		cin>>c;
		if(c=="a"||c=="b"||c=="c")
		{
			cin>>a>>b;
			count(c,a,b);
			t=c;
		}
		else
		{
			cin>>a;
			count(t,stoi(c),a);
		}
	}
	return 0;
}
			