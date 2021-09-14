//Mauricio Fortune Panizo
//COP3223C
// 11 Feb, 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function that makes the calculation of ax^2+bx+c
void evaluation_equation(double a, double b, double c, double i)
{
    //Get the values of the equation and print them
    printf("When X = %0.9lf         Y = %0.9lf\n", i, ((a*i*i)+(b*i)+c));

    //Void functions must return something
    return;
}
//Function for the loops to find answers for the values of x
void evaluate_points(double a, double b, double c)
{
    //State the variable i
    double i;

    //Tell them what we're evaluating

    printf("Evaluating the function with X going from 0.0 to 10.0\n");

    //The loop when i is 0.0 to 10.0
    for(i=0.0;i <= 10.0;i=i+1){

        //Call the evaluation equation
evaluation_equation(a,b,c,i);
    }

    //Get some space to make it look right
    printf("\n\n\n");

    //Tell them what we're evaluating
    printf("Evaluating the function with X going from 1.0 to 0.00000001\n");

    //The loop when i is 1 to 0.000000001
    for(i=1.0; i >= 0.000000001; i=i/10){

        //Call the evaluation equation
        evaluation_equation(a,b,c,i);
    }

    //Get some spacing to make it look better
    printf("\n\n\n");

    //Tell them what we're evaluating
    printf("Evaluating the function with X going from 1.0 to 10000000000.0\n");

    //The loop when i is 1 to 10000000000.0
    for(i=1.0; i <= 10000000000.0; i=i*10){

        //Call the evaluation equation
        evaluation_equation(a,b,c,i);
    }

    //Get some spacing to make it look better
    printf("\n\n\n");

    //Tell them what we're evaluating
    printf("Evaluating the function with X going from -10.0 to 10.0\n");

    //The loop when i is -10.0 to 10.0
    for(i=-10.0; i <= 10.0; i++){

        //Call the evaluation equation
        evaluation_equation(a,b,c,i);
    }

    //Void functions must return something
    return;
}


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
        printf("\n\n\n");
    //If the discriminant is less than zero
    }else if (discriminant(a,b,c) < 0)
    {
       //Print the answer giving the real values first and then add the imaginary values adding an i to the end.
       printf("x1 is: %f + %fi\n", (-b/2*a), (sqrt(fabs(discriminant(a,b,c))))/(2*a));
       printf("x2 is: %f - %fi\n", (-b/2*a), (sqrt(fabs(discriminant(a,b,c))))/(2*a));
        printf("\n\n\n");
    //If the discriminant is greater than zero
    } else if (discriminant(a,b,c) > 0)
    {
        // Find the x1 and the x2 values
        x1 = ((b + (sqrt(discriminant(a,b,c))))/(2*a));
        x2 = ((b - (sqrt(discriminant(a,b,c))))/(2*a));
        //Print the x1 and x2 values
        printf("Your x values are: %f, %f", x1, x2);
        printf("\n\n\n");
    }
    return;
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

    //Lets find the values of Y with the given X values
    evaluate_points(a, b, c);

    return 0;
}
