#define BASE_SIZE 25

typedef struct Card
{
	int id;
	int val;
} Card;

typedef struct Deck
{
	Card cards[BASE_SIZE];
	int cur_size;
} Deck;

