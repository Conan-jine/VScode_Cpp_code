#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int maxNum=0;
int num[250];
bool judge=false;

int main()
{
    int n,numbers;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>numbers;
        num[numbers]++;
        if(numbers>maxNum)  maxNum=numbers;
    }
    for(int i=1;i<=maxNum;i++)
    {
        if(num[i]==0)
        {
            judge=true;
            cout<<i<<endl;
        }
    }
    if(!judge)  cout<<"good job"<<endl;
    return 0;
}