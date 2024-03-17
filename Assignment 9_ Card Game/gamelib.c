/*!
@file gamelib.c
@author Yugendren S/O Sooriya Moorthi (2201512@sit.singapore.edu.sg)
@course RSE 1201
@tutorial assignment 9
@date 09/11/2022
@brief This file contains the various functions used in qdriver.c, to load a 
card game accordian, play it, and to print it. It also includes the additional 
function del_card to delete and reorder the cards for every iteration of the 
play loop
*//*_____________________________________________________________*/
#include <stdio.h>
#include "gamelib.h"
#include <string.h>

/*!
@brief The function replaces the value of the suit and rank for the given 
position in the array from the one after it, repeating the loop till all the 
values till the end are replaced .
Special scenarios: nil
@param Card game[], CardIndex position
@return void
*//*_____________________________________________________________*/
void del_card(Card game[], CardIndex position)
{
	int i = position;
	while(game[i].rank&& game[i].suit)
	{
	game[i].suit = game[i+1].suit;
	game[i].rank = game[i+1].rank;
	i++;
	}
}

/*!
@brief The function replaces all values in the array with 0. Then add the values
form str in to game array one by one, in order, for its lenght.
Special scenarios: nil
@param const char str[], Card game[]
@return void
*//*_____________________________________________________________*/
void load_game(const char str[], Card game[])
{	
	for(int k = 0; k<N;k++)
	{
		game[k].rank = 0;
		game[k].suit = 0;
	}

	int i = 0;
	for(int j = 0;j<(int)strlen(str);i++)
	{
	game[i].suit = str[j];
	j++;
	game[i].rank = str[j];
	j+=2;
	}
	
	//if required add a null byte
}

/*!
@brief The function check the array according to the game rules, calling 
del_card when required to replace the values, when the rules require it. 
Special scenarios: nil
@param Card game[]
@return void
*//*_____________________________________________________________*/
void play_game(Card game[])
{
	int i = 0;
	
		while(game[i].suit&& game[i].rank)
		{	while(1)
			{
				if(game[i].suit == game[i-3].suit || game[i].rank == game[i-3].rank)
				{
					game[i-3].suit = game[i].suit;
					game[i-3].rank = game[i].rank;
					del_card(game, (unsigned char)i);
					i-=3;
					continue;
				}
				else if(game[i].suit == game[i-1].suit || game[i].rank == game[i-1].rank)
				{
					game[i-1].suit = game[i].suit;
					game[i-1].rank = game[i].rank;
					del_card(game, (unsigned char)i);
					i--;
					continue;
				}
				break;	
			}
			i++;
		}
	
	}
/*!
@brief The function prints the values in the game array for both suit and rank
in their respective pairing, in the correct order.
Special scenarios: nil
@param const Card game[]
@return void
*//*_____________________________________________________________*/
void display_game(const Card game[])
{
	int i=0;
	while(game[i].suit&& game[i].rank)
	{
		printf("%c%c ", game[i].suit, game[i].rank);
		i++;
	}
	printf("\n");
	
}
