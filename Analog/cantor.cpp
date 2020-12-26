#include <iostream>
using namespace std;

int main()
{
	int x=1,y=1;
	int xp=1,yp=0,rules=1;
	int n;
	cin>>n;
	n--;
	while(n--)
	{
		if(xp==1)
		{
			y++;
			xp=0;
			rules=1;
		}
		else if(yp==1)
		{
			x++;
			yp=0;
			rules=0;
		}
		else if(rules==1)
		{
			x++;
			y--;
			if(y==1)	yp=1;
		}
		else if(rules==0)
		{
			x--;
			y++;
			if(x==1)	xp=1;
		}
		if(n<0)	break;
	}
	cout<<x<<'/'<<y<<endl;
	return 0;
}
