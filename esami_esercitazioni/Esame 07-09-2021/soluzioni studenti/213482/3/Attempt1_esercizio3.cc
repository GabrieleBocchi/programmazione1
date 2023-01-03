#include <iostream>
#include "pila.h"


using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
 
 const int MAX=100;
 
 	// SB: indentazione non precisa, ma corretta la realizzazione delle funzioni ausiliarie
	void risolviLabirinto(int [][5], int, int);

	void stampaCella(cella c){
		cout<<'['<<c.indiceRiga<<','<<c.indiceColonna<<"] ";
	}
	void inserisci(int x,int y){
		cella c;
		c.indiceRiga=x;
		c.indiceColonna=y;
		push(c);
	}
	bool controllaEinserisci(int labirinto[][5],int& currX,int& currY,int nextX,int nextY){
		if(labirinto[nextX][nextY]==1){
			currX=nextX;
			currY=nextY;
			cella c;
			inserisci(currX,currY);
	}
	}


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test  

    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };
    
    

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece � sempre [0,0])   
    cout<<"Percorso: ";
    
    risolviLabirinto(labirinto, 4, 2); 
    
    
   
    return 0;
}

void risolviLabirinto(int labirinto[][5], int x, int y){
	init();
	int currX=0;
	int currY=0;
	int nextX=0;
	int nextY=0;
	int iterazione=0;
	
	inserisci(currX,currY);
	
	// SB: se il primo percorso che l'algoritmo trova è quello giusto, allora 
	//     il programma funzionerebbe (una volta completati anche i controlli
	//     per le celle a sinistra e in alto, qui commentati). Purtroppo, manca 
	//     la logica per tornare a celle precedenti in caso il percorso scelto 
	//     non sia quello corretto.
	while((currX!=x|currY!=y)&&iterazione<MAX){
		iterazione++;
		nextX=currX+1;
		if(nextX>=0&&nextX<5){
			if(controllaEinserisci(labirinto,currX,currY,nextX,currY)); //giu
			else{
				nextY=currY+1;
				if(nextY>=0&&nextY<5){
					if(controllaEinserisci(labirinto,currX,currY,currX,nextY));	//destra
					/*
					else{
						nextY=currY-1;
						if(nextY>=0&&nextY<5){
							if(controllaEinserisci(labirinto,currX,currY,currX,nextY));	//sinistra
							else{
								nextX=currX-1;
								if(nextX>=0&&nextX<5){
									if(controllaEinserisci(labirinto,currX,currY,nextX,currY)); //su
								}
							}
						}
					}
					*/
				}
			}
		}else{
			nextY=currY+1;
			if(nextY>=0&&nextY<5){
				if(controllaEinserisci(labirinto,currX,currY,currX,nextY));//destra
			}		
		}
	}

	// SB: stampa corretta 
	if(currX==x&&currY==y){
		while(!vuota()){
			cella c;
			top(c);pop();
			stampaCella(c);
		}
		
	}

	
	deinit();
}
