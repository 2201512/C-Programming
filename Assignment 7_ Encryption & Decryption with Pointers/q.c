/*!
@file q.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial assignment 7
@date 22/10/2022
@brief This file contains the encrpyt() and decrypt() fucntion 
called in the mian function.
*//*_____________________________________________________________*/
#include <stdio.h>
#include "q.h"
/*!
@brief The funciton does encryption by using a key specified in q.h that passed to
this funciton from main. it add the key value to the ACSII value of the char passed 
form main, and passes the new char into a text file to be stored.
@param char* letter, char key
@return void
*//*_____________________________________________________________*/
void encrypt(char* letter, char key)
{
    int value = (int)(*letter + key);
    FILE * input = fopen("cipher.txt", "a+");
    if(value>127)
    {
        fputc((value-ASCII_COUNT), input);
    }
    else 
    {
        fputc((value), input);
    }

    fclose(input);  

}
/*!
@brief The funciton does decryption by using a key specified in q.h that passed to
this funciton from main. it subtrats the key value to the ACSII value of the char passed 
form main, and passes the new char into a text file to be stored.
@param char* letter, char key
@return void
*//*_____________________________________________________________*/
void decrypt(char* letter, char key)
{
    int value = (int)(*letter - key);
    FILE * input = fopen("out_plain.txt", "a+");
    if(value<0)
    {
        fputc((value+ASCII_COUNT), input);
    }
    else 
    {
        fputc((value), input);
    }

    fclose(input);  

}

