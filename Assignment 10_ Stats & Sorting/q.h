/*!
@file q.h
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial assignment 10
@date 18/11/2022
@brief This file contains the header files for 
various functions used in qdriver.c, to caluclate grades in various ways 
such as max min median e.t.c
*//*_____________________________________________________________*/

/*!
@brief The function opens the intended file, reads the values and counts the no
of grades present, and stores them into an array using malloc/calloc for use 
outside the function
Special scenarios: nil
@param char const *file_name, int *ptr_cnt
@return double *
*//*_____________________________________________________________*/
double* read_data(char const *file_name, int *ptr_cnt);
/*!
@brief The function finds max grade out of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double  max(double const *begin, double const *end);
/*!
@brief The function finds min grade out of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double min(double const *begin, double const *end);
/*!
@brief The function finds average grade out of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double average(double const *begin, double const *end);
/*!
@brief The function finds the variance of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double variance(double const *begin, double const *end);
/*!
@brief The function finds the standard deviation of the grade array 
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double std_dev(double const *begin, double const *end);
/*!
@brief The function finds the median of the grade array using selection sort
Special scenarios: nil
@param double *base, int size
@return double
*//*_____________________________________________________________*/
double median(double *base, int size);
/*!
@brief The function sorts the values in acending order of value
Special scenarios: nil
@param double *base, int size
@return void
*//*_____________________________________________________________*/
void selection_sort(double *base, int size);
/*!
@brief The function finds the number of respective grades
and calculates the percentage of those grades with respect to the total no of 
grades.
Special scenarios: nil
@param double const *begin, double const *end, double *ltr_grades
@return void
*//*_____________________________________________________________*/
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades);
/*!
@brief The function swaps the values in the respective addresses
Special scenarios: nil
@param double* rhs, double* lhs
@return void
*//*_____________________________________________________________*/
void swap(double* rhs, double* lhs);
//enum that can beused if required
enum grade {A_GRADE = 0, B_GRADE = 1, C_GRADE = 2, D_GRADE = 3, F_GRADE = 4, TOT_GRADE = 5};