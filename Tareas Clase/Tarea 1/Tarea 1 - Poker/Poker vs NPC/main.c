#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TAM 52

typedef struct CARTA{
int valor;
char pinta[9];
int numero;
}carta;

char tr[]="Trebol";
char pi[]="Pica";
char co[]="Corazon";
char di[]="Diamante";
char vacio[]="-1";

int existeElemento(int elemento[TAM],int longitud, int numero);

int main(){

    srand(time(NULL));
    carta mazo[TAM];
    carta mazoTemp[TAM];

    carta mano[5];
    carta croupier[5];

    int mazoOrdenado[TAM];
    bool cartaUsada[TAM];

    for(int i=0;i<TAM;i++){
        cartaUsada[i]=false;
    }

    for(int i=0;i<TAM;i++){
        mazoOrdenado[i]=i;
    }

    int index=0;
    for(int i=0;i<TAM;i++){
        do{
            index = (rand()%52);
        }
        while(cartaUsada[index]);
        (mazo[i].numero)=mazoOrdenado[index];
        cartaUsada[index]=true;
    }

    for(int i=0;i<TAM;i++){
        switch(mazo[i].numero){

        case 0 ... 12:
            strcpy(mazo[i].pinta,tr);
            (mazo[i].valor)=(mazo[i].numero)+1;
            break;

        case 13 ... 25:
            strcpy(mazo[i].pinta,pi);
            (mazo[i].valor)=(mazo[i].numero)-12;
            break;

        case 26 ... 38:
            strcpy(mazo[i].pinta,co);
            (mazo[i].valor)=(mazo[i].numero)-25;
            break;
        case 39 ... 51:
            strcpy(mazo[i].pinta,di);
            (mazo[i].valor)=(mazo[i].numero)-38;
            break;
    }
    printf("%i, %s\n",(mazo[i].valor),(mazo[i].pinta));

    }

    for(int i=0;i<5;i++){
        mano[i].valor = mazo[0].valor;
        strcpy(mano[i].pinta,mazo[0].pinta);

        carta temp;

        int x=0;
        while(x<52){
            if(x!=51){
            (mazo[x].valor)=(mazo[x+1].valor);
            strcpy((temp.pinta),(mazo[x+1].pinta));
            strcpy((mazo[x].pinta),(temp.pinta));
            (mazo[x].numero)=(mazo[x+1].numero);
            }
            x++;
        }

        (mazo[51].valor)=-1;
        strcpy(mazo[51].pinta,vacio);
        (mazo[51].numero)=-1;

        if(i==0){
        printf("\nTu mano es:\n");
        }
        printf("%i, %s\n",(mano[i].valor),(mano[i].pinta));
    }

    for(int i=0;i<5;i++){
        croupier[i].valor = mazo[0].valor;
        strcpy(croupier[i].pinta,mazo[0].pinta);

        carta temp;

        int x=0;
        while(x<52){
            if(x!=51){
            (mazo[x].valor)=(mazo[x+1].valor);
            strcpy((temp.pinta),(mazo[x+1].pinta));
            strcpy((mazo[x].pinta),(temp.pinta));
            (mazo[x].numero)=(mazo[x+1].numero);
            }
            x++;
        }

        (mazo[51].valor)=-1;
        strcpy(mazo[51].pinta,vacio);
        (mazo[51].numero)=-1;

        if(i==0){
        printf("\nLa mano del Croupier es:\n");
        }
        printf("%i, %s\n",(croupier[i].valor),(croupier[i].pinta));
    }


    printf("\nLa baraja restante es:\n");

    for(int i=0;i<TAM;i++){
        printf("%i, %s\n",(mazo[i].valor),(mazo[i].pinta));
    }



    return 0;
}



