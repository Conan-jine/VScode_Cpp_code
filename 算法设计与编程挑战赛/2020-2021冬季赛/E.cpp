#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string arr;
long long cnt=0;
struct myV
{
    int weight;
    int numOf1;
    int numOf2;
    int sum;
};

int main()
{
    myV V={0};
    cin>>V.weight;
    cin>>arr;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]=='1' && V.sum<V.weight)
        {
            V.numOf1+=1;
            V.sum+=1;
        }
        else if(arr[i]=='1' && V.numOf2>0)
        {
            V.numOf1+=1;
            V.numOf2-=1;
            V.sum-=1;
        }
        else if(arr[i]=='2' && V.sum+2<=V.weight)
        {
            V.numOf2+=1;
            V.sum+=2;
        }
        cnt+=V.numOf1+V.numOf2;
    }
    cout<<cnt<<endl;
    return 0;
}