#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int cnt[100000]={0};
	int now,last
	for(int i=0;i<n-1;i++)
	{
		cnt[abs(num[i]-num[i+1])]++;
	}
	bool judge=true;
	for(int i=1;i<n;i++)
	{
		if(cnt[i]==0)
		{
			judge=false;
			break;
		}
	}
	if(judge)	cout<<"Jolly"<<endl;
	else	cout<<"Not jolly"<<endl;
	return 0;
}