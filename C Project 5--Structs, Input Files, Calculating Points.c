//Mauricio Fortune Panizo
//COP 3223C
//11 April, 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//Create our Structure
struct point_struct
{
    double m;
    double b;
    int count;
    double *x;
    double *y;
};

//So that we can call it point instead of the long struct point_struct name
typedef struct point_struct point;


//Free our malloced arrays
void dispose_point(point* my_point)
{
    free(my_point);
}


//Print out function
void print_function(FILE *ofp, char *title, point* my_point, double x1, double y1, double x2, double y2)
{

    //create i and make it 0
    int i = 0;

    //Print out that title
    fprintf(ofp, "%s", title);

    //Print out the initial x and y values and the second x and y values
    fprintf(ofp, "The line across (%lf, %lf) and (%lf, %lf) has a slope of %f and intercept of %f\n", x1, y1, x2, y2, my_point->m, my_point->b);

    //Now lets print out the values from the x and y array
    for (i=0; i< my_point->count; i++){

        //Make sure they're in line
        fprintf(ofp, "  For x=  %15.8lf,   y=    %15.8lf\n", my_point-> x[i], my_point-> y[i]);

    }
    //Back to main we go!
    return;

}

//Fill the malloced y-array
void fill_y_array(point* my_point){

    //for loop to get to all of the y-values in the array
    for(int i=0; i < my_point->count; i++){

        //Use the formula to fill the y-array
        my_point->y[i]=(my_point->m * my_point->x[i]) + my_point->b;
    }
}

//Fill the malloced x-array
void fill_x_array(FILE *f, point* my_point){

    //For loop to get all the x-values into the array
    for(int i = 0; i < my_point->count; i++){

        //Scan from the input file and put those into the array
        fscanf(f, "%lf\n", &(my_point->x[i]));
    }
}


//Find the intercept of the points read
double intercept_calculator(double x1, double y1, double m)
{

    //Use algebra to rearrange the y=mx+b formula to find "b" and return it
    return (-1)*(m*x1) + y1;
}

//Find the slope between the points read from the input
double slope_calculator(double x1, double y1, double x2, double y2)
{
    //Get the value from the slop formula and return it
    return (y2-y1)/(x2-x1);
}

//Construct the point
point* constructor(int set_amount, double x1, double x2, double y1, double y2)
{
    //Make the array for the point
    point *my_point= (point*)malloc(sizeof(point));

    //Get the slope
    double m = slope_calculator(x1, y1, x2, y2);

    //Get the y-intercept
    double b = intercept_calculator(x1, y1, m);

    //pass the slope to the structures value of m
    my_point -> m = m;

    //pass the intercept to the structures value of b
    my_point -> b = b;

    //pass the set amount to the structures value of count
    my_point -> count = set_amount;

    //Make a malloced array for the x and y values
    my_point -> x = (double*)malloc(sizeof(double)*set_amount);
    my_point -> y = (double*)malloc(sizeof(double)*set_amount);

    //return the structure
    return my_point;
}

//Check if the files open or not
void check_if_null(FILE *ifp, FILE *ofp)
{
    //If it doesn't open, print an error message
    if(ofp==NULL || ifp == NULL)
    {
        printf("error opening file.\n");

    }

    //If there is no problem when opening the files, return back to main and lets get to work, WOOHOO
    else{
        return;
    }
}

int main()
{
    //Make the string for getting the title
    char title[256];

    //declare the variables we are going to obtain from the input
    double x1, y1, x2, y2;

    //This is our count variable
    int set_amount;

    //Pointer to our file names
    FILE *ifp;
    FILE *ofp;

    //ifp = fopen("cop3223-as5input.txt", "r");
    ifp = fopen("cop3223-as5input.txt", "r");
    ofp = fopen("cop3223-as5output-Fortune_Panizo-Mauricio.txt", "w");

    //Check if these files have an error wen opening them
    check_if_null(ifp, ofp);

    //Get the title and input it into the title array that holds its characters
    fgets(title, 256, ifp);

    //Get the values of x1 and y1
    fscanf(ifp, "(%lf,%lf)\n", &x1, &y1);

    //Get the values of x2 and y2
    fscanf(ifp, "(%lf, %lf)\n", &x2, &y2);

    //Get that count variable that tells how many numbers there are in the list
    fscanf(ifp, "%d\n", &set_amount);

    //Go to our construct the point
    point* my_point = constructor(set_amount, x1, x2, y1, y2);

    //Fill the malloced x-array
    fill_x_array(ifp, my_point);

    //close the input file
    fclose(ifp);

    //fill the malloced y-array
    fill_y_array(my_point);

    //Print out all the values
    print_function(ofp, title, my_point, x1, y1, x2, y2);

    //dispose the malloced array
    dispose_point(my_point);

    return 0;
}
