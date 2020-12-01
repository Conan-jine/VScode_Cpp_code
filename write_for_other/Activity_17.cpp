#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // 提供测试文件 test.txt
    double num;
    string row,filename,order;
    fstream file;
    cout<<"Please input file's name to open the file: ";
    cin>>filename;
    file.open(filename,ios::in|ios::out);
    if(file.is_open())  cout<<"Open file successful."<<endl;
    else
    {
        cout<<"Open failed."<<endl;
        return 0;
    }
    cout<<"Please type 'print' or 'double' :[print/double]"<<endl;
    cin>>order;
    if(order=="print")
    {
        while(getline(file,row))
        {
            cout<<row<<endl;
        }
    }
    else if(order=="double")
    {
        while(file>>num)
        {
            cout<<num*num<<endl;
        }
    }
    file.close();
    return 0;
}