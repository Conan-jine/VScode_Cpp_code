#include <iostream>
#include <cmath>
using namespace std;

void print(double a,double b,double c);
void count(double a,double b,double c);

int main()
{
    double a,b,c;
    cout<<"Please input the a,b,c of the equation:"<<endl;
    // cout<<"请输入方程的a，b，c："<<endl;
    cout<<"\ta = ";
    cin>>a;
    cout<<"\tb = ";
    cin>>b;
    cout<<"\tc = ";
    cin>>c;
    cout<<"Yours input is:"<<endl;
    // cout<<"你的输入是："<<endl;
    print(a,b,c);
    count(a,b,c);
    return 0;
}

void print(double a,double b,double c)
{
    cout<<'\t';
    if(a!=0)
    {
        if(a==1)    cout<<"x^2";
        else    cout<<a<<"x^2";
    }
    if(b!=0)
    {
        if(b==1)    cout<<"+x";
        else if(b==-1)  cout<<"-x";
        else if(b>0)    cout<<"+"<<b<<"x";
        else if(b<0)    cout<<b<<"x";
    }
    if(c!=0)
    {
        if(c>0) cout<<"+";
        cout<<c;
    }
    cout<<"=0"<<endl;
}

void count(double a,double b,double c)
{
    double dierta,r,r1,r2;
    dierta=b*b-4*a*c;
    if(dierta<0)    cout<<"Equation has no root."<<endl;    // cout<<"等式没有根"<<endl;
    else if(dierta==0)
    {
        r=-b/(2.0*a);
        cout<<"Equation has one root:"<<endl;   // cout<<"等式具有1个根"<<endl;
        cout<<"\tr = "<<r<<endl;
    }
    else if(dierta>0)
    {
        r1=(-b+sqrt(dierta))/(2.0*a);
        r2=(-b-sqrt(dierta))/(2.0*a);
        cout<<"Equation has two roots:"<<endl;  // cout<<"等式具有2个根"<<endl;
        cout<<"\tr1 = "<<r1<<endl;
        cout<<"\tr2 = "<<r2<<endl;
    }
}