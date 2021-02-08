#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string fun()
{
    string str="",temp;
    int num;
    char c;
    while(cin>>c)
    {
        if(c=='[')
        {
            cin>>num;
            temp=fun();
            for(int i=0;i<num;i++)  str+=temp;
        }
        else if(c==']') break;
        else    str+=c;
    }
    return str;
}

int main()
{
    // freopen("data.out","w",stdout);
    cout<<fun();
    return 0;
}