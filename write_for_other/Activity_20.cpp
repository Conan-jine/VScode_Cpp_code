#include <iostream>
using namespace std;

struct Complex
{
    double real;
    double virt;
};

Complex add(Complex one, Complex tow);
Complex sub(Complex one, Complex two);
Complex mul(Complex one, Complex two);
Complex div(Complex one, Complex two);

int main()
{
    Complex a,b,c;
    cout<<"Please input the first Complex Number real-part and virtual-part: [example: 1 2]"<<endl;
    cin>>a.real>>a.virt;
    cout<<"Please input the second Complex Number real-part and virtual-part: [example: 1 2]"<<endl;
    cin>>b.real>>b.virt;
    cout<<"The first Complex Number is: "<<a.real;
    if(a.virt>0)    cout<<"+"<<a.virt<<'i'<<endl;
    else    cout<<a.virt<<'i'<<endl;
    cout<<"The second Complex Number is: "<<b.real;
    if(b.virt>0)    cout<<"+"<<b.virt<<'i'<<endl;
    else    cout<<b.virt<<'i'<<endl;
    
    c=add(a,b);
    cout<<"c=a+b=";
    if(c.virt>0)    cout<<c.real<<"+"<<c.virt<<'i'<<endl;
    else    cout<<c.real<<c.virt<<'i'<<endl;
    c=sub(a,b);
    cout<<"c=a-b=";
    if(c.virt>0)    cout<<c.real<<"+"<<c.virt<<'i'<<endl;
    else    cout<<c.real<<c.virt<<'i'<<endl;
    c=mul(a,b);
    cout<<"c=a*b=";
    if(c.virt>0)    cout<<c.real<<"+"<<c.virt<<'i'<<endl;
    else    cout<<c.real<<c.virt<<'i'<<endl;
    c=div(a,b);
    cout<<"c=a/b=";
    if(c.virt>0)    cout<<c.real<<"+"<<c.virt<<'i'<<endl;
    else    cout<<c.real<<c.virt<<'i'<<endl;
    return 0;
}

Complex add(Complex one, Complex two)
{
    Complex c;
    c.real=one.real+two.real;
    c.virt=one.virt+two.virt;
    return c;
}

Complex sub(Complex one, Complex two)
{
    Complex c;
    c.real=one.real-two.real;
    c.virt=one.virt-two.virt;
    return c;
}

Complex mul(Complex one, Complex two)
{
    Complex c;
    c.real=one.real*two.real-one.virt*two.virt;
    c.virt=one.virt*two.real+one.real*two.virt;
    return c;
}

Complex div(Complex one, Complex two)
{
    Complex c;
    c.real=(one.real*two.real+one.virt*two.virt)/(one.real+two.real);
    c.virt=(one.virt*two.real-one.real*two.virt)/(one.real+two.real);
    return c;
}