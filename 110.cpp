#include<stdio.h>
#include<math.h>
int Huiwen(int n)//回文数 
{
	int t;
	int sum = 0;
	t = n;
	while (n) {
		sum = sum * 10 + n % 10;//数据逆转 
		n /= 10;
	}
	if (t == sum) {
		return 1;
	}
	else return 0; 
}
int prime(int n){
    if(n == 2|| n == 3) return 1;
    if(n % 6 != 1 && n % 6 != 5) return 0;
    int temp = sqrt(n);
    for(int i = 5;i <= temp; i += 6){
		if(n % i == 0 || n % (i+2) == 0 ) return 0;
	}
    return 1;
}
int main()
{
	int a, b, i; 
	scanf("%d%d", &a, &b);
	for(i = a; i <= b; i++)
	{
		if (Huiwen(i)) {
			if(prime(i)) {
			printf("%d\n",i);
			}
		}
	}
	return 0;
 }
