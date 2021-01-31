#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int sum=0;
    double a,b,c,x,y,z;
    cin>>a>>b>>c;
    bool judge=false,mark[10]={0};
    for(double i=123;i<333;i++)
    {
        judge=false;
        for(int j=1;j<10;j++)   mark[j]=false;
        for(int j=i;j!=0 && j<987;j/=10) mark[j%10]=true;
        for(int j=i*b/a;j!=0 && j<987;j/=10) mark[j%10]=true;
        for(int j=i*c/a;j!=0 && j<987;j/=10) mark[j%10]=true;
        for(int j=1;j<10;j++)
        {
            if(mark[j]==false)
            {
                judge=true;
                break;
            }
        }
        if(judge)   continue;
        sum++;
        cout<<int(i)<<' '<<int(i*b/a)<<' '<<int(i*c/a)<<endl;
    }
    if(sum==0)  cout<<"No!!!"<<endl;
}