# Introduction
A single class is created for this whole guessing game. The variable used to store randomly generated number is a classified as a private access specifier in this program so that only the member function of this guessing game class can directly access the number stored in this variable. There are 4 modes to choose from.

## Human guesses
The program would ask the user what game mode would they want to do. The user would have to enter 1 to play the human guesses game mode. Then the program would ask the max value of the possible random number so that the generated random guess is between 1 and the max value. Srand(), time(), and rand() were the few functions used to make sure that each random number generated would be different. The program asks for user input until the user guesses the correct random number generated. For each user input guess, it will be passes to a member function to check whether the guess is correct. If the guess is correct, the generated random number will be printed alongside the number of attempts it took guess the generated number. 

## Computer guesses
This mode can be run by entering number 2 when the program asks for the user to select the mode. This mode is where a computer would have to guess the randomly generated number. For the computer to guess randomly generated number it would have to use an algorithm so that guess made by the computer is not totally random. The foundation of the algorithm used in this program for the computer to guess is the binary search algorithm. It works as explained in steps below:

1.	The computer makes a guess by dividing the range of the guessing pool (upper_number – lower_number) by 2. For the first guess the upper_number would be N and the lower_number would be 1 as the smallest possible generated random number is 1.
   
2.	If the number guessed is large than the generated random number, then the upper_number is updated to be the currently guessed number made by the computer
   
3.	If the number guessed is smaller than the generated random number, then lower_number is updated to the currently guessed number made by the computer
   
4.	This process is repeated until a correct guess is made by the computer 

## Histogram on number of guesses
By selecting mode 3, the program generates a horizontal histogram and provides the mean and standard deviation of guesses produced by a computer algorithm developed in mode 2. This mode allows users to choose a value (N) that defines the range for the computer's guessing pool and the range for generating random numbers. After specifying the range, the program runs the mode from question 2, which involves the computer algorithm guessing a randomly generated number, 200 times. Each experiment uses the same N value but different random numbers. The results are collected to create a frequency array based on the number of guesses it took for the computer to guess the correct number.

At the end of all 200 experiments, the program calculates the maximum bin (most frequent number of guesses) from the frequency array. The horizontal histogram is then plotted, displaying the frequency of guesses up to the maximum bin. The histogram is constructed using nested loops to access array indices representing the number of guesses and printing star signs to depict frequency. The calculation of mean and standard deviation is also limited to the range up to the maximum bin.

## Relationship between the mean and the standard deviation with (N)
Uses algorithm in mode 3 and export the data as excel file so the user can simply insert a chart to visually see the relationship. 
