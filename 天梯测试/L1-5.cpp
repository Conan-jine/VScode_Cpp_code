#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string arr="I Love GPLT";
    int len=arr.size();
    for(int i=0;i<len;i++)  cout<<arr[i]<<endl;
    return 0;
}