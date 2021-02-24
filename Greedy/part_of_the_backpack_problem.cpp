#include <iostream>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct gold
{
    double weight;
    double value;
    double rate;
}arr[110];
double sumNeed;

bool cmp(gold a, gold b)
{
    return a.rate>b.rate;
}

int main()
{
    int n,space;
    cin>>n>>space;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].weight>>arr[i].value;
        arr[i].rate=arr[i].value/arr[i].weight;
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(space>=arr[i].weight)
        {
            space-=arr[i].weight;
            sumNeed+=arr[i].value;
        }
        else
        {
            sumNeed+=arr[i].rate*space;
            break;
        }
    }
    cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2)<<sumNeed<<endl;
    return 0;
}