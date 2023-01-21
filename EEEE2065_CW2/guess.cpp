#include "guess.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guessgame class

void Guessgame::printWelcome(){
    //get the user input of mode to proceed with
    cout << "------------------------------------------------------------------\n";
    cout << "Select Mode: \n";
    cout << "------------------------------------------------------------------\n";
    cout << "Human guesses (Enter 1 only)\n";
    cout << "Computer guesses (Enter 2 only)\n";
    cout << "Histogram Out (Enter 3)\n";
    cout << "Characteristics only (Enter any other number)\n";
    cout << "------------------------------------------------------------------\n";
    cout << "Enter your choice: ";
}

//to initialize the parameters of the guessing game
//take range as input to set the range of the guessing pool
void Guessgame::Init_para(int range, int choice){
    //seed for random number
    this->range=range;
    //dynamically allocate memory to array
    if(!(choice==1 || choice==2)){
        counter = new int[mem];
        for(int i=0; i<mem; i++){
            counter[i] = 0;
        }
    }
}

//to generate the random guessing number within the class
void Guessgame::set_guessnumber(){
    //generate the random number
    //plus 1 so that the range starts from 1 to 'range'
    Thenumber = rand()%range+1;

    //cout << "Random number = " << Thenumber << endl;
}

//to check the human guessing mode whether the human guessed correctly or not
void Guessgame::checkhumanguess(){
    if(user_guess>Thenumber){
        //increase the number of guesses it took
        num_prediction = num_prediction+1;
        cout << user_guess <<" is too high\n";

    }
    else if(user_guess<Thenumber){
        //increase the number of guesses it took
        num_prediction = num_prediction+1;
        cout << user_guess <<" is too low\n";

    }
    else if(user_guess==Thenumber){
        //printing the summary of how many guesses and what was the correct number
        cout << user_guess << " is correct!"<< " You took " << num_prediction << " guesses" << endl;

        //set to false to stop asking for user guess input
        cont = false;
    }
}

