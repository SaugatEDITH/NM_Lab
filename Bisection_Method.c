#include<stdio.h>
#include<math.h>
// Define the cubic polynomial function
float f(float x){
    return (a3*x*x*x+a2*x*x+a1*x+a0);
}
int main(){
    float x1,xm,xu,fxl,fxm,fxu,E,Era; // Declare variables for lower, middle, and upper points, their function values, error, and relative error
    printf("Enter coefficients a3,a2,a1 and a0\n"); // Prompt the user to enter the coefficients of the polynomial
    scanf("%d%d%d%d",&a3,&a2,&a1,&a0); // Read the coefficients from the user
    printf("Enter initial bracket and E\n"); // Prompt the user to enter the initial interval [x1,xu] and the desired error E
    scanf("%f%f%f",&x1,&xu,&E); // Read the interval and error from the user
    fxl=f(x1); // Compute the function value at the lower point
    fxu=f(xu); // Compute the function value at the upper point
    while (1) // Start an infinite loop
    {
        fxl=f(x1); // Compute the function value at the lower point
        fxu=f(xu); // Compute the function value at the upper point
        xm=(x1+xu)/2; // Find the middle point of the interval
        fxm=f(xm); // Compute the function value at the middle point
        if((fxl*fxm)==0){ // Check if the lower or middle point is a root
            printf("Root= %f\n",xm); // Print the root
            break; // Exit the loop
        }
        else if ((fxl*fxm)<0) // Check if the root lies in the left subinterval
        {
            xu=xm; // Update the upper point to the middle point
        }
        else // Otherwise, the root lies in the right subinterval
            x1=xm; // Update the lower point to the middle point
        Era=(xu-x1)/xu; // Calculate the relative error
        if (Era<E) // Check if the relative error is less than the desired error
        {
            printf("Root= %f\n",xm); // Print the root
            break; // Exit the loop
        }
    }

    return 0; // End the program
}
