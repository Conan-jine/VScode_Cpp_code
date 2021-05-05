#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;

int n;
map<int, int> arr;
map<int, int> temparr;

int main()
{
    int times,temp,loc,len;
    unsigned long long int sum=0;
    pair<int, int> rd;
    cin>>times;
    while(times--)
    {
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr[temp]++;
        }
        rd=*arr.begin();
        len=rd.second;
        for(int i=1;i<=len;i++)
        {
            temparr=arr;
            for(map<int, int>::iterator it=temp.begin(); it!=temp.end();)
            {
                rd=*it;
                if(rd.second)
            }
        }
    }
    return 0;
}