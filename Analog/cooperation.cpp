#include <iostream>

int main()
{
    bool judge=true;
    int times=0,arr[27]={0};
    char str[25];
    str[0]='z';
    for(int i=1;i<26;i++)
    {
        std::cin>>str[i];
        arr[int(str[i]-'a')]++;
        if(str[i]>str[i-1]  && str[i-1]=='a') judge=false;
    }
    if(judge)   std::cout<<1<<std::endl;
    else
    {
        for(int i=26;i>=0;i--)
        {
            while(arr[i]!=0)
            {
                if(times!=0)    std::cout<<' ';
                std::cout<<char('a'+i);
                times++;
                if(times==5)
                {
                    times=0;
                    std::cout<<std::endl;
                }
                arr[i]--;
            }
        }
    }
    return 0;
}