//Mauricio Fortune Panizo
//COP3223C
//29 Jan, 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Let's find the discriminant
double discriminant(double a, double b, double c)
{
    //return the discriminant
    return (b*b-4*a*c);
}

//Put the answer together
void answer(float a, float b, float c)
{
    //define the variables
    float x1, x2;

    //if the discriminant is zero
    if (discriminant(a,b,c) == 0)
    {
        //Get the calculation of what isn't under the square root
        x1 = (-(b)/(2*a));
        //Print the "x" value
        printf("Your x value is: %f", x1);

    //If the discriminant is less than zero
    }else if (discriminant(a,b,c) < 0)
    {
       //Print the answer giving the real values first and then add the imaginary values adding an i to the end.
       printf("x1 is: %f + %fi\n", (-b/2*a), (sqrt(abs(discriminant(a,b,c))))/(2*a));
       printf("x2 is: %f - %fi\n", (-b/2*a), (sqrt(abs(discriminant(a,b,c))))/(2*a));

    //If the discriminant is greater than zero
    } else if (discriminant(a,b,c) > 0)
    {
        // Find the x1 and the x2 values
        x1 = ((-b + (sqrt(discriminant(a,b,c))))/(2*a));
        x2 = ((-b - (sqrt(discriminant(a,b,c))))/(2*a));
        //Print the x1 and x2 values
        printf("Your x values are: %f, %f", x1, x2);
    }
}

//function to check if a is negative or not
void check_num_a(float a, float b, float c)
{
    //If a is not zero, we can solve
    if (a != 0.0)
    {
        //Go to the function that finds the answer since a is not zero
        answer(a, b, c);
    //If it is zero print the error function
    } else {
        //print the error function
        printf("Sorry, there was an error with your inserted values. Make sure the 'a' value is greater than 0.\n");
    }
    //A void function needs a return so this is here
    return;
}

int main()
{
    //define the variables
    float a, b, c;
    //Get the value of a
    printf("What is your a value?\n");
    scanf("%f", &a);
    //Get the value of b
    printf("What is your b value?\n");
    scanf("%f", &b);
    //Get the value of c
    printf("What is your c value?\n");
    scanf("%f", &c);
    //Call the function to find if a is 0 or not
    check_num_a(a, b, c);
    return 0;
}
