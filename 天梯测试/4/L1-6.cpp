#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool judge(char c)
{
    if( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || c=='.')  return true;
    else    return false;
}

int main()
{
    // freopen("data.out","w",stdout);
    int n,len;
    bool rLen,rRule,rNum,rChar;
    string str;
    cin>>n;
    getchar();
    while(n--)
    {
        // cin>>str;
        
        getline(cin,str);
        rLen=rRule=true;
        rNum=rChar=false;
        if(str.size()<6)    rLen=false;
        len=str.size();
        for(int i=0;i<len;i++)
        {
            if(!judge(str[i]))
            {
                rRule=false;
                break;
            }
        }
        for(int i=0;i<len;i++)
        {
            if( (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) rChar=true;
            if(str[i]>='0' && str[i]<='9')  rNum=true;
        }

        if(rLen && rRule && rNum && rChar)  cout<<"Your password is wan mei."<<endl;
        else if(!rLen)  cout<<"Your password is tai duan le."<<endl;
        else if(!rRule) cout<<"Your password is tai luan le."<<endl;
        else if(!rNum && rChar)  cout<<"Your password needs shu zi."<<endl;
        else if(!rChar && rNum) cout<<"Your password needs zi mu."<<endl;
    }
    return 0;
}