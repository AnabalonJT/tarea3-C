#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "player.h"
#include "card.h"

int checkSD(int* rolls){
    int sum=0;
    for (int i=0;i<(int)(sizeof(rolls)/sizeof(rolls[0]));i++){
    	if(rolls[i]>0 && rolls[i]<6) sum += rolls[i];
        if (sum == 15) return 1;
    }
    return 0;
}


//////ACA

void copyCard(Card original, Card copy){
	strcpy(copy.name,original.name);
	copy.def=original.def;
	copy.atk=original.atk;
}

char* duel(Card player, Card gm, int dp, int dg){
	int hitP=(player.atk*dp);
	int hitG=(gm.atk*dg);
	player.def-=hitG;
	gm.def-=hitP;
	if((player.def<=0 && gm.def<=0) || (player.def>0 && gm.def>0)) return "draw";
	else if(player.def<=0) return "gm";
	else if(gm.def<=0) return "player";
	return "draw";
}

///HASTA ACA

int main (){

	srand(time(NULL));
    FILE * archivo;
    // ahora creamos nuestro mazo
    archivo = fopen("cartas.txt","r");
    Card mazo[30];
    char * buff=malloc(sizeof(char)*30);
    char * token;
    int i=0;
    int j=0;
    printf("debug0\n");
    while(fgets(buff,15,archivo)!=NULL){
        printf("debug1\n");
    	token=strtok(buff," ");
    	if(j==0) strcpy(mazo[i].name,token);
    	j++;
    	while(token!=NULL){
    		token=strtok(NULL," ");
    		if(j==1){
				mazo[i].def=atoi(token);
				j++;
    		} 
    		if(j==2){
    			mazo[i].atk=atoi(token);
    			j=0;
    		} 
    	}
    	//printf("%s-%d-%d\n",mazo[i].name,mazo[i].def,mazo[i].atk);
    	i++;
    }
    printf("debug2\n");
    fclose(archivo);
    free(buff);
    
    Card mazoGM[5];
    for (int k=0; k<5;k++){
    	int ind=rand()%i;
    	mazoGM[k]=mazo[ind];	
    }
    
    Card preMazo[10];
    for (int k=0; k<10;k++){
    	int ind=rand()%i;
    	preMazo[k]=mazo[ind];	
    	printf("%d-%s-[%d]-[%d]\n",k,preMazo[k].name,preMazo[k].def,preMazo[k].atk);
    }
    
    printf("debug3\n");
    ////// DESDE ACA
    Card mazoJ[5];
    char * opcion= malloc(sizeof(char)*10);
    printf("seleccione 5 cartas:");
    scanf("%s",opcion);
    // separamos la opcion
    token=strtok(opcion,",");
    int op=0;
    int tok;
    while (token != NULL){
        tok=atoi(token);
        mazoJ[op]=preMazo[tok];
        token = strtok(NULL, ",");
        printf("-%s\n",mazoJ[op].name);
        op++;
    }
    free(opcion);

    printf("debug4\n");
    //Mazo creado post eleccion del jugador.
    
    
    int round=1;
    int pointsPlayer=0;
    int pointsGm=0;
    int dadoPlayer=0;
    int dadoGm=0;
    int dadosGm[5];
    int dadosPlayer[5];
   	char*  input= malloc(sizeof(char)*3);
   	char* outcome;
    
    while(round<6){
        printf("debug5\n");
        Card player;
        strcpy(player.name," ");
        player.atk=0;
        player.def=0;
        Card gm;
        strcpy(gm.name," ");
        gm.atk=0;
        gm.def=0;
		for (int k=0;k<5;k++){
			printf("%d-%s-[%d]-[%d]\n",k+1,mazoJ[k].name,mazoJ[k].def,mazoJ[k].atk);
		}
		printf("Seleccione Carta a Jugar");
        scanf("%s",input);
		i=atoi(input);
		copyCard(mazoJ[i],player);
		copyCard(mazoGM[rand()%5],gm);
		dadoPlayer=(rand()%6+1);
		dadosPlayer[round-1]=dadoPlayer;
		if(checkSD(dadosPlayer)){
			printf("Player Wins By SD");
			break;
		} 
		dadoGm=(rand()%6+1);
		dadosGm[round-1]=dadoGm;
		if(checkSD(dadosGm)){
			printf("Gm Wins By SD");
			break;
		}
        //funcion interfaz
        interfaz(player,gm,dadoPlayer,dadoGm,round,pointsPlayer,pointsGm);
        
		outcome=duel(player,gm,dadoPlayer,dadoGm);
		if(strcmp(outcome,"draw")) printf("Duel it's a Drwa");
		if(strcmp(outcome,"gm")){
			printf("Game Master wins Duel\n");
			pointsGm++;
		}
		if(strcmp(outcome,"player")){
			printf("Player wins Duel\n");
			pointsPlayer++;
		}
        round++;
		
	}
    free(input);
	return 0;
}
