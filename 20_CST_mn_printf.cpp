#include <stdio.h>
// 输出printf("%x",16);
// 输出一个数的十六进制的小写形式
// 输出一个数的十六进制的大写形式
// 输出一个数的十进制的八位左对齐
// 输出一个数的十进制的八位右对齐
// 输出一个数的十六进制八位左对齐(a)
// 输出一个数的十六进制八位右对齐(A)
int main()
{
    int n;
    scanf("%d",&n);
    printf("printf(\"%%x\",16);\n");
    printf("%x\n",n);
    printf("%X\n",n);
    printf("%-8d\n",n);
    printf("%8d\n",n);
    printf("%-8x\n",n);
    printf("%8X\n",n);
    return 0;
}