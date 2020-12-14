#include <stdio.h>

int main()
{
    int n,x,y,temp;//a[10]={0};
    int i,j,flag;
    scanf("%d",&n);
    for(x=12345;x<=98765;x++)
    {
        int a[10]={0};
        flag = 1;
        temp = x;

    //    if(x%n != 0)                    //不用这句数组a要重新全部初始化！
    //        continue;

        if(x%n== 0)                        //记录y的各个位
        {

            y = x/n;
            for(i=4;i>=0;i--)
            {
                a[i] = y%10;
                y = y/10;
            }
        }

        for(i=9;i>=5;i--)                //记录x的各个位
        {
            a[i] = temp%10;
            temp = temp/10;

        }

        for(i=0;i<9;i++)                //判断有没有重复的
        {
            for(j=i+1;j<=9;j++)
            {
                if(a[i] == a[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag ==0)
                break;
        }

        if(flag==1)                        //打印
        {
            for(i=5;i<=9;i++)
                printf("%d",a[i]);
            printf("/");
            for(i=0;i<5;i++)
                printf("%d",a[i]);
            printf("=%d\n",n);
        }
    }
    return 0;
}