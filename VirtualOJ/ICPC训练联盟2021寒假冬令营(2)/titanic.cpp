#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
/*
    未解待续 Conan-jine
*/
using namespace std;
 
double dist( double l1, double d1, double l2, double d2 )
{
	double r = 6875.0/2;
	double p = acos(-1.0);
	
	l1 *= p/180;d1 *= p/180;
	l2 *= p/180;d2 *= p/180;
	
	return r*acos(cos(l1)*cos(l2)*cos(d1-d2)+sin(l1)*sin(l2));
}
 
int main()
{
	char   temp[100];
	double d,m,s,l1,l2,d1,d2,dis;
	
	for ( int i = 0 ; i < 9 ; ++ i ) scanf("%s",temp);
	scanf("%lf^%lf'%lf\" %s",&d,&m,&s,temp);
	l1 = d+m/60+s/3600;
	if ( temp[0] == 'S' ) l1 *= -1;
	
	scanf("%s",temp);
	scanf("%lf^%lf'%lf\" %s.",&d,&m,&s,temp);
	d1 = d+m/60+s/3600;
	if ( temp[0] == 'W' ) d1 *= -1;
	
	for ( int i = 0 ; i < 5 ; ++ i ) scanf("%s",temp);
	scanf("%lf^%lf'%lf\" %s",&d,&m,&s,temp);
	l2 = d+m/60+s/3600;
	if ( temp[0] == 'S' ) l2 *= -1;
	
	scanf("%s",temp);
	scanf("%lf^%lf'%lf\" %s.",&d,&m,&s,temp);
	d2 = d+m/60+s/3600;
	if ( temp[0] == 'W' ) d2 *= -1;
	
	scanf("%s",temp);	
	dis = dist(l1,d1,l2,d2);
	printf("The distance to the iceberg: %.2lf miles.\n",dis);
	if ( floor(dis+0.005) < 100 ) printf("DANGER!\n");
	return 0;
}