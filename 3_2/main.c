#include <stdio.h>

double hermite(int n, double x);

int main() {
    int n;
    double x;
    printf("Value n=");
    scanf("%d",&n);
    printf("Value x=");
    scanf("%lf",&x);
    printf("%.2f",hermite(n,x));
    return 0;
}

double hermite(int n, double x)
{
    if(n==0)
        return 1;
    if(n==1)
        return 2*x;
    return 2*n*hermite((n-1),x)-2*(n-1)*hermite((n-2),x);
}
