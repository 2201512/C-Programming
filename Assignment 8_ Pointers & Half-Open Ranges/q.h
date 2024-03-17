/*!
@file q.h
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial assignment 8
@date 30/10/2022
@brief This file contains the function prototypes for various functions 
that will be called by main for various uses
*//*_____________________________________________________________*/

/*!
@brief The function returns a pointer to the first occurrence of val or
returns NULL if nothing is found.
Special scenarios: nil
@param char const *begin, char const *end, char val
@return char const*
*//*_____________________________________________________________*/
char const* find(char const *begin, char const *end, char val);
/*!
@brief The function  returns a pointer to the first occurrence of any member of 
the array whose first element is pointed to by pointer vals of lenght len, if 
not returning NULL
Special scenarios: nil
@param char const *begin, char const *end, char const *vals, int len
@return char const*
*//*_____________________________________________________________*/
char const* find_any(char const *begin, char const *end, char const *vals, int len);
/*!
@brief The function  returns the number of elements in a half-open range of
values equivalent to val 
Special scenarios: nil
@param char const *begin, char const *end, char val
@return int
*//*_____________________________________________________________*/
int count(char const *begin, char const *end, char val);
/*!
@brief The function  returns the number of elements in a half-open range of
values equivalent toany member of the array whose first element is pointed to 
by parameter vals with lenght len  
Special scenarios: nil
@param char const *begin, char const *end, char const *vals, int len
@return int
*//*_____________________________________________________________*/
int count_any(char const *begin, char const *end, char const *vals, int len);
/*!
@brief The function  compares corresponding elements in the arrays whose first
elements are pointed to by begin1 and begin2 with lenght len, if the two arrays 
are exactly the same, return 0. If an element in  begin1 is smaller than begin2,
return -ve. Else, return +ve.
Special scenarios: nil
@param char const *begin1, char const *begin2, int len
@return int
*//*_____________________________________________________________*/
int compare(char const *begin1, char const *begin2, int len);
/*!
@brief The function  swaps the values in the two arrays, with lenght len
Special scenarios: nil
@param char *begin1, char *begin2, int len
@return void
*//*_____________________________________________________________*/
void exchange(char *begin1, char *begin2, int len);
/*!
@brief The function copies values in address folowing src onto dst, for lenght 
len, and does in a manner to prevent overlap issues.
Special scenarios: nil
@param char *dst, char *src, int len
@return void
*//*_____________________________________________________________*/
void copy(char *dst, char *src, int len);
