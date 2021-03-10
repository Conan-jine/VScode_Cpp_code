#include<iostream>
#include <algorithm> // 常用头文件，内有sort函数

using std::cin;
using std::cout;
using std::endl;

int a[100010];

int main()
{
	int n,t,temp;
	cin>>n;
	if(n>0)
	{
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
        // 对a数组进行排序；
        std::sort(a,a+n);
		t=a[n-1]*10+n+n*5;
		for(int i=0;i<n-1;i++)
		{
			if(0==a[i])
			{
				t-=5;
			}
			if(0!=a[i]&&a[i]==a[i+1])
			{
				t-=5;
			}
		}
		if(0==a[n-1])
			t-=5;
		cout<<t<<endl;
	}
	return 0;
}
