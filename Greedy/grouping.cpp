#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;

int n;
int minLen=1000000000;
map<int, int> my_p;

int main()
{
    int len,num;
    cin>>n;
    while(n--)
    {
        cin>>num;
        my_p[num]++;
    }
    map<int, int>::iterator it,nextit;
    while(!my_p.empty())
    {
        len=1;
        it=my_p.begin();
        nextit=my_p.begin();
        (*it).second--;
        for(nextit++;nextit!=my_p.end() && (*it).first+1==(*nextit).first && (*it).second<(*nextit).second;it++,nextit++)
        {
            len++;
            (*nextit).second--;
        }
        it=my_p.begin();
        while(it!=my_p.end() && (*it).second==0)   my_p.erase((*it++).first);
        if(len<minLen)  minLen=len;
    }
    cout<<minLen<<endl;
    return 0;
}