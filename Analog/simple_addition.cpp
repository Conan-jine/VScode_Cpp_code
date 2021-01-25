#include <stdio.h>

int p, q;

long long Sum(long long s, long long e)
{
    if (s > e)  return 0;
    return (s + e) * (e - s + 1) / 2;
}
long long cal(long long n)
{
    if (n <= 0) return 0;
    long long ans = 0;
    while (n)
    {
        ans += n / 10 * 45;
        ans += Sum(1, n % 10);
        n /= 10;
    }
    return ans;
}

int main()
{
    while (~scanf("%d%d", &p, &q) && p != -1 && q != -1)
    {
	    printf("%lld\n", cal(q) - cal(p - 1));
    }
    return 0;
}