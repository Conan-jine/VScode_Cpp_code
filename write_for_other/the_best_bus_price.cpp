#include <iostream>
using namespace std;

int main()
{
    char c;
    int age,income;
    cout<<"Please input your age: ";
    cin>>age;
    cout<<"Please input your income: ";
    cin>>income;
    cout<<"Are you a City employee? (input Y or N) : ";
    cin>>c;

    // 输出用户的信息，以便用户自查
    cout<<"Age = "<<age<<endl;
    cout<<"Imcome = "<<income<<endl;
    if(c=='Y')  cout<<"You are a City employee."<<endl;
    else if(c=='N') cout<<"You are a General population."<<endl;

    // 判断最低价格
    if(age>=0 && age<=5)
    {
        cout<<"The best bus price for you is $0."<<endl;
    }
    else if(age>=18 && income<15000)
    {
        cout<<"The best bus price for you is $30."<<endl;
    }
    else if(c=='Y')
    {
        cout<<"The best bus price for you is $50."<<endl;
    }
    else if(age>=65 && income<30000)
    {
        cout<<"The best bus price for you is $70."<<endl;
    }
    else if(age>=6 && age<=17)
    {
        cout<<"The best bus price for you is $80."<<endl;
    }
    else
    {
        cout<<"The best bus price for you is $100."<<endl;
    }
}