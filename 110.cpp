#include<stdio.h>
int main()
{
	int n,x,s=0;
	scanf("%d%d",&x,&n);
	for(x=0;x<=n;x++)
	{
		if((x%7>=1)&&(x%7<=5))
		{
			s+=250;
		}
		else
		{
			s=s;
		}
	 } 
	printf("%d",s);
	return 0;
}