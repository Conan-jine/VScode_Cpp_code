#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int x,y,tx,ty;
	int n,m,times=0;
	char **arr,*str;
	cin>>times;
	while(times--)
	{
		cin>>n;
		arr=new char *[n+1];
		str=new char [1010];
		for(int i=0;i<n+1;i++)	arr[i]=new char [n+1];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j]=='S')
				{
					x=i;
					y=j;
				}
			}
		}
		(cin>>m).get();
		while(m--)
		{
			tx=x;
			ty=y;
			cin.getline(str,1010);
			//cout<<"strlen="<<strlen(str)<<endl;
			for(unsigned int i=0;i<strlen(str);i++)
			{
				//cout<<"i="<<i<<endl;
				if(str[i]=='L')	ty-=1;
				else if(str[i]=='R')	ty+=1;
				else if(str[i]=='U')	tx-=1;
				else if(str[i]=='D')	tx+=1;
				//cout<<"Work!"<<endl;
				if(arr[tx][ty]=='#')
				{
					cout<<"I am dizzy!"<<endl;
					break;
				}
				else if((tx<0||tx>=n)||(ty<0||ty>=n))
				{
					cout<<"I am out!"<<endl;
					break;
				}
				//cout<<"i="<<i<<endl;
			}
			if(arr[tx][ty]=='.'||arr[tx][ty]=='S')	cout<<"I have no idea!"<<endl;
			else if(arr[tx][ty]=='T')	cout<<"I get there!"<<endl;
		}
		for(int i=0;i<n;i++)
		{
			delete [] arr[i];
		}
		delete [] arr;
		delete [] str;
	}
	return 0;
}