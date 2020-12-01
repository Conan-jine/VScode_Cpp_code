#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int num;
    fstream file1,file2,file3;
    file1.open("numbers.txt",ios::in);
    file2.open("odd.txt",ios::out);
    file3.open("even.txt",ios::out);
    while(file1>>num)
    {
        if(num%2==0)
        {
            file3<<num<<endl;
        }
        else if(num%2==1)
        {
            file2<<num<<endl;
        }
    }
    return 0;
}