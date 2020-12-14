#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int x=0,y=0;
	int n=0,m=0;
	queue<int> a;
	queue<int> b;
	char c;
	while(cin>>c)
	{
		if(c=='W')
		{
			x++;
			n++;
		}
		else if(c=='L')
		{
			y++;
			m++;
		}
		else if(c=='E')
		{
			a.push(x);
			a.push(y);
			b.push(n);
			b.push(m);
			break;
		}

		if(abs(x-y)>1&&(x>10||y>10))
		{
			a.push(x);
			a.push(y);
			x=y=0;
		}
		if(abs(n-m)>1&&(n>20||m>20))
		{
			b.push(n);
			b.push(m);
			n=m=0;
		}
	}
	while(!a.empty())
	{
		cout<<a.front()<<':';
		a.pop();
		cout<<a.front()<<endl;
		a.pop();
	}
	cout<<endl;
	while(!b.empty())
	{
		cout<<b.front()<<':';
		b.pop();
		cout<<b.front()<<endl;
		b.pop();
	}
	return 0;
}