
# 1. UNITTEST

## 1.1. Modularize your code
As code's testability depends on its design, unit tests facilitate breaking it into specialized easy-to-test pieces.

## 1.2. Avoid regressions
When you have a suite of unit tests, you can run it iteratively to ensure that everything keeps working correctly every time you add new functionality or introduce changes.

## 1.3. Document your code
Running, debugging, or even just reading tests can give a lot of information about how the original code works, so you can use them as implicit documentation.

## 1.4. Good practices for unit testing include
- Creating tests for all publicly exposed functions, including class constructors and operators.
- Covering all code paths and checking both trivial and edge cases, including those with incorrect input data (see negative testing).
- Assuring that each test works independently and does't prevent other tests from execution.
- Organizing tests in a way that the order in which you run them doesn't affect the results.

## 1.5. A single test
A single unit test is a method that checks some specific functionality and has clear pass/fail criteria. The generalized structure of a single test looks like this:

Test (TestGroupName, TestName)   {
    1 - setup block
    2 - running the under-test functionality
    3 - checking the results (assertions block)
}

## 1.6. inject dependances


## 1.7. reference
https://www.jetbrains.com/help/clion/unit-testing-tutorial.html#basics

# 2. GTEST
## 2.1. Use expected and actual

## 2.2. Check non fatal macro

## 2.3. Check fatal macro

## 2.4. Test private members

## 2.5. Test exceptions

## 2.6. Visual studio code

# 3. GMOCK

## 3.1. MOCK vs STUB

## 3.2. Mocking virtual method

## 3.3. Mocking Free Functions

## 3.4. Reference
http://google.github.io/googletest/gmock_cook_book.html


