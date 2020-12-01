#include <iostream>
using namespace std;

int main()
{
    char c;
    cout<<"Please input a letter: ";
    cin>>c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        cout<<"This is a vowel"<<endl;
    }
    else if(c=='y')
    {
        cout<<"This is sometimes a vowel"<<endl;
    }
    else if(c>='a' && c<='z')
    {
        cout<<"This is a consonant"<<endl;
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
    return 0;
}