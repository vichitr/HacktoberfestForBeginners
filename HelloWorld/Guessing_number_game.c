#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Number Guessing Game\n");
    while(1)
    {
        int num,choice;
        int key = 1; //number to guess input 
        printf("Enter a number\n");
        scanf("%d",&num);
        if(num == key)
        {
            printf("Number is Found - %d\n",key);
            printf("Thank you for playing this game");
            exit(0);
        }
        else if(num > key)
        {
            printf("The number you guessed is greater than the required number\n");
        }
        else
        {
            printf("The number you guessed is lesser than the required number\n");
        }
        printf("Do you want to try the game again\nPress 0 for no\n");
        scanf("%d",&choice);
        if(choice == 0)
        {
            printf("Thank you for playing this game again");
            exit(0);
        }
        printf("You have chosen to play the game\n");
    }
}