#include "guess.h"

int main()
{
    Guessgame game; //create object
    int choice; //to store the user's choice of mode

    game.printWelcome();
    cin >> choice;

    //check which choice made by user
    if(choice ==1 || choice==2 || choice==3){
        int range;

        //asking user for the range of the guessing pool
        cout << "\nSelect Range: ";
        cin >> range;

        if(choice==1){
            game.question1(range, choice);
        }
        else if (choice==2){
            game.question2(range, choice);
        }
        else if (choice==3){
            game.question3(range, choice);
        }
    }
    else{
        game.question4(choice);
    }

    return 0;
}
