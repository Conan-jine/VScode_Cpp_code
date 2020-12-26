#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;

struct pt
{
    double x,y,z;
}arr[50010];

double fun(pt p1, pt p2)
{
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)+pow(p1.z-p2.z,2));
}

bool cmp(pt p1, pt p2)
{
    return p1.z<p2.z;
}

int main()
{
    int n;
    cin>>n;
    double sum=0;
    for(int i=0;i<n;i++)    scanf("%lf%lf%lf",&arr[i].x,&arr[i].y,&arr[i].z);
    sort(arr,arr+n,cmp);
    for(int i=0;i<n-1;i++)  sum+=fun(arr[i],arr[i+1]);
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl;
}