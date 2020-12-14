#include <iostream>
#include <string>
using namespace std;

struct stu
{
	string name;
	int a;
	int b;
	int c;
	int sum;
};

int main()
{
	int MAX=0;
	stu student[1010];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		student[i].sum=0;
		cin>>student[i].name>>student[i].a>>student[i].b>>student[i].c;
		student[i].sum+=student[i].a+student[i].b+student[i].c;
		if(student[i].sum>MAX)	MAX=student[i].sum;
	}
	for(int i=0;i<n;i++)
	{
		if(student[i].sum==MAX)
		{
			cout<<student[i].name<<' '<<student[i].a<<' '<<student[i].b<<' '<<student[i].c<<endl;
			break;
		}
	}
	return 0;
}