#include <iostream>
using namespace std;

int main()
{
    char *arr;
    int lenOfArr;
    cout<<"Please input the length of string: ";
    cin>>lenOfArr;
    arr=new char [lenOfArr];
    cout<<"Please input the string: ";
    cin>>arr;
    // 主要涉及 ASCII码 的内容
    if(arr[0]>='a' && arr[0]<='z')   arr[0]-=32;
    if(arr[lenOfArr-1]>='a' && arr[lenOfArr-1]<='z')    arr[lenOfArr-1]-=32;
    cout<<"After change : "<<arr<<endl;
    delete [] arr;
    return 0;
}