//Mauricio Fortune Panizo
//CS1
// 27 August 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lets calculate the longest suit run
int longestSuitRun(int* cardSuit, int n){
    //The smallest value a counting value can be is 1
    int val=1;
    //The smallest value max can be is 1
    int max=1;
    //Lets make a loop to run through the array of suits and calculate the longest running value
    for(int i = 1; i < n; i++){
        //If the previous suit is equal to the suit before, increase counting value by 1
        if(cardSuit[i] == cardSuit[i-1]){
            //Increase counting value by 1
            val = val +1;
        }
        //Other than that, if they don't repeat, make the val = 1 again
        else{
            val =1;
        }
        //If the val is greater than the max value, make max = val
        if(val > max){
            max = val;
        }
    }
    //return the max value
    return max;
}
//Lets calculate the longest ascending run value
int longestAscRun(int* cardValue, int n){
    //The smallest value val can start at is 1
    int val=1;
    //The smallest value max can be is 1
    int max=1;
    //Lets go through all the values in the cardValue array and determine the size
    for(int i=1;i<n; i++){
        //Special case: if we have an "A" followed by a 2, this is still considered ascending, add a 1 to val
        //If this happens
        if(cardValue[i]==2 && cardValue[i-1]==14){
          val = val + 1;
        }
        //Other than that, if the previous value - the current value is equal to 1, add 1 to val
        else if(cardValue[i]- cardValue[i-1]==1){
            val = val +1;
        }
        //If neither are satisfied, the suit is not increasing, thus, make val = 1
        else {
            val =1;
        }
        //If val is greater than the max value, make max = val
        if(val > max){
            max = val;
        }
    }
    //Return the max value
    return max;
}

int main()
{
  //Create variable for number of test cases value
   int amttestcases;

   //Get the amount of test cases
   scanf("%d", &amttestcases);

    //Read 2 lines for each test case
    for(int i=0; i<amttestcases; i++){
        //Create arrays for the two lines that need to be read
        char l1[200], l2[100];
        //Scan the first line and input it all into the array l1
        scanf("%s",l1);
        //Scan the second line and input it all inti the array l2
        scanf("%s",l2);
        //Concatenate both strings into l1
        strcat(l1,l2);

        //Make arrays for for the values and the suits of each given string
        int value[54], suit[54];

        /*First loop through every even index of l1 to get the Number value itself.
        Change every possible given value from a char variable to an int variable*/
        for(int j=0; j<52; j++){

            //If we see T change it to 10
            if(l1[2*j]=='T'){
                value[j]=10;
            }

            //If we see J change it to 11
            else if(l1[2*j]=='J'){
                value[j]=11;
            }

            //If we see Q change it to 12
            else if(l1[2*j]=='Q'){
                value[j]=12;
            }

            //If we see K change it to 13
            else if(l1[2*j]=='K'){
                value[j]=13;
            }

            //If we see A change it to 14
            else if(l1[2*j]=='A'){
                value[j]=14;
            }

            //For any other value we must change it from a char character to an int
            else{
                value[j]=l1[2*j]-'0';
            }
        }
        //Lets make the values of C,D,H, and S numerical
        for(int j=0; j<52; j++){

            //If there is a C in the odd spots of the array, make it 0
            if(l1[2*j+1]=='C'){
                suit[j]=0;
            }
            //If there is a D in the odd spots of the array, make it 1
            else if(l1[2*j+1]=='D'){
                suit[j]=1;
            }
            //If there is an H in the odd spots of the array, make it 2
             else if(l1[2*j+1]=='H'){
                suit[j]=2;
            }
            //If there is an s (only other option) in the odd spots of the array, make it 3
            else{
                suit[j]=3;
            }
        }
        //Call and print both the longest suit run and the longest ascending run
        printf("%d  %d\n", longestSuitRun(suit, 52), longestAscRun(value, 52));

    }
        return 0;
}
