#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int i,j,len,t;
string arr,temp;

// 判断是否首位
// 判断是否大写
// 判断是否唯一
// 判断是否结束判断

bool isHead(int loc)
{
    if(loc==0)    return true;
    else if(arr[loc-1]==' ' || arr[loc-1]==',' || 
    arr[loc-1]=='.' || arr[loc-1]=='!' || arr[loc-1]=='?')  return true;
    else    return false;
}

bool isBig(int loc)
{
    if(arr[loc]>='A' && arr[loc]<='Z')  return true;
    else    return false;
}

bool isOnly(int loc)
{
    int k;
    for(k=loc+1;arr[k]<='z' && arr[k]>='a';k++)
    {
        if(arr[k]>='A' && arr[k]<='Z')  return false;
        if(arr[k+1]>='A' && arr[k+1]<='Z')  return false;
    }
    t=k-1;
    return true;
}

bool isEnd(int loc)
{
    if(arr[loc]==',' || arr[loc]=='.' || arr[loc]=='!' || arr[loc]=='?')    return true;
    else    return false;
}

int main()
{
    freopen("data.out","w",stdout);
    bool judge=false;
    while(getline(cin,arr))
    {
        len=arr.size();
        for(i=0;i<len;i++)
        {
            // 扫描字符串
            if(arr[i]>='A' && arr[i]<='Z')
            {
                temp.assign("");
                for(j=i;j<len;j++)
                {
                    if(arr[j]==' ') continue;
                    if(isEnd(j))    break;
                    if(isHead(j) && isBig(j) && isOnly(j))
                    {
                        temp+=arr[j];
                        j=t;
                    }
                    else    break;
                }
                if(temp.size()>1)
                {
                    cout<<temp<<" (";
                    for(int k=i;k<t;k++)    cout<<arr[k];
                    cout<<")";
                    continue;
                }
            }
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}