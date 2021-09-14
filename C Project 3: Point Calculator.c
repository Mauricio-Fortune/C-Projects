//Mauricio Fortune Panizo
//COP 3223C
//3 March 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Calculate the y value
double y_value_calculator(double x_array_value, float a, float b, float c){

    //Calculate it through y=ax^2+bx+c
    return ((a)*(x_array_value*x_array_value))+((b)*(x_array_value))+c;
}

//Function that gets the y value
double y_array_inputter(double x_array_value, float a, float b, float c){

    //Declare the y value
    double y;

    //Get the y value by calling the function that calculates it
    y = y_value_calculator(x_array_value, a, b, c);

    //Return the y value to the function that called it
    return y;

}

//Creates the x array, y array, and prints both
void first_x_array_creator(double *first_x_array, double *first_y_array, float a, float b, float c) {

    //declare the i value
    int i;

    //Declare the value that the array is starting at
    float x_value = 0.0;

    //Loop that inputs values into the x array
    for(i=0; i<=10; i++){

        //As i increases, the x value also changes
        first_x_array[i]= x_value;

        //Add one to the x value, this is the step variable
        x_value++;
    }

    //Loop that calls the y=ax^2+bx+c function and gets its values from it
    for(i=0; i<=10; i++){

        //call the y array function and input the outcome into the y array
        first_y_array[i]= y_array_inputter(first_x_array[i], a, b, c);
    }

    //Print out the output
    for(i=0; i<=10; i++){
        printf("The X value is: %0.9lf          The Y value is: %0.9lf\n", first_x_array[i], first_y_array[i]);
    }
    //Spacing
    printf("\n\n\n");


    return;
}

//Creates the x array, y array, and prints both
void second_x_array_creator(double *second_x_array, double *second_y_array, float a, float b, float c) {

    //declare i
    int i;

    //declare the starting value
    float x_value = 1.0;

    //Loop that inputs values into the x array
    for(i=0; i<=8; i++){

        //As i increases, the x value also changes
        second_x_array[i]= x_value;

        //Step variable, divide by 10
        x_value = (x_value/10);
    }

    //Loop that calls the y=ax^2+bx+c function and gets its values from it
    for(i=0; i<=8; i++){

        //call the function and whatever it returns is that value of that spot in the y_array
        second_y_array[i]= y_array_inputter(second_x_array[i], a, b, c);
    }

    //Print out the output
    for(i=0; i<=8; i++){
        printf("The X value is: %0.9lf          The Y value is: %0.9lf\n", second_x_array[i], second_y_array[i]);
    }

    //Spacing
    printf("\n\n\n");


    return;
}

//Creates the x array, y array, and prints both
void third_x_array_creator(double *third_x_array, double *third_y_array, float a, float b, float c){

    //declare i
    int i;

    //declare the starting value
    float x_value = 1.0;

    //Loop that inputs values into the x array
    for(i=0; i<=9; i++){

        //input the x value into array
        third_x_array[i]= x_value;

        //increase the x value by multiplying by 10, this is the step variable
        x_value = (x_value*10);
    }

    //Loop that calls the y=ax^2+bx+c function and gets its values from it
    for(i=0; i<=9; i++){

        //call the function and whatever it returns is that value of that spot in the y_array
        third_y_array[i]= y_array_inputter(third_x_array[i], a, b, c);
    }

    //Print out the values
    for(i=0; i<=9; i++){
        printf("The X value is: %0.9lf          The Y value is: %0.9lf\n", third_x_array[i], third_y_array[i]);
    }

    //Spacing
    printf("\n\n\n");

    return;
}

//Creates the x array, y array, and prints both
void last_x_array_creator(double *fourth_x_array, double *fourth_y_array, float a, float b, float c) {

    //Declare the i variable
    int i;

    //Declare the starting variable for the array
    float x_value = -10.0;

    //Loop that inputs the values into the x array
    for(i=0; i<=20; i++){

        //Input the x_value into the array
        fourth_x_array[i]= x_value;

        //Step variable, add one each time
        x_value = (x_value+1.0);
    }

    //Loop that calls the y=ax^2+bx+c function and gets its values from it
    for(i=0; i<=20; i++){

        //call the function and whatever it returns is that value of that spot in the y_array
        fourth_y_array[i]= y_array_inputter(fourth_x_array[i], a, b, c);
    }

    //print it out
    for(i=0; i<=20; i++){
        printf("The X value is: %0.9lf          The Y value is: %0.9lf\n", fourth_x_array[i], fourth_y_array[i]);
    }

    //Spacing
    printf("\n\n\n");

    return;
}


int main(){

    //define the variables
    float a, b, c;

    //define the arrays in their pairs
    double first_x_array[11];
    double first_y_array[11];

    double second_x_array[9];
    double second_y_array[9];

    double third_x_array[10];
    double third_y_array[10];

    double last_x_array[21];
    double last_y_array[21];

    //Get the value of a
    printf("What is your 'a' value?\n");
    scanf("%f", &a);

    //Get the value of b
    printf("What is your 'b' value?\n");
    scanf("%f", &b);

    //Get the value of c
    printf("What is your 'c' value?\n");
    scanf("%f", &c);

    //This creates and prints the first x and y arrays
    first_x_array_creator(first_x_array, first_y_array, a, b, c);

    //This creates and prints the second x and y arrays
    second_x_array_creator(second_x_array, second_y_array, a, b, c);

    //This creates and prints the third x and y arrays
    third_x_array_creator(third_x_array,third_y_array, a, b, c);

    //This creates and prints the fourth(last) x and y arrays
    last_x_array_creator(last_x_array, last_y_array, a, b, c);

    return 0;

}
