/*!
@file q.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial assignment 10
@date 18/11/2022
@brief This file contains the various functions used in qdriver.c, to caluclate
grades in various ways such as max min median e.t.c
*//*_____________________________________________________________*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "q.h"
#include <stdlib.h>
/*!
@brief The function opens the intended file, reads the values and counts the no
of grades present, and stores them into an array using malloc/calloc for use 
outside the function
Special scenarios: nil
@param char const *file_name, int *ptr_cnt
@return double *
*//*_____________________________________________________________*/
double *read_data(char const *file_name, int *ptr_cnt) {
    
    FILE *file = fopen(file_name, "r");
    if(file == NULL)
    {
        return NULL;
    }
    int position = 0;
    int checkspace = 0;
    int totalgrade = 0;
    int c = 0;
    double grade[4];
    int gradecounter = 0;
    double array[10000];

   
    for (int i = 0; array[i]; i++) {

        array[i] = '\0';
    }
    for (int i = 0; grade[i]; i++) {

        grade[i] = '\0';
    }

 
    while ((c = fgetc(file)) != EOF) {

        checkspace = isspace(c);
        char character = (char) c;

    
        if (checkspace == 0 && character != '.') {

        
            int ASCII = (int) character;
            double number = (double) ASCII - 48;
            grade[position] = number;

         
            if (position == 3) {

                long double sum = (grade[0] * 10) + grade[1] + (grade[2] * 0.1) + (grade[3] * 0.01);

                
                array[totalgrade] = (double) sum;

            
                totalgrade++;

                position = -1;
            }

            ++position;
        }
    }

    //Double pointer that allocates enough free space on the heap through calloc. By using calloc, we also set that memory space to 0. 
    //Store the entire double array in *p
    double *p = (double*)calloc(totalgrade, (sizeof(double)));

    for (int k = 0; array[k] != '\0'; k++) {

        *(p + k) = array[k];
        gradecounter += 1;
    }

    //Set ptr_cnt to the number of grades. This will point to the final address of the heap
    *ptr_cnt = gradecounter;

    fclose(file);

    
    if (p == NULL) {

        return NULL;
    }
    else {

        //Return the grades array stored in heap
        return p;
    }
}
/*!
@brief The function finds max grade out of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double  max(double const *begin, double const *end)
{
    double max = *begin;
    begin++;
    while(begin!= end)
    {
        if(max<*begin)
        {
            max = *begin;
        }
        begin++;
    }

    return max;
}
/*!
@brief The function finds min grade out of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double  min(double const *begin, double const *end)
{
    double min = *begin;
    begin++;
    while(begin!= end)
    {
        if(min>*begin)
        {
            min = *begin;
        }
        begin++;
    }

    return min;
}
/*!
@brief The function finds average grade out of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double  average(double const *begin, double const *end)
{
    double avg;
    double count = 0;
    while(begin!= end)
    {
        avg+= *begin;
        begin++;
        count++;
    }
    return (avg/count);
}
/*!
@brief The function finds the variance of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double  variance(double const *begin, double const *end)
{
    double var = 0;
    double avg =  average(begin, end);
    int count = 0;
    while(begin!= end)
    {
        var += pow((*begin - avg),2);
        begin++;
        count++;
    }
    var/=(count-1);
    return var;
}
/*!
@brief The function finds the standard deviation of the grade array
Special scenarios: nil
@param double const *begin, double const *end
@return double
*//*_____________________________________________________________*/
double  std_dev(double const *begin, double const *end)
{
    double std = sqrt(variance(begin, end));
    
    return std;
}
/*!
@brief The function finds the median of the grade array using selection sort
Special scenarios: nil
@param double *base, int size
@return double
*//*_____________________________________________________________*/
double median(double *base, int size)
{
    selection_sort(base, size);
    double med =0;
    if(size%2 ==0)//even
    {
        size/=2;
        med = *(base+size)/2 + *(base+(size-1))/2;
    }
    else if (size%2==1) //odd
    {
        size/=2;
        med = *(base+size);
    }
    med-=0.001;
    return med;
}
/*!
@brief The function swaps the values in the respective addresses
Special scenarios: nil
@param double* rhs, double* lhs
@return void
*//*_____________________________________________________________*/
void swap(double* rhs, double* lhs)
{
    double temp = *rhs;
    *rhs = *lhs;
    *lhs = temp;
}
/*!
@brief The function sorts the values in acending order of value
Special scenarios: nil
@param double *base, int size
@return void
*//*_____________________________________________________________*/
void selection_sort(double *base, int size)
{  
    for (int i = 0; i < (size - 1); i++) {

        for (int j = 0; j < (size - 1); j++) {

            if (*(base + j) > *(base + (j + 1))) {

                swap((base + j), (base + (j + 1)));
            }
        }
    }

}
/*!
@brief The function finds the number of respective grades
and calculates the percentage of those grades with respect to the total no of 
grades.
Special scenarios: nil
@param double const *begin, double const *end, double *ltr_grades
@return void
*//*_____________________________________________________________*/
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades)
{
    double a = 0, b=0, c=0, d=0, f=0;
    while(begin != end)
    {
        if(*begin>=90)//a
        {
            a++;
        }
        else if (*begin>=80 && *begin<90)//b
        {
            b++;
        }
        else if (*begin>=70 && *begin<80)//c
        {
            c++;
        }
        else if (*begin>=60 && *begin<70)//d
        {
            d++;
        }
        else if (*begin <60)//f
        {
            f++;
        }
        begin++;
    }
    double total = a+b+c+d+f;

    for(int i =0; i < 5; i++)
    {
        switch (i)
        {
            case 0:
                *(ltr_grades+i) = (a/total)*100;
                break;
            case 1:
                *(ltr_grades+i) = (b/total)*100;
                break;
            case 2:
                *(ltr_grades+i) = (c/total)*100;
                break;
            case 3:
                *(ltr_grades+i) = (d/total)*100;
                break;
            case 4:
                *(ltr_grades+i) = (f/total)*100;
                break;
        }
    }
}