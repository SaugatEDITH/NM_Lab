#include<stdio.h>
int a0,a1,a2,a3;
float f(float x){
    return (a3*x*x*x+a2*x*x+a1*x+a0);
}
int main(){
    float x1,xm,xu,fxl,fxm,fxu,E,Era;
    printf("Enter coefficients a3,a2,a1 and a0\n");
    scanf("%d%d%d%d",&a3,&a2,&a1,&a0);
    printf("Enter initial bracket and E\n");
    scanf("%f%f%f",&x1,&xu,&E);
    fxl=f(x1);
    fxu=f(xu);
    while (1)
    {
        fxl=f(x1);
    fxu=f(xu);
    xm=(x1+xu)/2;
    fxm=f(xm);
    if((fxl*fxm)==0){
        printf("Root= %f\n",xm);
    }
    else if ((fxl*fxm)<0)
    {
        xu=xm;
    }
    else
        x1=xm;
    Era=(xu-x1)/xu;
    if (Era<E)
    {
        printf("Root= %f\n",xm);
        break;
    }
    }
    
    return 0;
}