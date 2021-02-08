#include <stdio.h>
#include <math.h>

int sumArr[100]={1};

void fun(int num)
{
    int i=1,j,len=0,arr[100]={1};
    // 判断num是几位数，并存储于len当中
    while(num>pow(10,i))    i++;
    len=i;
    // 将2~num分别与数（数组）相乘
    for(i=2;i<=num;i++)
    {
        // 将 i 分别与数组的每一位相乘
        for(j=0;j<len;j++)  arr[j]*=i;
        // 判断数组的每一位是否进位，即处理进位关系
        for(j=0;j<len;j++)
        {
            if(arr[j]>10)
            {
                arr[j+1]+=arr[j]/10;
                arr[j]%=10;
            }
        }
        // 判断该数字是否增加位数，使用while是为了保证数据的准确性
        while(arr[len]!=0)
        {
            arr[len+1]+=arr[len]/10;
            arr[len]%=10;
            len++;
        }
    }
    // 将num的阶乘累加到sumArr当中去
    for(int i=0;i<100;i++)
    {
        sumArr[i]+=arr[i];
        sumArr[i+1]+=sumArr[i]/10;
        sumArr[i]%=10;
    }
}

int main()
{
    int n,judge=0;
    scanf("%d",&n);
    // 分别计算每个数的阶乘并累加到sumArr数组当中去，sumArr为全局变量，好操作
    for(int i=2;i<=n;i++)   fun(i);
    // 判断最高位然后从最高位往‘前’持续打印
    for(int i=99;i>=0;i--)
    {
        if(sumArr[i]!=0)    judge=1;
        if(judge==1)    printf("%d",sumArr[i]);
    }
}
