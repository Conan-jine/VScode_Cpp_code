#include <iostream>
using namespace std;

int main()
{
    int number;
    cout<<"Please input the number: ";
    cin>>number;
    if(number==1)
    {
        cout<<"1 for Monday."<<endl;
    }
    else if(number==2)
    {
        cout<<"2 for Tuesday."<<endl;
    }
    else if(number==3)
    {
        cout<<"3 for Wednesday."<<endl;
    }
    else if(number==4)
    {
        cout<<"4 for Thursday."<<endl;
    }
    else if(number==5)
    {
        cout<<"5 for Friday."<<endl;
    }
    else if(number==6)
    {
        cout<<"6 for Saturday."<<endl;
    }
    else if(number==7)
    {
        cout<<"7 for Sundat."<<endl;
    }
    else
    {
        cout<<"Wrong number!"<<endl;
    }
    return 0;
}