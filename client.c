#include "deck.h"

#include <stdio.h>
#include <unistd.h>

int initialize_deck(Deck * d)
{
	int i;
	for (i = 0; i < BASE_SIZE; i++)
	{
		d->cards[i].id = i;
		d->cards[i].val = 0;
	}
	return(0);
}

int main (int argc, char **argv)
{
	Deck d;
	initialize_deck(&d);
	printf("%d\n", d.cards[4].id);
	return(0);
}
