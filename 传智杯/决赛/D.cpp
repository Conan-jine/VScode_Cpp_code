#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;

int n,m;
map<int, int> one,two,three;
int nowTerm;

int main()
{
    pair<int, int> nowSend;
    bool newTerm=true,onesend=false,twosend=false,threesend=false;
    map<int, int>::iterator it;
    int temp;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        one[temp]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        two[temp]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        three[temp]++;
    }
    nowTerm=1;
    while(!one.empty() && !two.empty() && !three.empty())
    {
        if(nowTerm==1 && newTerm)
        {
            it=one.begin();
            nowSend.first=(*it).first;
            nowSend.second=1;
            if( (*it).second==1 )   one.erase(it);
            else    (*it).second--;
            newTerm=false;
            nowTerm++;
        }
        else if(nowTerm==2 && newTerm)
        {
            it=two.begin();
            nowSend.first=(*it).first;
            nowSend.second=1;
            if( (*it).second==1 )   two.erase(it);
            else    (*it).second--;
            newTerm=false;
            nowTerm++;
        }
        else if(nowTerm==3 && newTerm)
        {
            it=three.begin();
            nowSend.first=(*it).first;
            nowSend.second=1;
            if( (*it).second==1 )   three.erase(it);
            else    (*it).second--;
            newTerm=false;
            nowTerm=1;
        }

        if(nowTerm==1)
        {
            if(onesend)
            {
                newTerm=true;
                onesend=false;
                continue;
            }
            for(it=one.begin();it!=one.begin();it++)
            {
                if( (*it).second>nowSend.second )
                {
                    nowSend.first=(*it).first;
                    (*it).second-=nowSend.second+1;
                    nowSend.second=nowSend.second+1;
                    if( (*it).second==0 )   one.erase(it);
                    onesend=true;
                    twosend=false;
                    threesend=false;
                    break;
                }
                else if( (*it).first>nowSend.first && (*it).second==nowSend.second)
                {
                    nowSend.first=(*it).first;
                    one.erase(it);
                    onesend=true;
                    twosend=false;
                    threesend=false;
                    break;
                }
            }
            nowTerm++;
        }
        if(nowTerm==2)
        {
            if(twosend)
            {
                newTerm=true;
                twosend=false;
                continue;
            }
            for(it=two.begin();it!=two.begin();it++)
            {
                if( (*it).second>nowSend.second )
                {
                    nowSend.first=(*it).first;
                    (*it).second-=nowSend.second+1;
                    nowSend.second=nowSend.second+1;
                    if( (*it).second==0 )   two.erase(it);
                    onesend=false;
                    twosend=true;
                    threesend=false;
                    break;
                }
                else if( (*it).first>nowSend.first && (*it).second==nowSend.second)
                {
                    nowSend.first=(*it).first;
                    two.erase(it);
                    onesend=false;
                    twosend=true;
                    threesend=false;
                    break;
                }
            }
            nowTerm++;
        }
        if(nowTerm==3)
        {
            if(threesend)
            {
                newTerm=true;
                threesend=false;
                continue;
            }
            for(it=three.begin();it!=three.begin();it++)
            {
                if( (*it).second>nowSend.second )
                {
                    nowSend.first=(*it).first;
                    (*it).second-=nowSend.second+1;
                    nowSend.second=nowSend.second+1;
                    if( (*it).second==0 )   three.erase(it);
                    onesend=false;
                    twosend=false;
                    threesend=true;
                    break;
                }
                else if( (*it).first>nowSend.first && (*it).second==nowSend.second)
                {
                    nowSend.first=(*it).first;
                    three.erase(it);
                    onesend=false;
                    twosend=false;
                    threesend=true;
                    break;
                }
            }
            nowTerm=1;
        }
    }
    if(one.empty()) cout<<1<<endl;
    else if(two.empty())    cout<<2<<endl;
    else if(three.empty())  cout<<3<<endl;
    return 0;
}