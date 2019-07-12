    
/* Define the header class if not defined */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#endif 

#include <vector>
    
using namespace std;

/* Define Calculator class */
class Calculator {
	
    /* Define the class functions */
    public:
        double add(double num1, double num2);
        double subtract(double num1, double num2);
        double multiply(double num1, double num2);
        double divide(double num1, double num2);
        double modulus(double num1, double num2);
        double average(vector<double> nums);
        double squareRoot(int num);
        double power(double num, int power);
        int factorial(int num);
};

  
