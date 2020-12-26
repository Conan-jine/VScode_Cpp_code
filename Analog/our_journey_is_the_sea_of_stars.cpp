#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x,y,tx,ty;
	int n,m,times=0;
	string str;
	char arr[60][60];
	cin>>times;
	while(times--)
	{
		cin>>n;
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
		cin>>m;
		while(m--)
		{
			tx=x;
			ty=y;
			cin>>str;
			//cout<<"strlen="<<strlen(str)<<endl;
			for(unsigned int i=0;i<str.size();i++)
			{
				//cout<<"i="<<i<<endl;
				if(str[i]=='L')	ty-=1;
				else if(str[i]=='R')	ty+=1;
				else if(str[i]=='U')	tx-=1;
				else if(str[i]=='D')	tx+=1;
				//cout<<"Work!"<<endl;
				
				if((tx<0||tx>=n)||(ty<0||ty>=n))
				{
					cout<<"I am out!"<<endl;
					break;
				}
				else if(arr[tx][ty]=='#')
				{
					cout<<"I am dizzy!"<<endl;
					break;
				}
				else if(arr[tx][ty]=='T')
				{
					cout<<"I get there!"<<endl;
					break;
				}
				//cout<<"i="<<i<<endl;
			}
			if(arr[tx][ty]=='.'||arr[tx][ty]=='S')	cout<<"I have no idea!"<<endl;
		}
	}
	return 0;
}