#include "deck.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int add_card(Deck *d, int id)
{
	if (d->cur_size == BASE_SIZE)
	{
		return(1);
	}
	d->cards[d->cur_size].id = id;
	d->cards[d->cur_size].val = 0;
	d->cur_size ++;
	return(0);
}

int add_card_pos(Deck *d, int id, int pos)
{
	if (pos < BASE_SIZE)
	{
		d->cards[pos].id = id;
		d->cards[pos].val = 0;
		return(0);
	}
	return(1);
}

int initialize_deck(Deck * d)
{
	int i;
	d->cur_size = 0;
	for (i = 0; i < BASE_SIZE; i++)
	{
		d->cards[i].id = -1;
		d->cards[i].val = 0;
		d->cur_size ++;
	}
	return(0);
}

int fill_deck_list(Deck * d, int * list)
{
	int i;
	for (i = 0; i < BASE_SIZE; i++)
	{
		add_card(d, list[i]);
	}
	return(0);
}

int fill_deck_random(Deck * d)
{
	int i;
	for (i = 0; i < BASE_SIZE; i++)
	{
		if (d->cards[i].id < 0)
		{
			d->cards[i].val = 0;
			d->cards[i].id = rand();
		}
	}
	return(0);
}

int main (int argc, char **argv)
{
	//Testing
	Deck d;
	initialize_deck(&d);
	srand(time(NULL));
	fill_deck_random(&d);
	printf("Size is %d.\n", d.cur_size);
	printf("First two cards are %d, %d.\n", d.cards[0].id, d.cards[1].id);
	
	int a[BASE_SIZE];
	int i;
	for (i = 0; i < BASE_SIZE; i++)
	{
		a[i] = rand();
	}
	Deck d2;
	d2.cur_size = 0;
	fill_deck_list(&d2, a);
	printf("Size is %d.\n", d2.cur_size);
	printf("First two cards are %d, %d.\n", d2.cards[0].id, d2.cards[1].id);
	return(0);
}
