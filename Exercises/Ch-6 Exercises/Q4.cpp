/*

Write a program for the following numerical game:
    The computer stores a random number between 1 and 15 and the player 
(user) attempts to guess it. The player has a total of three attempts. After each
wrong guess, the computer tells the user if the number was too high or too low.
If the third attempt is also wrong, the number is output on screen.
    The player wins if he or she can guess the number within three attempts.
The player is allowed to repeat the game as often as he or she wants.

*/

#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main(){
    long sec;
    time(&sec);
    srand((unsigned)sec);

    cout << "Let's play a game! System will generate a random rumber a between 1 to 15\n You have three attemps to guess the number currectly.\n";
    int guess, no_attemp = 1;
    bool attemp = true, win=false; 

    while(attemp = true){

        int number= (rand() % 15 + 1);
        while ( no_attemp <= 3 ){
            cout << endl << "Your " << no_attemp << " is: ";
            cin >> guess;
            if(guess == number){
                cout << "Bhuiya!!" << endl;
                win = true;
                attemp = false;
                no_attemp = 1;
                break;
            }
            else if (guess > number && guess < number +6 ){
                cout << "try again. The number large" << endl ;
                no_attemp++;
                win = false;
            }
            else if (guess >= number + 6){
                cout << "try again. The number too large" << endl;
                no_attemp++;
                win = false;
            }
            else if (guess < number && guess > number -6){
                cout << "try again. The number less" << endl;
                no_attemp++;
                win = false;
            }
            else if (guess <= number - 6){
                cout << "try again. The number too less" << endl;
                no_attemp++;
                win = false;
            }
            else{
                cout << "Enter valid input" << endl;
                win = false;
            }
        }
        if( win == false){
            cout << endl << "Game Over";
            attemp = false;
            return 0;
        }
        else if (win == true){
            cout << "let's play again"<< endl;
            attemp = true;
        }
        
    }

    return 0;
}