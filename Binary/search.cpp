#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n;
struct my_arr
{
    int num=1000000000;
    int loc=1000001;
}arr[1000010];


int binary_search(int num)
{
    int left=0,right=n;
    int temp;
    while(right-left>=1)
    {
        temp=(left+right)/2;
        if(arr[temp].num==num)  return arr[temp].loc;
        else if(arr[temp].num>num)  right=temp;
        else    left=temp+1;
    }
    return -1;

}
int main()
{
    int t,num,cnt=1;
    cin>>n>>t;
    cin>>arr[0].num;
    arr[0].loc=1;
    for(int i=2;i<=n;i++)
    {
        cin>>num;
        if(arr[cnt-1].num!=num)
        {
            arr[cnt].num=num;
            arr[cnt].loc=i;
            cnt++;
        }
    }
    n=cnt;
    while(t--)
    {
        cin>>num;
        cout<<binary_search(num);
        if(t!=0)    cout<<' ';
    }
    return 0;
}