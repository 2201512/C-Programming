/*!
@file main.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial assignment 7
@date 22/10/2022
@brief This file contains the main function that encrpts and decrepts 
a specified text file using Vigenere's Cipher.
*//*_____________________________________________________________*/
#include <stdio.h>		// file and console I/O

#define INCLUDE_KEYWORD
#include "q.h"			// include declarations and the decryption keyword
/*!
@brief The funciton does encryption and decryption.The encrption and decreption
itself is done by the fuctions encrypt() and decrypt() respectively
Additionally, for decreption, the file word count is read using a nested loop,
and printed to stderr using fprintf().
To determine if the function will deccrpyt or encrypt, there is a ifdef stated, 
so if ENCRYPT is specified in the comipler thru e.g. -DENCRYPT in command prompt, 
it will only use the encrypt part on the function. Otherwise, it will always decrypt.
Special scenarios: specification on ENCRYPT
@param nil
@return int
*//*_____________________________________________________________*/
int main(void)
{	
	#ifdef ENCRYPT
		//encrypt part of function
		FILE * input = fopen("plain.txt", "r"); 
		int x = 0;
		int c;
		while((c = fgetc(input))!=EOF)
		{
			if(x>6)
			{
				x = 0;
			}
			char b = (char)c;
			encrypt(&b, key[x]);
			x++;
				
			
		}
		fclose(input);

	#else
		// decrepyt part of function
		FILE * input = fopen("cipher.txt", "r"); 
		int x = 0;
		int c;
		while((c = fgetc(input))!=EOF)
		{
			if(x>6)
			{
				x = 0;
			}
			char b = (char)c;
			decrypt(&b, key[x]);
			x++;
		}
		fclose(input);
		//word counter
		FILE * counter = fopen("out_plain.txt", "r");
		int count = 0, c1;
		int start=0;

		while((c1 = fgetc(counter))!=EOF)
		{
			if(c1 != ' ' && c1 != '\n' && c1 != '\t' && c1 != '\r') //start of a word
			{
			start = 1;
			}	
			if(start == 1 &&(c1 == ' ' || c1 == '\n' || c1 == '\t' || c1 == '\r')) //end of a word
			{
				count++; //adds to word count
				start = 0; //resets the start 
			}
		}
		fclose(counter);
		//print word count to stderr
		fprintf(stderr, "%s %d%s", "Words:", count, "\n");
		
	#endif

	return 0;
}
