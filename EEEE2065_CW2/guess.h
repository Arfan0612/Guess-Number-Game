#include <time.h>
#include <math.h>
#include <iomanip>
#include <fstream>

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
// class for the workings of the guessing game
class Guessgame{
 private:
     int range; //store the range of the guessing pool
     int num_prediction=1; //stores the number of guess
     int Thenumber; //store the number that must be predicted
     bool cont = true; //control loop for asking input guesses

     int user_guess; //stores the current guess made by the user
     int comp_guess; //stores the computer guess

     ////////////////////////////////////////////////////////
     // computer algorithm variables
     int MaxVal; //to store the upper bound of the range
     int upper_num;
     int lower_num;

     ////////////////////////////////////////////////////////
     // histogram variables
     const int mem = 100; //memory for counter array
     const int repeat= 200; //to get 200 samples for each value N
     int *counter;
     int MaxBin;
     float mean;
     float sigma;

     //checking guessed number
     void checkhumanguess();
     void checkcomputerguess(int *decision, int choice);

 public:
     //constructor
     Guessgame(){
        //to generate the seed for random number generator
        srand(time(0));
     }
     ~Guessgame(){}

     void printWelcome();

     //setters
     void Init_para(int n, int choice);
     void set_guessnumber();

     ///////////////////////////////////////////////////////
     // computer algorithm for guessing
     void set_Comp();
     void update_Comp(int decision);
     int algo();

     ///////////////////////////////////////////////////////
     // histogram functions
     void update_counter(int num_prediction);
     void findMaxBin();
     void CalcMean();
     void CalcSTD();
     void histogramGraph();
     void printSummary();

     //getter for mean and sigma
     float getMean()const{return mean;}
     float getSigma()const{return sigma;}

     ///////////////////////////////////////////////////////
     // functions for answering the questions
     void question1(int , int choice);
     void question2(int range, int choice);
     void question3(int range, int choice);
     void question4(int choice);
};

