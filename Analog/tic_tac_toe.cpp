#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int judge(char **arr)
{
    int Xsum=0,Osum=0;
    if(arr[0][0]==arr[0][1] && arr[0][2]==arr[0][1] && arr[0][0]!='.')
    {
        if(arr[0][0]=='X')  Xsum++;
        if(arr[0][0]=='O')  Osum++;
    }
    if(arr[1][0]==arr[1][1] && arr[1][2]==arr[1][1] && arr[0][0]!='.')
    {
        if(arr[1][0]=='X')  Xsum++;
        if(arr[1][0]=='O')  Osum++;
    }
    if(arr[2][0]==arr[2][1] && arr[2][2]==arr[2][1] && arr[0][0]!='.')
    {
        if(arr[2][0]=='X')  Xsum++;
        if(arr[2][0]=='O')  Osum++;
    }

    if(arr[0][0]==arr[1][0] && arr[1][0]==arr[2][0] && arr[0][0]!='.')
    {
        if(arr[0][0]=='X')  Xsum++;
        if(arr[0][0]=='O')  Osum++;
    }
    if(arr[0][1]==arr[1][1] && arr[1][1]==arr[2][1] && arr[0][0]!='.')
    {
        if(arr[0][1]=='X')  Xsum++;
        if(arr[0][1]=='O')  Osum++;
    }
    if(arr[0][2]==arr[1][2] && arr[1][2]==arr[2][2] && arr[0][0]!='.')
    {
        if(arr[0][2]=='X')  Xsum++;
        if(arr[0][2]=='O')  Osum++;
    }

    if(arr[0][0]==arr[1][1] && arr[2][2]==arr[1][1] && arr[0][0]!='.' || arr[0][2]==arr[1][1] && arr[2][0]==arr[1][1] && arr[0][0]!='.')
    {
        if(arr[1][1]=='X')  Xsum++;
        if(arr[1][1]=='O')  Osum++;
    }
    if(Xsum!=0 && Osum!=0)  return -1;
    if(Xsum==Osum)  return -2;
    if(Xsum==0) return 0;
    if(Osum==0) return 1;
}

int main()
{
    int n,O=0,X=0;
    char **arr=new char *[4];
    for(int i=0;i<4;i++)    arr[i]=new char [4];
    cin>>n;
    while(n--)
    {
        O=0;
        X=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='X')  X++;
                else if(arr[i][j]=='O') O++;
            }
        }
        if(O>X || X-O>1 )
        {
            cout<<"no"<<endl;
            continue;
        }
        else if(judge(arr)==0 && X!=O)
        {
            cout<<"no"<<endl;
            continue;
        }
        else if(judge(arr)==1 && O==X)
        {
            cout<<"no"<<endl;
            continue;
        }
        else if(judge(arr)==-1)
        {
            cout<<"no"<<endl;
            continue;
        }
        else
        {
            cout<<"yes"<<endl;
            continue;
        }
    }
}