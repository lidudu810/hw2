/*  ========== H02 - Guessing Game ============
 *
 *   Student: Chengyi Li
 *   Semester: spring 2023
 *
 * A simple guessing game program. 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H

#define MAX_RANDOM 10
#define MIN_RANDOM 1

//this is meth for the frame.
void frame() {
    printf("----------------------------------------------------\n");
}

// this is the entry for the game show welcome game.
void welcome_guess() {
     frame();
     printf("|  Welcome to the Guessing Game. Let's get started.  |\n");
     frame();
}

//this is the main function for guessing game, to print and provide hint.
int guess_hint(int x, int num1) {
    int guess;
    int num;
    for(num = 0; num < 15; num++){
        printf("Guess a number (1 to 10): ");
        if(num == 0 && num1 != -1) {
                guess = num1;
        }else{
            scanf("%d", &guess);
        }

        if(x > guess) {
            printf("Your guess is too low. \n"); 
        }else if(x < guess) {
            printf("Your guess is too high. \n");
        }else {
            printf("Correct! Congratulations! \n");
            break;
        }
    }
    return num + 1; // guess time is starting at 1 not 0.
}

// the main guessing game, to let the function run 5 times.
int * guess() {
    int static guess_time[5];
    int i; 
    for(i = 0; i < 5; i++) {
     frame();
     printf("|                     Round %d                     |\n", i + 1);
     frame();
     int x = rand() % 10 + 1;
     guess_time[i] = guess_hint(x, -1);
    }
    return guess_time;
}

// to get how many run and time the guess use.
void end_guessting(int *guess_time) {
    frame();
    printf("|              Result of the Rounds!              |\n");
    frame();
    int i;
    for(i = 0; i < 5; i++) {
        printf("Round %d took you %d guesses.\n", i + 1, guess_time[i]);
    }   
}


/** Start location for the guessing game - this must
 * remain the starting point. DO NOT reset the random seed.
 */
int start_game()
{
    int *guess_time;
    welcome_guess();
    guess_time = guess();
    end_guessting(guess_time);
    return 0; // returns 0 if game ran validly
}

#endif