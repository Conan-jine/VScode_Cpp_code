#include <iostream>
using namespace std;

int main()
{
	long a1,b1,c1;
	long a2,b2,c2;
	char t;
	long skills;
	cin>>a1>>t>>b1>>t>>c1;
	cin>>a2>>t>>b2>>t>>c2;
	cin>>skills;
	c1+=a1*3600+b1*60;
	c2+=a2*3600+b2*60;
	unsigned long long end=(c2-c1)*skills;
	cout<<end<<endl;
	return 0;
}