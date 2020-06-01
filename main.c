#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "player.h"
#include "card.h"

void obtener(int * p_l, int * c_p, FILE * f){
    *p_l = 0;
    int larga = 0;
    *c_p = 0;
    char buff = fgetc(f);
    while (buff != EOF){
        *p_l += 1;
        if(buff == '\n'){
            *c_p += 1;
            if (*p_l > larga){
                larga = *p_l;
            }
            *p_l = 0;
        }
        buff = fgetc(f);
    }
    *p_l = larga;
}

int checkSD(int* rolls){
    int sum=0;
    for (int i=0;i<(int)(sizeof(rolls)/sizeof(rolls[0]));i++){
        sum += rolls[i];
        if (sum == 15) return 1;
    }
    return 0;
}

int main (int argc, char* argv[]){
    FILE * archivo;
    int nothing= argc; // son para que no me de error al compilar
    char* palabra = argv[0];
    printf("%d\n",nothing);
    printf("%s\n",palabra);
    archivo = fopen("cards.txt","r");
    // para ahorrar memoria obtenemomos la cantidad de palabras y la palabra mas larga
    int palabra_mas_larga;
    int cantidad_de_palabras;
    obtener(&palabra_mas_larga,  &cantidad_de_palabras, archivo);
    fclose(archivo);
    
    // ahora creamos nuestro mazo
    archivo = fopen("cards.txt","r");
    char mazo[cantidad_de_palabras+1][palabra_mas_larga];
    char buff_s[palabra_mas_larga];
    int i=0;
    while(fgets(buff_s,palabra_mas_larga,archivo)!=NULL){
        strcpy(mazo[i],buff_s);
        i++;
    }
    // mazo creado, funcion que nos imprime el total del mazo
    printf("\n");
    fclose(archivo);
    for(int j = 0; j<i;j++) printf("%s", mazo[j]);
    printf("\n");
    // ahora sacamos 5 aleatorias para el gm y 10 para el jugador que eliga
    i=0;//vamos contando cuantas sacamos
    int cartA;
    int * selecion= NULL;// aqui vamos viendo cuales salen aleatorias podemos hace un mazo[selecion] de ahi, las primeras 5 son gm y las otras las mostramos al jugador
    for(i=0;i<15;i++){
        cartA=rand()%30;
        selecion[i]= cartA;
        printf("%d\n",cartA);
    }
    // generamos mazo mg
    char mazoMG[6][palabra_mas_larga];
    for(i=0;i<5;i++){
        strcpy(mazoMG[i],mazo[selecion[i]]);
    }
    // nos imprime la seleccion de nuetras cartas
    char lectura[palabra_mas_larga];
    char mazoP[6][palabra_mas_larga];
    
    while(i< 15){
        strcpy(lectura,mazo[selecion[i]]);
        printf(" -%d -%s",i, lectura);
        i++;
    }
    printf("seleccione 5 cartas ingresando su indice");
    printf("ingrese indice:");
    int opcion;
    i=0;// ocupamos varias veces i para reutilizar memoria(supongo)
    while(i<5){
        printf("ingrese indice:");
        scanf("%d", &opcion);
        i++;
        // deberiamos comprobar, aqui vamos eliguiendo las que seleccione en  mazoP
    }
    srand(time(NULL));
    int * diceP = NULL;
    for(int i=0;i<=5;i++){
        int diceRoll=rand()%6+1;
        diceP[i]=diceRoll;
        printf("%d\n",diceRoll);
    }
    printf("is SD: %d\n",checkSD(diceP));
    
    PrintTest();
	return 0;
}
