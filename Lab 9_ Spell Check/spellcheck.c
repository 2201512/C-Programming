/*!
@file spellcheck.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial Lab 9
@date 03/11/2022
@brief This file contain fucntions that does one of the following;
converts lowercase letters to uppercase; counts the no of words
with a certain letter; check spelling against a dictornary; check word length
count of a dictionary; and give info on longest, shortest, and count of word.
*//*_____________________________________________________________*/
#include <string.h>		// strcpy, strcmp, strlen                                   
#include <stdio.h>		// printf, fopen, fclose
#include <ctype.h>      // isspace
#include "spellcheck.h"//header file
/*!
@brief this function coverts lowercase letter to uppercase, for a string
Special scenarios: nil
@param char* string
@return char*
*//*_____________________________________________________________*/
char* str_to_upper(char* string)
{
    int count=0;
        while(strlen(string))
        {
            if (*string>='a'&& *string<='z')
            {
            *string -='a'- 'A';
            
            }
            count++;
            string++;
        }
        return string-count;
}

/*!
@brief this function counts and return no of characters starting with a certain
letter.
Special scenarios: nil
@param const char* dictionary(a.k.a text file of some sort), char letter
@return WordCount (defined in spellcheck.h)
*//*_____________________________________________________________*/
WordCount words_starting_with(const char* dictionary, char letter)
{
    long long unsigned int count = 0;
    int start = 1,casecheck, c;
    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
    return FILE_ERR_OPEN;
    }
    
    while((c  = fgetc(fp))!=EOF)
    {
        if(isspace(c))
        {
            start = 1;
        }
        if(start>0 && !isspace(c))
        {
            start = 0;
            if(letter == c)
            {
                count++;
            }
            else if(c>='a'&& c<='z')
            {
                casecheck = letter + ('a'-'A');

                if(c == casecheck)
                {
                    count++;
                }
                
            }
            else if(c>='A'&& c<='Z')
            {
                casecheck = letter - ('a'-'A');
                
                if(c == casecheck)
                {
                    count++;
                }   
            }
        }
    }
    fclose(fp);
    return count;
}
/*!
@brief this function checks if the spelling of an input word is correct 
in accordance to the dictionary, without carrying if the letter in uppercase.
Special scenarios: nil
@param const char* dictionary(a.k.a text file of some sort), const char* word
@return ErrorCode (defined in spellcheck.h)
*//*_____________________________________________________________*/
ErrorCode spell_check(const char* dictionary, const char* word)
{   
    FILE* fp = fopen(dictionary, "r");

    if(fp == NULL)
    {
    fclose(fp);
    return FILE_ERR_OPEN; //return error
    }
    char myword[128];
    int i = 0;
    for(i=0;*word!='\0';i++)
    {
        if(*word>='A'&& *word<='Z')
        {
            myword[i]=(*word+32);
        }
        else
        {
            myword[i]= *word;
        }
        word++;
    }
    myword[i] = '\n';
    myword[++i] = '\0';
    char array[128];//filelenght 
    while(fgets(array, sizeof(array), fp)!=NULL)
    {   
        if(strstr(array, myword))
        {
        fclose(fp);
        return WORD_OK;
        }

    }
    fclose(fp);
    return WORD_BAD;

}
/*!
@brief this function finds the no of each count of words and intented by the 
input vairable, and stores these values into an array.
Special scenarios: nil
@param const char* dictionary(a.k.a text file of some sort), 
WordCount lengths[], WordLength count
@return ErrorCode (defined in spellcheck.h)
*//*_____________________________________________________________*/
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count)
{
    
    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
    fclose(fp);
    return FILE_ERR_OPEN; //return error
    }
    char array[128];
    while(fgets(array,sizeof(array),fp)!=NULL)
    {
        array[strcspn(array, "\n")] = 0;
        if(strlen(array)<=count)
        {
            lengths[strlen(array)]++;
        }

    }

    fclose(fp);
    return FILE_OK;

}
/*!
@brief this function finds the no of words in the dictionary, and finds the 
count of the longest and shorted word.
Special scenarios: nil
@param const char* dictionary(a.k.a text file of some sort), 
DictionaryInfo* info (STRUCT)
@return ErrorCode (defined in spellcheck.h)
*//*_____________________________________________________________*/
ErrorCode info(const char* dictionary, DictionaryInfo* info)
{
    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
    fclose(fp);
    return FILE_ERR_OPEN; //return error
    }
    WordLength lng = 1;//est shortest
    int cnt = 0;
    WordLength shrt = 100; //est longest
    char array[128];
    while(fgets(array,sizeof(array),fp)!=NULL)
    {
        array[strcspn(array, "\n")] = 0;
        
        if(strlen(array)>lng)
        {
            lng = strlen(array);
        }
        if(strlen(array)<shrt)
        {
            shrt = strlen(array);
        }
        cnt++;
    }
    info->longest = lng;
    info->shortest = shrt;
    info->count = cnt;
    fclose(fp);
    return FILE_OK;

}