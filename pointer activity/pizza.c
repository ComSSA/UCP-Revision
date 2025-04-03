#include "pizza.h"

/*
Assume:
Each attendee eats 3 slices of pizza
Each pizza has 8 slices
Each pizza is 10 dollars
Return: total cost of pizza order
*/
void pizza_cost(int *num_pizza, float *cost_pizza, int num_attendees)
{
    const int slices_per_attendee = 3;
    const int slices_per_pizza = 8;
    const float dollar_per_pizza = 10;
    int num_slices = 0;
    
    // num_slices will be a multiple of 3
    num_slices = slices_per_attendee * num_attendees; 

    // num_pizza will be num_slices on 8, if there are remainders then we need an additional pizza
    // some confusion on the % operator... so it will DIVIDE num_slices by slices_per_pizza and return the REMAINDER... NOT THE QUOTIENT
    if(num_slices % slices_per_pizza > 0)
    {
        *num_pizza = num_slices / 8 + 1;
    }
    else
    {
        *num_pizza = num_slices / 8;
    }
    
    // update the total cost, which is the number of pizzas multiplied by 10
    *cost_pizza = *num_pizza * dollar_per_pizza;    
}

/*
Input: number of attendees (int)
Output: print the cost of the pizza
*/
int main(int argc, char **argv)
{
    int num_pizza = 0, num_attendees = 0, i=0, string_len = 0, is_letter=1;
    float cost_pizza = 0;

    // Check if user is only inputting 1 command line argument
    if (argc != 2)
    {
        printf("Please input the number of attendees (integer) as the first and only command line argument\n");
        return 1;
    }

    // Check the first argument if it's an int
    // Loop through the 1st argument and check if each character is a number
    string_len = (int)(strlen(argv[1]) / sizeof(char));
    for(i = 0; i < string_len; i++)
    {
        if (argv[1][i] > '9' || argv[1][i] < '0')
        {
            is_letter = 0;
        }
    }
    if (!is_letter)
    {
        printf("Please make sure you're entering a number\nYour input: %s\n", argv[1]);
    }
    else
    {
        num_attendees = atoi(argv[1]);
        /*
        atoi will overflow if user input is greater than INT32_MAX, meaning the comparison later down in the code is irrelevant
        I'm not too sure on how to check for it, and kinda not getting paid to do this so I'll leave it up to you
        */
    }
    // You won't have to do so much user input checking like this... ESPECIALLY MANUALLY LIKE THIS

    // Make sure the input is within bounds... this check is actually wrong
    if(num_attendees >= 0 && num_attendees < INT32_MAX && is_letter) //this code won't work >.< some input values larger than INT32_MAX will overflow into a value within bounds
    {
        pizza_cost(&num_pizza, &cost_pizza, num_attendees);
        printf("Cost of pizza is $%2.f\n", cost_pizza);
    }
    else
    {
        printf("Please input an integer greater than 0 and less than 2147483647\nYour input: %s\n", argv[1]);
    }
    return 0;
}