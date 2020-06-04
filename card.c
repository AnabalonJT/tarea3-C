#include "card.h"
#include <stdio.h>

struct Card;
void interfaz(Card player, Card gm, int diceP, int diceGm, int round, int scoreP,int scoreGm){
    printf("\n");
    printf("  ╔═══════════════════════════════════════════════════╗\n");
    printf("  ║                      ROUND %d                      ║\n",round);
    printf("  ╚═══════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("  Game Master\n");
    printf("  ╔════╦═══════════════╗ ╔═══╗   ╔════╦═══════════════╗\n");
    printf("  ║ %d ║ %s\t\t ║ ║ %d ║   ║ %d ║ %s\t\t ║\n",gm.atk,gm.name,diceGm,player.atk,player.name);
    printf("  ╠════╩═══════════════╣ ╚═══╝   ╠════╩═══════════════╣\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║ %d - %d ║                    ║\n",scoreGm,scoreP);
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║                    ║         ║                    ║\n");
    printf("  ║               ╔════╣   ╔═══╗ ║               ╔════╣\n");
    printf("  ║               ║ %d ║   ║ %d ║ ║               ║ %d ║\n",gm.def, diceP,player.def);
    printf("  ╚═══════════════╩════╝   ╚═══╝ ╚═══════════════╩════╝\n");
    printf("                                                Jugador\n");
}
