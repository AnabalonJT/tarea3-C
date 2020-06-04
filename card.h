#ifndef CARD
#define CARD

typedef struct Card{
    char name[20];
    int atk;
    int def;
} Card;

void interfaz(Card player,Card gm, int diceP,int diceGm, int round, int scoreP, int scoreGm);
#endif
