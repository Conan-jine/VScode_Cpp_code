#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	printf("Hello World");
	// 等价于
	printf("%s","Hello World");

	int n=5;
	printf("%d",n);
	// %d 对应 整型n
	// %s 对应 字符串 Hello World

	int a=3,b=4;
	printf("%d %d",a,b);
	printf("***%d***%d***",a,b);
	// %d 会分别对应 右边的 a 和 b
	// 相当于你使用 %s 对应 I ate apple.
	// 你可以使用 %d 对应 苹果的数量，而 I ate apple 不用%s ，而是想 第18行那样，在*********里面加入%d
}