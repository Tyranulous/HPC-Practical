/**************************************************
 *                                                *
 * First attempt at a code to calcule lost barley *
 * by A. Farmer                                   *
 * 18/05/18                                       *
 *                                                *
 **************************************************/

// Include any headers from the C standard library here
#include <stdio.h>
#include <stdlib.h>


// Define any constants that I need to use here
#define PI 3.142

// This is where I should put my function prototypes
float area_of_circle(float radius); 

// Now I start my code with main()
int main() 
    {

    // In here I need to delare my variables
    int totalArea = 0;      //Total area of circles
    int numberCircles = 0;  //number of circles program is calculating area for 
    int index = 0;          //index for use in for loop
    float weightLoss = 0;
    float monetaryLoss = 0;
    float cropCost = 0.1; //cost of 1kg of crop in £
    float cropYield = 0.135; //Yeild of crop per unit area in kg
    //float *rad;

    // Next I need to get input from the user.
    // I'll do this by using a printf() to ask the user to input the radii.
    printf("Enter number of crop circles: ");
    get(numberCircles);

    float rad[numberCircles];   //create array to store radii from user

    for(index = 0; index<numberCircles; index++)
        {
        printf("\nEnter radii of circle %i: ", index+1);
        scanf("%f", rad[index]);
        }
    // Now I need to loop through the radii caluclating the area for each
    for(index = 0; index<numberCircles; index++) 
        {
        totalArea =+ PI * rad[index] * rad[index];
        }   
    // Next I'll sum up all of the individual areas //not required :shrug:

    /******************************************************************
     *                                                                *
     * Now I know the total area I can use the following information: *
     *                                                                *
     * One square meter of crop produces about 135 grams of barley    *
     *                                                                *
     * One kg of barley sells for about 10 pence                      *
     *                                                                *
     ******************************************************************/

    // Using the above I'll work out how much barley has been lost.
    weightLoss = totalArea * cropYield;
    monetaryLoss = weightLoss * cropCost;

    // Finally I'll use a printf() to print this to the screen.
    printf("\nTotal area lossed in m^2 is:\t%f\n", totalArea);
    printf("Total loss in kg is:\t\t%f\n", weightLoss);
    printf("Total crop lost in money is: \t\t%f\n", monetaryLoss);

    return(0);
}

// I'll put my functions here:
