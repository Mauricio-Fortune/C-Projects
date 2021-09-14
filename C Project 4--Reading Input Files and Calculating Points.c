//Mauricio Fortune Panizo
//COP3223C
//April 1, 2021

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lets print all this our=t
void print_function(FILE *ofp, char *title, double x1, double y1, double x2, double y2, double *x_values, int count, double b, double m, double *y_values)
{

    //create i and make it 0
    int i = 0;

    //Print out that title
    fprintf(ofp, "%s", title);

    //Print out the initial x and y values and the second x and y values
    fprintf(ofp, "The line across (%lf, %lf) and (%lf, %lf) has a slope of %lf and intercept of %lf\n", x1, y1, x2, y2, m, b);

    //Now lets print out the values from the x and y array
    for (i=0; i<count; i++){

        //Make sure they're in line
        fprintf(ofp, "  For x=  %15.8lf,   y=    %15.8lf\n", x_values[i], y_values[i]);

    }
    //Back to main we go!
    return;

}

//Calculate the values to put into the y array
void y_array_computer(FILE *ifp, FILE *ofp, double *x_values, int count, double *y_values, double b, double m)
{
    //create i and make it 0
    int i = 0;

    //Create a variable that will be the exact x-value and y-value we are at
    double x_cur, y;

    //Use a for loop to fill the x values from the input file we are reading
    for (i=0; i<count; i++){

        //use ifp to read from and make the current value x_cur
        fscanf(ifp, "%lf\n", &x_cur);

        //Add the current value from the input file into the x array
        x_values[i]= x_cur;
    }

    //Lets do a similar thing for the y values
    for (i=0; i<count; i++){
        //Use y=mx+b to find the y value since we have found all the other variables in the function
        y = m*(x_values[i]) + b;

        //Take the value that was found and put it into the y array
        y_values[i] = y;
    }

    //Lets go back to main
    return;

}


//Find the intercept of the points read
double intercept_calculator(FILE *ofp, double x1, double y1, double m)
{

    //Use algebra to rearrange the y=mx+b formula to find "b" and return it
    return (-1)*(m*x1) + y1;
}



//Find the slope between the points read from the input
double slope_calculator(FILE *ofp, double x1, double y1, double x2, double y2)
{
    //Get the value from the slop formula and return it
    return (y2-y1)/(x2-x1);
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

//Main function that runs everything
int main()
{
    //Set up the array to hold the characters that make up the title
    char title[256];

    //Define all the variables this function will need
    double x1, y1, x2, y2, m, b;
    int count;

    //The file will be known as ifp and ofp
    FILE *ifp;
    FILE *ofp;

    //Open this input file and read it
    ifp = fopen("Proj4input.txt", "r");

    //create this output file and write to it
    ofp = fopen("Proj4output.txt" , "w");

    //Check if these files have an error wen opening them
    check_if_null(ifp, ofp);

    //Get the title and input it into the title array that holds its characters
    fgets(title, 256, ifp);

    //Get the values of x1 and y1
    fscanf(ifp, "(%lf,%lf)\n", &x1, &y1);

    //Get the values of x2 and y2
    fscanf(ifp, "(%lf, %lf)\n", &x2, &y2);

    //Get that count variable that tells how many numbers there are in the list
    fscanf(ifp, "%d\n", &count);

    //Create the arrays for the x and y variables
    double x_values[count], y_values[count];


    //Calculate the slope between the values we just read from the input
    m = slope_calculator(ofp, x1, y1, x2, y2);

    //Get the y-intercept from the points given and their slope that was just found
    b = intercept_calculator(ofp, x1, y1, m);

    //Fill the x array and from this x array, calculate the y array
    y_array_computer(ifp, ofp, x_values, count, y_values, b, m);

    //Lets take everything we did and print it out.
    print_function(ofp, title, x1, y1, x2, y2, x_values, count, b, m, y_values);

    //Make sure those files are closed!
    fclose(ifp);
    fclose(ofp);
}
