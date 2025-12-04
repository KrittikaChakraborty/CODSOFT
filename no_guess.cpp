#include <iostream>
#include <cstdlib>   
#include <ctime>    
using namespace std;

int main() {
    char turn = 'y';

    while (turn == 'y' || turn  == 'Y') {
        srand(time(0));

        int num= rand() % 100 + 1; // Random number between 1 and 100
        int Guess = 0;
        int c= 0;

        cout << "Welcome to the Number Guessing Game!\n";
        cout << "I have selected a number between 1 and 100.\n";
        cout << "Try to guess it!\n";

        // Game loop
        while(Guess!= num) {
            cout << "Enter your guess: ";
            cin >> Guess;

            if(cin.fail()) {
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                cout << "Please enter a valid number.\n";
                continue;
            }

            c++;

            if(Guess > num) {
                cout << "Too high! Try again.\n";
            } else if(Guess < num) {
                cout << "Too low! Try again.\n";
            } else {
                cout << "Congratulations! You guessed the number in " << c << " attempts.\n";
            }
        }

        cout << "Do you want to play again? press(y/n): ";
        cin >> turn;
    }

    cout << "Thank you for playing!bye.\n";
    return 0;
}
