#include "Calculator.h"     // For accessing functions defined in header
#include <iostream>         // For input/output
#include <math.h>           // For maths functions
#include <vector>           // For creating vectors
#include <string>           // For creating strings
#include <limits>           // For streamsize limit

/* Standard namespace */
using namespace std;

/* Function that clears the input stream */
void clearInput(istream &in){
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(),'\n');
    
}

/* Boolean function that checks that the user input is the correct type */
bool validateInput(istream &in, ostream &out){
    /* If it is not the correct type call clearInput and return false */
    if(in.fail()){
        clearInput(in);
        out << "Please enter a valid  number " << endl;
        return false;
    }
    /* Else it is correct so return true */
    return true;
}

/* Main Program */
int main() {

    /* Instance of Calculator class */
    Calculator calc;
    
    /* Menu for user*/
    string menu = string("Calculator Menu" )
	+ "\n Type 1 for addition. \n Type 2 for subtraction."
	+ "\n Type 3 for multiplication. \n Type 4 for division." 
	+ "\n Type 5 for modulus. \n Type 6 for average."
	+ "\n Type 7 for square root. \n Type 8 for power."
	+ "\n Type 9 for factorial. \n Type 0 to exit program \n";
    /* Print menu */
    cout << menu;

    /* Continuous loop unless break */
    while (true){
        cout << "Enter choice" << endl;
        cout << "Type m for menu" << endl;

        /* Variable to store user input as string */
        string s_input;
        /* Get the user's input and save it to variable */
        cin >> s_input;
        /* If input is "m" then print menu */
        if(s_input == "m"){
            cout << menu;
        }
        /* Else input should be a number */
        else {
            /* Variable to store the input as an integer */
            int input;
            /* Try to cast from string to integer */
            try{
                input = stoi(s_input);
            }
            /* If it is not an integer then continue loop */
            catch(invalid_argument& e){
                cout << "Please enter a number" << endl;
                continue;
            }

            /* If zero is input then exit loop and terminate program */
            if(input == 0){
                break;
            }

            /* Variables to store number inputs as doubles */
            double num,num2;
            
            /* Switch statement depending on user input */
            switch(input){
                /* 1. Addition function */
                case 1:                    
                    cout << "Addition" << endl;
                    /* Continue loop while input is non-numeric */
                    while(true){
                        cout << "Enter first number" << endl;
                        /* Save input to variable */
                        cin >> num;
                        /* Call function to check input is numeric. If it is 
                           break out of loop */
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    while(true){
                        cout << "Enter second number" << endl;
                        /* Save input to variable */
                        cin >> num2;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    /* Call the add function and print the result */
                    cout << "RESULT: " << calc.add(num, num2) << endl;
                    break;
                /* 2. Subtraction function */
                case 2:
                    cout << "Subtraction" << endl;
                    
                    while(true){    
                        cout << "Enter first number" << endl;
                        cin >> num;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    while(true){
                       cout << "Enter second number" << endl;
                       cin >> num2;
                       if(validateInput(cin,cout)){
                           break;
                       }
                    }
                    /* Call the subtract function and print the result */
                    cout << "RESULT: " << calc.subtract(num, num2) << endl;
                    break;
                        
                /* 3. Multiplication function */
                case 3:
                    cout << "Multiplication" << endl;
						
                    while(true){    
                        cout << "Enter first number" << endl;
                        cin >> num;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    while(true){
                       cout << "Enter second number" << endl;
                       cin >> num2;
                       if(validateInput(cin,cout)){
                           break;
                       }
                    }
                    /* Call the multiply function and print the result */
                    cout << "RESULT: " << calc.multiply(num, num2) << endl;
                    break;
                /* 4. Division function */
                case 4:
                    cout << "Division" << endl;						
                    while(true){    
                        cout << "Enter first number" << endl;
                        cin >> num;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    while(true){
                       cout << "Enter second number" << endl;
                       cin >> num2;
                       if(validateInput(cin,cout)){
                           break;
                       }
                    }
                    /* Call the divide function and print the result */
                    cout << "RESULT: " << calc.divide(num, num2) << endl;
                    break;
                /* 5. Modulus function */
                case 5:
                    cout << "Modulus" << endl;                   					
                    while(true){    
                        cout << "Enter first number" << endl;
                        cin >> num;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    while(true){
                       cout << "Enter second number" << endl;
                       cin >> num2;
                       if(validateInput(cin,cout)){
                           break;
                       }
                    }    
                    /* Call the modulus function and print the result */
                    cout << "RESULT: " << calc.modulus(num, num2) << endl;
                    break;
                    
                /* 6. Average function */
                case 6:
                    cout << "Average" << endl;
                    while(true){
                        /* Brackets are necessary because a vector is defined 
                           within case statement */
                        {
                            /* Vector to store each number */
                            vector<double> numbers;
                            cout << "Enter a sequence of numbers. ";
                            cout << "Any non-numeric character will end sequence." << endl;
                            
                            /* While input is numeric add it to vector */
                            while(cin >> num){
                                numbers.push_back(num);
                            }
                            /* Call function to clear input stream */
                            clearInput(cin);
                            /* If two or more numbers in vector then call the 
                             * average function and print the result */
                            if(numbers.size() > 1){
                                cout << "RESULT: " << calc.average(numbers) << endl;
                                break;
                            }
                            /* Else not enough numbers */
                            else{
                                cout << "Please enter two or more numbers" << endl;
                            }
                        }
                    }
                    break;
                /* 7. Square root function */
                case 7:
                    cout << "Square root" << endl;
                    while(true){
                        cout << "Enter number" << endl;
                        cin >> num;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    /* Call the square root function and print result */
                    cout << "RESULT: " << calc.squareRoot(num) << endl;
                    break;
                    
                /* 8. Power function */
                case 8:
                    cout << "Power" << endl;                    
                    while(true){    
                        cout << "Enter number" << endl;
                        cin >> num;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    while(true){
                       cout << "Enter exponent" << endl;
                       cin >> num2;
                       if(validateInput(cin,cout)){
                           break;
                       }
                    } 
                    /* Call the power function and print the result */
                    cout << "RESULT: " << calc.power(num, num2) << endl;
                    break;
                   
                /* 9. Factorial function */
                case 9:
                    cout << "Factorial" << endl;
                    while(true){
                        cout << "Enter number" << endl;
                        cin >> num;
                        if(validateInput(cin,cout)){
                            break;
                        }
                    }
                    /* Call the factorial function and print the result */
                    cout << "RESULT: " << calc.factorial(num) << endl;
                    break;
                /* Default case where input is not between 1 and 9 */
                default:
                    cout << "Please enter a number between 1 and 9" << endl;
            }   /* End switch */
        }   /* End else */
    }   /* End while */
    
    // Exit program
    return 0;
}   /* End main */

