#include <iostream>
using namespace std;

void Copy(char **a,char **b,int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)	a[i][j]=b[i][j];
	}
}

void right(char **a,char **b,int n)
{
	Copy(b,a,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=b[j][n-i+1];
		}
	}
}

bool CMP(char **a,char **b,int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=b[i][j])	return false;
		}
	}
	return true;
}

void level_reverse(char **a,char **b,int n)
{
	Copy(b,a,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=b[i][n-j+1];
		}
	}
}

void SHOW(char **a,int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)	cout<<a[i][j];
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	char **NEW;
	char **TMP;
	char **OLD;
	char **END;
	NEW=new char *[11];
	OLD=new char *[11];
	TMP=new char *[11];
	END=new char *[11];
	for(int i=0;i<11;i++)
	{
		NEW[i]=new char [11];
		OLD[i]=new char [11];
		TMP[i]=new char [11];
		END[i]=new char [11];
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)	cin>>OLD[i+1][j+1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)	cin>>END[i+1][j+1];
	}
	Copy(NEW,OLD,n);
	right(NEW,TMP,n);
	right(NEW,TMP,n);
	right(NEW,TMP,n);
	if(CMP(NEW,END,n))
	{
		cout<<1<<endl;
		return 0;
	}

	Copy(NEW,OLD,n);
	right(NEW,TMP,n);
	right(NEW,TMP,n);
	if(CMP(NEW,END,n))
	{
		cout<<2<<endl;
		return 0;
	}

	Copy(NEW,OLD,n);
	right(NEW,TMP,n);
	if(CMP(NEW,END,n))
	{
		cout<<3<<endl;
		return 0;
	}

	Copy(NEW,OLD,n);
	level_reverse(NEW,TMP,n);
	if(CMP(NEW,END,n))
	{
		cout<<4<<endl;
		return 0;
	}
	right(NEW,TMP,n);
	if(CMP(NEW,END,n))
	{
		cout<<5<<endl;
		return 0;
	}
	right(NEW,TMP,n);
	if(CMP(NEW,END,n))
	{
		cout<<5<<endl;
		return 0;
	}
	right(NEW,TMP,n);
	if(CMP(NEW,END,n))
	{
		cout<<5<<endl;
		return 0;
	}
	
	Copy(NEW,OLD,n);
	if(CMP(NEW,END,n))
	{
		cout<<6<<endl;
		return 0;
	}

	cout<<7<<endl;
	return 0;
}