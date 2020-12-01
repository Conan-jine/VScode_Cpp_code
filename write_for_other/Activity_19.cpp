#include <iostream>
using namespace std;

// Fibonacci Numbers is 1 1 2 3 5 8 13 21 34 55 89 ......
int Fibonacci(int n)
{
    if(n==1||n==0)  return 1;
    else return Fibonacci(n-1)+Fibonacci(n-2);
}

int main()
{
    int n;
    cout<<"Please input the location of Fibonacci Numbers: ";
    cin>>n;
    cout<<"Result is: "<<Fibonacci(n-1)<<endl;
    return 0;
}