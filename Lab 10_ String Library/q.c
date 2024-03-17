/*!
@file q.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial Lab 10
@date 10/11/2022
@brief This file contains multiple functions to build a string, compare it with
other strings, describe them, and find the string
*//*_____________________________________________________________*/
#include "q.h"  

/*!
@brief this function creates a string from parameters in a specific order, 
mimicing a file directory
Special scenarios: nil
@param const char* parent, const char* separator, const char* const folders[], size_t count
@return const char*
*//*_____________________________________________________________*/
const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count)//done
{
    char array[128] = {0};
    STRCPY(array, parent);
    
    for(int i = 0; i<(int)count; i++)
    { 
        STRCAT(array, folders[i]);
        STRCAT(array, separator);
    }
    
    char* result = debug_malloc(STRLEN(array)+1);
    
    STRCPY(result, array);
    
    return result;
}
/*!
@brief this function using strcmp to compare, and prints the equivilent answer
whether they are equal, or which string goes first
Special scenarios: nil
@param const char* lhs, const char* rhs
@return void
*//*_____________________________________________________________*/
void compare_string(const char* lhs, const char* rhs)
{
    int x = STRCMP(lhs, rhs);
    if(x>0)
    {
        printf("Right string goes first.\n");
    }
    else if (x<0)
    {
        printf("Left string goes first.\n");
    }
    else
    {
        printf("Both strings are equal.\n");
    }
}
/*!
@brief this function using strlen to find lenght of string, and prints
the equivilent lenght and the string itself
Special scenarios: nil
@param const char* text
@return void
*//*_____________________________________________________________*/
void describe_string(const char* text)//done
{
    printf("The length of the path \"%s\" is %ld.\n", text, STRLEN(text));
}
/*!
@brief this function using strstr to find  the start of str 2 in str 1,
and uses strlen for lenght of string and prints both.
Special scenarios: nil
@param const char* string, const char* substring
@return void
*//*_____________________________________________________________*/
void find_string(const char* string, const char* substring)
{
    printf("Searching for a string:\n");
    printf("	Text:     %s\n", string);
    printf("	Sub-text: %s\n", substring);
    printf("	Result:   ");
    char* check = STRSTR(string, substring);
    if(check)
    {   
        printf("found %ld characters at a position %ld.\n", STRLEN(substring), (check-string));
    }
    else
    {
        printf("not found\n");
    }
}
