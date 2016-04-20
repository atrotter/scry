#define BASE_SIZE 30

typedef struct Card
{
	int id;
	int val;
} Card;

typedef struct Deck
{
	Card cards[BASE_SIZE];
} Deck;

