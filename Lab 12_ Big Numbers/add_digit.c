/*!
@file add_digit.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial Lab 12
@date 24/11/2022
@brief This file contains multiple functions used by main to calculate addition
of long intergers using arrays and structs
*//*_____________________________________________________________*/
#include <stdio.h>
#include "add_digit.h"
#include "string.h"
#include <stdlib.h>
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))
#define new_min(x,y) (((x) <= (y)) ? (x) : (y))

struct BigNumber {
    BigDigit* digits;
    size_t length;
};

/*!
@brief this function allocates memoryf or the data for a number given from 
a string and stores the data values
Special scenarios: nil
@param BigNumber* 
@return const char* text
*//*_____________________________________________________________*/
BigNumber* create_BigNumber(const char* text) {
    BigNumber* numba = malloc(sizeof(BigNumber));
    size_t digits = strlen(text);
    numba->digits = malloc(digits);
    numba->length = digits;
    for (int i = 0; i < (int) digits; i++) numba->digits[i] = (unsigned char) text[i] - 48;
    return numba;
}

/*!
@brief this function memory deallocates the data for a number given from a 
string
Special scenarios: nil
@param BigNumber* number
@return void
*//*_____________________________________________________________*/
void destroy_BigNumber(BigNumber* number) {
    free(number->digits);
    free(number);
    return;
}
/*!
@brief this function get a char value based on strlen to be used in other 
functions
Special scenarios: nil
@param const char *s, int idx
@return int
*//*_____________________________________________________________*/
int getcharval(const char *s, int idx) {
    if (idx < (int) strlen(s)) return s[(int) strlen(s) - idx - 1] - 48; 
    return 0;
}
/*!
@brief this funciton calculates the sum of the two numbers given to a new number
Special scenarios: nil
@param const BigNumber* number1, const BigNumber* number2
@return BigNumber*
*//*_____________________________________________________________*/
BigNumber* add_BigNumber(const BigNumber* number1, const BigNumber* number2) {
    BigNumber* sum = malloc(sizeof(BigNumber));
    size_t width = new_max(number1->length, number2->length);
    sum->digits = malloc(width);
    sum->length = width;
    int i = 0;
    for (i = 0; i <= (int) new_max(number1->length, number2->length); i++) sum->digits[i] = 0;
    for (i = 0; i < (int) new_max(number1->length, number2->length); i++) {
        if (i > (int) number1->length) {
            // printf("hello%d %d A\n", 0, number2->digits[number2->length - 1 - i]);
            sum->digits[(int) width - 1 - i] += add_BigDigit(0, number2->digits[(int) number2->length - 1 - i], sum->digits);
        } 
        else if (i > (int) number2->length) {
            // printf("hello%d %d B\n", number1->digits[number1->length - 1 - i], 0);
            sum->digits[(int) width - 1 - i] += add_BigDigit(number1->digits[(int) number1->length - 1 - i], 0, sum->digits);
        } 
        else {
            // printf("hello%d %d C\n", number1->digits[number1->length - 1 - i], number2->digits[number2->length - 1 - i]);
            sum->digits[(int) width - 1 - i] += add_BigDigit(number1->digits[(int) number1->length - 1 - i], number2->digits[(int) number2->length - 1 - i], sum->digits);
        }
    }
    return sum;
}
/*!
@brief this funciton prints out the values of the 3 numbers in a fixed format
based on the expected output
Special scenarios: nil
@param const BigNumber* number1, const BigNumber* number2, const BigNumber* sum
@return void
*//*_____________________________________________________________*/
void print_BigNumber_sum(const BigNumber* number1, const BigNumber* number2, const BigNumber* sum) {
    int allocatedStrLen = (int) new_max(new_max(sum->length, number1->length), number2->length) + 2;
    int lenNum1 = (int) number1->length;
    int lenNum2 = (int) number2->length;
    int lenSum = (int) sum->length;
    for (int i = 0; i < allocatedStrLen - lenNum1; i++) printf(" ");
    for (int i = 0; i < lenNum1; i++) printf("%d", number1->digits[i]);
    printf("\n+");
    for (int i = 0; i < allocatedStrLen - lenNum2 - 1; i++) printf(" ");
    for (int i = 0; i < lenNum2; i++) printf("%d", number2->digits[i]);
    printf("\n");
    for (int i = 0; i < allocatedStrLen; i++) printf("-");
    printf("\n");
    for (int i = 0; i < allocatedStrLen - lenSum; i++) printf(" ");
    for (int i = 0; i < lenSum; i++) printf("%d", sum->digits[i]);
    printf("\n");
    return;
}