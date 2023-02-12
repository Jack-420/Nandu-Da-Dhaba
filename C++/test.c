#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

int number, guess, nguesses=1;
srand(time(0));

number = rand()%100+1;

// printf("%d\n",number);
// scanf("%d",&number);
    printf("Guess the number\n");

do{
    scanf("%d",&guess);
    if(guess>number){
        printf("Guess a lower number\n");
    }
    else if(guess<number){
        printf("Guess a higher number\n");
    }
    else{
        printf("congrats!!!!....You guessed the number correct in %d attempts \n", nguesses);
    }
    nguesses++;
} while(guess!=number);

return 0;

}