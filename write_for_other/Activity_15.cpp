#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int n,*p,num;
    cout<<"Please input length of numbers: ";
    cin>>n;
    cout<<"Please input numbers: "<<endl;
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<"Please input the number you want to search: ";
    cin>>num;
    p=&num;
    for(int i=0;i<n;i++)
    {
        if(*p==arr[i])
        {
            cout<<"Number exist."<<endl;
            return 0;
        }
    }
    cout<<"Number doesn't exist!"<<endl;
    return 0;
}