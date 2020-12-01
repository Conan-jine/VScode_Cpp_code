#include <iostream>
using namespace std;

void printSpace(int row);

int main()
{
    int i,j,num;
	int arr1[50]={0,1,0},arr2[50]={0};
    cout<<"Please input the number of rows: ";
    cin>>num;
	if(num>1)
	{
        printSpace(num);
        cout<<"1"<<endl;
		for(i=1;i<num;i++)
		{
            printSpace(num-i);
			for(j=1;j<=num;j++)	arr2[j]=arr1[j-1]+arr1[j];
			for(j=1;j<=i+1;j++)
			{
				if(i==num-1&&j==i+1)	cout<<arr2[j];
				else    cout<<arr2[j]<<' ';
			}
			for(j=0;j<i+3;j++)	arr1[j]=arr2[j];
			if(i<num-1)	cout<<endl;
		}
	}
	else    cout<<"1"<<endl;
    return 0;
}

void printSpace(int row)
{
    int rowSpace=row;
    for(int i=0;i<rowSpace;i++)
    {
        cout<<' ';
    }
}