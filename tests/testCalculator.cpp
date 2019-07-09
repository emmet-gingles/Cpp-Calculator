#include <CUnit/Basic.h>        // For CUnit tests
#include "../Calculator.h"      // For accessing functions defined in header

/* Instance of Calculator class */
Calculator calc;

/* Run at the start of test suite */
int init_suite(void) {
    return 0;
}

/* Run at the end of test suite */
int clean_suite(void) {
    return 0;
}

/* Test for Calculator's add function */
void testAdd() {
    CU_ASSERT(calc.add(2,2) == 4);
    CU_ASSERT(calc.add(2,-1) == 1);
    CU_ASSERT(calc.add(-2,-2) == -4);
}

/* Test for Calculator's subtract function */
void testSubtract() {
    CU_ASSERT(calc.subtract(2,1) == 1);
    CU_ASSERT(calc.subtract(2,-1) == 3);
    CU_ASSERT(calc.subtract(-2,-2) == 0);
}

/* Test for Calculator's multiply function */
void testMultiply() {
    CU_ASSERT(calc.multiply(2,2) == 4);
    CU_ASSERT(calc.multiply(2,-2) == -4);
    CU_ASSERT(calc.multiply(-2,-2) == 4);
    CU_ASSERT(calc.multiply(2,0) == 0);
}

/* Test for Calculator's divide function */
void testDivide() {
    CU_ASSERT(calc.divide(2,1) == 2);
    CU_ASSERT(calc.divide(2,-1) == -2);
    CU_ASSERT(calc.divide(-2,-1) == 2);
    CU_ASSERT(calc.divide(2,0) == 0);
}

/* Test for Calculator's modulus function */
void testModulus() {
    CU_ASSERT(calc.modulus(4,2) == 0);
    CU_ASSERT(calc.modulus(5,2) == 1);
    CU_ASSERT(calc.modulus(2.5,2) == .5);
}

/* Test for Calculator's average function */
void testAverage() {
    CU_ASSERT(calc.average({2,2}) == 2);
    CU_ASSERT(calc.average({6,5,1}) == 4);
    CU_ASSERT(calc.average({-4,-4,-1}) == -3);
}

/* Test for Calculator's square root function */
void testSquareRoot() {
    CU_ASSERT(calc.squareRoot(144) == 12);
    CU_ASSERT(calc.squareRoot(25) == 5);
    CU_ASSERT(calc.squareRoot(-1) == 0);
}

/* Test for Calculator's power function */
/* Any number to the power of 1 is itself */
/* Any number to the power of 0 is 1 */
/* If the exponent is negative then 1 is divided by the first number */
void testPower() {
    CU_ASSERT(calc.power(2,1) == 2);
    CU_ASSERT(calc.power(2,2) == 4);
    CU_ASSERT(calc.power(3,3) == 27);
    CU_ASSERT(calc.power(2,0) == 1);
    CU_ASSERT(calc.power(2,-2) == 0.25);
    CU_ASSERT(calc.power(-2,2) == 4);
    CU_ASSERT(calc.power(-3,3) == -27);
}

/* Test for Calculator's factorial function */
void testFactorial() {
    CU_ASSERT(calc.factorial(3) == 6);
    CU_ASSERT(calc.factorial(4) == 24);
    CU_ASSERT(calc.factorial(5) == 120);
    CU_ASSERT(calc.factorial(0) == 1);
    CU_ASSERT(calc.factorial(-3) == -6);
}

int main() {
    /* Test suite */
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("Calculator tests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add testAdd to the suite */
    if ((NULL == CU_add_test(pSuite, "testAdd", testAdd))) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* Add testSubtract to the suite */
    if (NULL == CU_add_test(pSuite, "testSubtract", testSubtract))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }
    
    /* Add testMultiply to the suite */
    if (NULL == CU_add_test(pSuite, "testMultiply", testMultiply))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }
    
    /* Add testDivide to the suite */
    if (NULL == CU_add_test(pSuite, "testDivide", testDivide))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }
    
    /* Add testModulus to the suite */
    if (NULL == CU_add_test(pSuite, "testModulus", testModulus))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }
    
    /* Add testAverage to the suite */
    if (NULL == CU_add_test(pSuite, "testAverage", testAverage))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }
    
    /* Add testSquareRoot to the suite */
    if (NULL == CU_add_test(pSuite, "testSquareRoot", testSquareRoot))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }
    
    /* Add testPower to the suite */
    if (NULL == CU_add_test(pSuite, "testPower", testPower))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }
    
    /* Add testFactorial to the suite */
    if (NULL == CU_add_test(pSuite, "testFactorial", testFactorial))
    {
      CU_cleanup_registry();
      return CU_get_error();  
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
