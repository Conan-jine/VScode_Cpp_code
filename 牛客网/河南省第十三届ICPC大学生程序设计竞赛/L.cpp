#include<stdio.h>
#include<math.h>
const double pi=acos(-1.0);//计算圆周率
double a1,b1,a2,b2;//a1,a2和b1,b2分别是两个椭圆的x轴和y轴
double solve(){
	if(a1<=a2)
		return pi*a1*b1;//椭圆B包含椭圆A
	if(b1>=b2)
		return pi*a2*b2;//椭圆A包含椭圆B
	double ans=0.0;//相交部分面积
	double x,y;//两椭圆在第一象限的交点坐标
	x=sqrt((b1*b1-b2*b2)*a1*a1*a2*a2/(b1*b1*a2*a2-b2*b2*a1*a1));
	y=sqrt((a1*a1-a2*a2)*b1*b1*b2*b2/(a1*a1*b2*b2-b1*b1*a2*a2));
	//下面计算相交部分面积
	double theta1=asin(y/b1),theta2=asin(y/b2);
	ans=a1*b1*((pi-2*theta1)+sin(2*theta1))+a2*b2*(2*theta2+sin(2*theta2))-4*x*y;
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);//读入数据
		printf("%.1lf\n",solve());//计算相交面积
	}
	return 0;
}