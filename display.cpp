#include <iostream>
#include <string>
using namespace std;

int main()
{
	//string arr0[5]={"XXX","X.X","X.X","X.X","XXX"};
	//string arr1[5]={"..X","..X","..X","..X","..X"};
	//string arr2[5]={"XXX","..X","XXX","X..","XXX"};
	//string arr3[5]={"XXX","..X","XXX","..X","XXX"};
	//string arr4[5]={"X.X","X.X","XXX","..X","..X"};
	//string arr5[5]={"XXX","X..","XXX","..X","XXX"};
	//string arr6[5]={"XXX","X..","XXX","X.X","XXX"};
	//string arr7[5]={"XXX","..X","..X","..X","..X"};
	//string arr8[5]={"XXX","X.X","XXX","X.X","XXX"};
	//string arr9[5]={"XXX","X.X","XXX","..X","XXX"};
	string arr[10][5]={{"XXX","X.X","X.X","X.X","XXX"},{"..X","..X","..X","..X","..X"},{"XXX","..X","XXX","X..","XXX"},{"XXX","..X","XXX","..X","XXX"},{"X.X","X.X","XXX","..X","..X"},
		{"XXX","X..","XXX","..X","XXX"},{"XXX","X..","XXX","X.X","XXX"},{"XXX","..X","..X","..X","..X"},{"XXX","X.X","XXX","X.X","XXX"},{"XXX","X.X","XXX","..X","XXX"}};
	char Arr[100];
	int n;
	cin>>n;
	cin>>Arr;
	int numarr[100];
	for(int i=0;i<n;i++)	numarr[i]=Arr[i]-'0';
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j!=0)	cout<<'.';
			cout<<arr[numarr[j]][i];
		}
		cout<<endl;
	}
	return 0;
}