#include <iostream>
using namespace std;

int An(int n)
{
	if(n==1||n==2)  return 1;
	else
	{
		return An(n-2)+2*An(n-1);
	}
}

int main()
{
	int S[100]={0},end=0;
	int a,b,c,arr[3]={0};
	cin>>a>>b>>c;
	for(int i=1;;i++)
	{
		for(int j=1;j<=i;j++)
		{
			S[i]+=An(j);
		}
		if(S[i]>c)  break;
	}
	for(int i=1;S[i]<c;i++)
	{
		if(S[i]<a&&S[i+1]>=a)	arr[0]=i;
		else if(S[i]<b&&S[i+1]>=b)    arr[1]=i;
		else if(S[i]<c&&S[i+1]>=c)
		{
			arr[2]=i;
			end=1;
			break;
		}
		else    continue;
		if(end==1) break;
	}
	for(int i=0;i<3;i++)    cout<<arr[i]<<endl;
	for(int i=1;i<100;i++)	cout<<i<<"="<<S[i]<<' ';
	return 0;
}