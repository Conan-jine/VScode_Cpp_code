#include <iostream>
#include <string>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

int len;
stack<string> arr[55];

bool fun()
{
    string str1,str2;
    for(int i=1;i<len;i++)
    {
        str1=arr[i].top();
        if(i>2)
        {
            str2=arr[i-3].top();
            if(str2[0]==str1[0] || str2[1]==str1[1])
            {
                arr[i-3].push(str1);
                arr[i].pop();
                if(arr[i].empty())
                {
                    for(int j=i;j<len;j++)  arr[j]=arr[j+1];
                    len--;
                }
                return true;
            }
        }
        if(i>0)
        {
            str2=arr[i-1].top();
            if(str2[0]==str1[0] || str2[1]==str1[1])
            {
                arr[i-1].push(str1);
                arr[i].pop();
                if(arr[i].empty())
                {
                    for(int j=i;j<len;j++)  arr[j]=arr[j+1];
                    len--;
                }
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // freopen("data.out","w",stdout);
    string ch;
    while(1)
    {
        len=52;
        for(int i=0;i<52;i++)
        {
            cin>>ch;
            if(ch=="#") return 0;
            while(!arr[i].empty())  arr[i].pop();
            arr[i].push(ch); 
        }
        while(fun()){}
        if(len>1)   cout<<len<<" piles remaining:";
        else    cout<<len<<" pile remaining:";
        for(int i=0;i<len;i++)  cout<<" "<<arr[i].size();
        cout<<endl;
    }
}