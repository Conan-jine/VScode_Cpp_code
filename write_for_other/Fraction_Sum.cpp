#include <iostream>
using namespace std;

struct Fraction
{
    int molecule;
    int denominator;
};

void multiply(Fraction a, Fraction b);

int main()
{
    Fraction one,two;
    cout<<"Please input the first fraction's molecule: ";
    cin>>one.molecule;
    cout<<"Please input the first fraction's denominator: ";
    cin>>one.denominator;
    cout<<"Please input the second fraction's molecule: ";
    cin>>two.molecule;
    cout<<"Please input the second fraction's denominator: ";
    cin>>two.denominator;
    multiply(one,two);
    return 0;
}

void multiply(Fraction a, Fraction b)
{
    int up,down;
    cout<<"The results is:"<<endl;
    up=a.molecule*b.molecule;
    down=a.denominator*b.denominator;
    cout<<"\t"<<up<<'/'<<down<<endl;
}