/*!
@file my_string.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial Lab 10
@date 10/11/2022
@brief This file contains multiple functions as replacements to the string.h lib
*//*_____________________________________________________________*/
#include "my_string.h"
/*!
@brief this function finds the lenght of the string
Special scenarios: nil
@param const char* str
@return size_t
*//*_____________________________________________________________*/
size_t my_strlen(const char* str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return (size_t)i;
}
/*!
@brief this function copies one string to another string, in a fixed order
Special scenarios: nil
@param char* dest, const char* src
@return char
*//*_____________________________________________________________*/
char* my_strcpy(char* dest, const char* src)
{
    int i =0;
    while(src[i])
    {
    dest[i]=src[i];
    i++;
    }
    return dest;

}
/*!
@brief this function appends one string to another string, in a fixed order
Special scenarios: nil
@param char* dest, const char* src
@return char
*//*_____________________________________________________________*/
char* my_strcat(char* dest, const char* src)
{
    int j = 0;
    while(dest[j])
    {
        j++;
    }
    int i =0;
    while(src[i])
    {
    dest[j]=src[i];
    i++;
    j++;
    }
    return dest;

}
/*!
@brief this function compares one string with another, returing an int value
representing if it equals each other, or bigger or smaller in size.
Special scenarios: nil
@param char* dest, const char* src
@return int
*//*_____________________________________________________________*/
int my_strcmp(const char* lhs, const char* rhs)
{
    for ( ; *lhs == *rhs; lhs++, rhs++)
	if (*lhs == '\0')
	    return 0;
    return ((*(unsigned char *)lhs < *(unsigned char *)rhs) ? -1 : +1);
}
/*!
@brief this function returns the address of the first instance of the 
needle(substr) in the haystack(str)
Special scenarios: nil
@param const char* str, const char* substr
@return char*
*//*_____________________________________________________________*/
char* my_strstr(const char* str, const char* substr)
{
    
    const char *a, *b;

    b = substr;
    if (*b == 0) {
    char*p = (char*)str;
	return p;
    }
    for ( ; *str != 0; str += 1) {
	if (*str != *b) {
	    continue;
	}
	a = str;
	while (1) {
	    if (*b == 0) {
		char*p = (char*)str;
	    return p;
	    }
	    if (*a++ != *b++) {
		break;
	    }
	}
	b = substr;
    }
    return NULL;

}




