#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int arr[5]={4,3,2,1};
    std::reverse(arr+1,arr+3);
    for(int i=0;i<5;i++)    cout<<arr[i]<<' ';
    return 0;
}
