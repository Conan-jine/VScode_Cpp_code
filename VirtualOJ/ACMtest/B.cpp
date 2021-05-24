#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int leftbook[200010];
int rightbook[200010];
int times;

int main()
{
    char c;
    int i,id,minlen;
    int leftlen=0,rightlen=0;
    int nowleft=0,nowright=0;
    bool find=false;
    cin>>times;
    while(times--)
    {
        cin>>c>>id;
        if(c=='L')
        {
            leftbook[nowleft++]=id;
            leftlen++;
        }
        else if(c=='R')
        {
            rightbook[nowright++]=id;
            rightlen++;
        }
        else if(c=='?')
        {
            find=false;
            minlen=leftlen<rightlen? leftlen:rightlen;
            for(i=0;i<=minlen;i++)
            {
                if(leftbook[nowleft-i]==id)
                {
                    cout<<i-1<<endl;
                    find=true;
                    break;
                }
                else if(rightbook[nowright-i]==id)
                {
                    cout<<i-1<<endl;
                    find=true;
                    break;
                }
            }
            if(!find && minlen==leftlen && leftlen!=rightlen)
            {
                for(;i<=rightlen;i++)
                {
                    if(rightbook[nowright-i]==id)
                    {
                        cout<<i-1<<endl;
                        break;
                    }
                }
            }
            else if(!find && minlen==rightlen && leftlen!=rightlen)
            {
                for(;i<=leftlen;i++)
                {
                    if(leftbook[nowleft-i]==id)
                    {
                        cout<<i-1<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}