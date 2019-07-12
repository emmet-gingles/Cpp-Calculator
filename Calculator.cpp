#include <math.h>           // For maths functions
#include "Calculator.h"     // For accessing functions defined in header

/* Standard namespace */
using namespace std;

/* Function that adds two numbers */
double Calculator::add(double num1, double num2){
    return num1+num2;
}

/* Function that subtracts two numbers */
double Calculator::subtract(double num1, double num2){
    return num1-num2;
}

/* Function that multiplies two numbers */
double Calculator::multiply(double num1, double num2){
    return num1*num2;
}

/* Function that divides two numbers */
double Calculator::divide(double num1, double num2){
    /* Division by zero is not allowed */
    if(num1 == 0 || num2 == 0){
        return 0;
    }
    else{
        return num1/num2;
    }
}

/* Function that returns the remainder of the division of two numbers */
double Calculator::modulus(double num1, double num2){
    /* Call the divide function and floor the result to make it a whole number */
    double div = floor(this->divide(num1, num2));
    /* Multiply the result by the second number and subtract this from the 
     * first number */
    return this->subtract(num1, this->multiply(div ,num2));
}		

/* Function that returns the average of a set of numbers */
double Calculator::average(vector<double> nums){
    /* Initialize variable as zero */
    double total = 0;
    /* Loop through each number and increase the total accordingly */
    for(int i=0;i< nums.size();i++){
        total += nums[i];
    }
    /* Divide the total by the number of numbers */
    return this->divide(total, nums.size());
}

/* Function that returns the square root of a number */
double Calculator::squareRoot(int num){
    /* Check that number is not less than zero */
    if(num <= 0){
        return 0;
    }
    /* Call the Maths sqrt function */
    return sqrt(num);
}

/* Function that returns a number to the power of an exponent */
double Calculator::power(double num, int power){
    return pow(num, power);
}

/* Function that returns the factorial of a number */
int Calculator::factorial(int num){
    /* Initialize variable as 1 */
    int fact = 1;
    /* 0! = 1 */
    if(num == 0){
        return fact;
    }
    /* Positive number */
    else if(num > 0){
        /* From 1 up to the number */
        for(int i=1;i<= num;i++){
            /* Multiply by the iterator */
            fact *= i;
        }
    }
    /* Negative number */
    else{
        /* From -1 up to the number */
        for(int i=-1;i>= num;i--){
            fact *= i;
        }
    }
    /* Return the factorial */
    return fact;
}