//to check the computer guessing mode whether the computer guessed correctly or not
void Guessgame::checkcomputerguess(int *decision, int choice){
    if(comp_guess>Thenumber){
        //only print if it is mode 2
        if(choice == 2){
            cout << "Guess " << num_prediction << ": " << comp_guess <<" is too large\n";
        }

        //update the number of guesses the computer took
        num_prediction = num_prediction+1;

        //to update the parameter of the computer algorithm accordingly
        *decision = 1;

    }
    else if(comp_guess<Thenumber){
        //only print if it is mode 2
        if(choice == 2){
            cout << "Guess " << num_prediction << ": " << comp_guess <<" is too small\n";
        }

        //update the number of guesses the computer took
        num_prediction = num_prediction+1;

        //to update the parameter of the computer algorithm accordingly
        *decision = 2;

    }
    else if(comp_guess==Thenumber){
        //only print if it is mode 2
        if(choice == 2){
            //printing the summary of how many guesses and what was the correct number
            cout << "Guess " << num_prediction << ": " << comp_guess << " is correct!\n";
            cout << "Solution obtained after " << num_prediction << " guesses\n";
        }

        //so that the computer algorithm does not have to be updated because it guessed correctly
        *decision = 0;

        //stops asking for computer guess input
        cont = false;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// computer algorithm for guessing

//to set the parameters of the computer algorithm
//takes range as input so that the computer makes a guess within the range
void Guessgame::set_Comp(){
    MaxVal = range;
    upper_num = range;
    lower_num = 1;
}

//to update the parameters of the computer algorithm as the computer makes more guesses
//takes 'guess' as input to update the parameters
//takes 'decision' as input to determine which parameter that needs to be updated
void Guessgame::update_Comp(int decision){
    if(decision == 1){
        upper_num = comp_guess;
    }
    else if(decision == 2){
        lower_num = comp_guess;
    }
}

//to generate a computer guess
//the workings of it is the same as Binary Search
int Guessgame::algo(){
    int current_guess;

    if(lower_num == MaxVal-1){
        current_guess = upper_num;
    }

    else if(upper_num == lower_num+1){
        current_guess = lower_num;
    }

    else{
        current_guess = (upper_num - lower_num)/2 + lower_num;
    }

    return current_guess;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// histogram functions

//to update the counter for keeping track of the number of guesses for each sample in an experiment
//takes 'num_prediction' to update the counter based on the number of guesses it took
void Guessgame::update_counter(int num_prediction){
    counter[num_prediction]++;
}

//to find the maximum number of guesses it took for the computer to get the number correct
void Guessgame::findMaxBin(){
    //finding the max bin
    for (int i = 0; i < mem; i++) {
        if (counter[i]!=0) {
            MaxBin = i;
        }
    }
}

//calculating the mean of the experiment
//takes 'repeat' as input to know the sample size
void Guessgame::CalcMean(){
    float sum1 = 0;

    //calculate sum until Maxbin
    for(int i=0; i<=MaxBin; i++){
        sum1 = sum1 + (counter[i]*i);
    }

    mean = sum1/repeat;
}

//calculate the standard deviation of the experiment
//takes 'repeat' as input to know the sample size
void Guessgame::CalcSTD(){
    float sum2 = 0;

    //calculate the sum until Maxbin
    for(int i=0; i<=MaxBin; i++){
        sum2 = sum2 + counter[i]*pow(i,2);
    }

    sigma = sqrt((sum2/repeat)-pow(mean,2));
}

//to output the horizontal histogram onto the console
void Guessgame::histogramGraph(){
    //accessing each counter
    for(int i=0; i<=MaxBin; i++){
        cout << setw(2) << i << "/" << setw(3) <<counter[i] << "  ";

        //checks whether the counter has a value large than 0
        if(counter[i]!=0){
            //prints the star sign according the value of the counter
            for(int j=0; j<counter[i]; j++){
                cout << "*";
            }
        }

        //print to the next row
        cout << "\n";
    }

    //display summary of the experiment
    cout << "max bin = " << MaxBin << endl;
    cout<< "mean: " << setprecision(3) << mean << endl;
    cout<< "sigma: " << setprecision(6) << sigma << endl;
    delete[] counter;//to free the memory in counter array
}

//prints more summary of the experiment
//takes 'range' as input to display the range of the experiment
void Guessgame::printSummary(){
    cout << "N = " << range << endl;
    cout << "max bin = " << MaxBin << endl;
    cout << "mean = " << mean << endl;
    cout << "standard deviation = " << sigma << endl;
    cout << "\n";
    delete[] counter;//to free the memory in counter array
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// functions for answering the questions

//mode 1 represents Question 1 from the CW
//takes 'range' as input to know the pool of the guessing pool
//takes choice as input to know whether to initialize the counter array or not
void Guessgame::question1(int range, int choice){
    //set the range
    Init_para(range, choice);

    //generate the random number that has to be guessed
    set_guessnumber();

    //asking user for input repeatedly until correct number is guessed
    while(cont){
        //ask user for input
        cout << "\nEnter guess " << num_prediction << ":\n";
        cin >> user_guess;

        //in the class check whether the user guess is correct or not
        checkhumanguess();
    }
}

//mode 2 represents Question 2 from the CW
//takes 'range' as input to know the pool of the guessing pool
//takes choice as input to know whether or not to print retry message
void Guessgame::question2(int range, int choice){
    int decision = 0; //stores the next decision of what the computer should do

    //initializes the parameters of the guessing game
    Init_para(range, choice);

    //generate the random number to be guess by the computer
    set_guessnumber();

    //set the parameters of the computer's algorithm to guess the random number
    set_Comp();

    //asking the computer for input repeatedly
    //until the computer guess the number correctly
    while(cont){
        //calls algorithm for guessing the random number
        comp_guess = algo();

        //check whether the computer guesses correctly or not
        checkcomputerguess(&decision, choice);

        //change the parameters of the computer's algorithm based on whether the computer guess higher or lower than correct number
        update_Comp(decision);
    }

}

//takes 'range' as input to know the pool of the guessing pool
//takes choice as input to know whether or not to print retry message
void Guessgame::question3(int range, int choice){
    int decision = 0; //stores the next decision of what the computer should do

    //initialize the parameters for the guessing game
    Init_para(range, choice);

    for(int i=0; i<repeat; i++){
        //set the parameters for the computer guessing algorithm
        set_Comp();

        //generate the random number
        set_guessnumber();

        //ask the computer for input guess
        while(cont){
            //calls the function to generate a guess from the computer
            comp_guess = algo();

            //check the computer's guess
            checkcomputerguess(&decision, choice);

            //change the parameters of the computer's algorithm based on whether the computer guess higher or lower than correct number
            update_Comp(decision);
        }

        //update counter for the number of guesses it took for the computer each experiment
        update_counter(num_prediction);

        //reset values
        cont = true; //so that the loop for asking computer guess input can restart
        num_prediction = 1; //reset the current number of guess the computer took at the start of each experiment
    }

    cout << "\n";

    //finding the max number of guesses the computer took in the whole experiment
    findMaxBin();

    //calculate the mean number of guesses for the whole experiment
    CalcMean();

    //calculate the standard deviation of the whole experiment
    CalcSTD();

    //display the histogram showing the results of the experiment
    histogramGraph();
}

//gettingCharac represents Question 4 from the CW
//takes choice as input to know whether or not to print retry message
void Guessgame::question4(int choice){
    //create an output stream
    ofstream excel_mean;
    ofstream excel_sigma;

    //create and open excel file
    excel_mean.open("mean.csv");
    excel_sigma.open("sigma.csv");

    //create header for the excel file
    excel_mean << "mean, N" << endl;
    excel_sigma << "sigma, N" << endl;

    int decision = 0;

    //loop for varying the range from N=100 to N=5000
    for(int N = 100; N<=5000; N+=100){
        //initialize the parameters for the guessing game
        Init_para(N, choice);

        //for each value of N, get 200 samples
        for(int i=0; i<repeat; i++){
            set_Comp();
            set_guessnumber();

            //asking the computer for input
            while(cont){
                comp_guess = algo();
                checkcomputerguess(&decision, choice);
                update_Comp(decision);
            }

            //update counter
            update_counter(num_prediction);

            //reset values
            cont = true;
            num_prediction = 1;
        }

        cout << "\n";

        //finding the max number of guesses the computer took in the current value of N
        findMaxBin();

        //calculate the mean number of guesses in the current value of N
        CalcMean();

        //calculate the standard deviation in the current value of N
        CalcSTD();

        //printing the summary of experiment for the current value of N
        printSummary();

        //export data to excel file
        excel_mean << mean << "," << range << endl;
        excel_sigma << sigma << "," << range << endl;
    }

}
