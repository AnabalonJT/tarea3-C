#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "card.h"

int main (int argc, char* argv[]){
    int nothing= argc; // son para que no me de error al compilar
    char* palabra = argv[0];
    printf("%d",nothing);
    printf("%s",palabra);

    PrintTest();
	return 0;
}
