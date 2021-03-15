#include <stdio.h>
/***********************************
观察题目样例给出的高为5层的塔，可以得出以下几个规律
对于一个高为n层的塔而言，首先设最上面一层（顶层）为第一层。
1. 对于第i层而言，其字符的排列规律为：大写字母表中从第1个字符(A)~第i个字符，后又倒序从第i-1个字符~第1个字符(A)。
2. 第1~n-1层每层前都有空格，具体而言，对于第i行，字符前面的空格个数为n-i个。
找出以上规律后，我们就可以根据这些规律构造出答案：层高26的塔。

TIPS:
大写字母'A'为大写字母表第一个字符
对于大写字母表中第i个字符，可以使用'A'+i-1得到。
例如：第5个字符为'E'，亦即为：'A'+5-1
***********************************/
int main() 
{
    char c1;
    int n = 26; //设定塔的层数为26
    int i, j;
    for (i = 1; i <= n; i++) {   //对塔每一层按照规律进行构造。
        //首先进行输出空格的操作：对于第i行，字符前面的空格个数为n-i个。
        for (j = 1; j <= n-i; j++)
            printf(" ");
        for (j = 1; j <= i; j++) { //按照规律1，输出第1~第i个大写字母。
            c1 = j + 'A' - 1; //第j个大写字母为'A'+j-1
            printf("%c", c1); //输出第j个大写字母
        }
        for (j = i-1; j >= 1; j--) {//按照规律1，输出第i-1~第1个大写字母，注意是倒序
            c1 = j + 'A' - 1;
            printf("%c", c1);
        }
        printf("\n");//第i行输出结束，进行换行。
    }
    return 0;
}

