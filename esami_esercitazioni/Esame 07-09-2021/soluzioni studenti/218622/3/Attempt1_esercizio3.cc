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
void risolviLabirinto(int [][6], int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[6][6] = {
        { 1, 0, 1, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0 },
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 4, 2);
   
    return 0;
}

void risolviLabirinto (int labirinto [][6], int j, int k){
    init();

    cella indici, incrocio;
    indici.indiceRiga = 0;
    indici.indiceColonna = 0;
    push (indici);
    
    int controllo = 1;
    int riga = 0, colonna = 0;

    indici.indiceRiga = 40;
    indici.indiceColonna = 40;

    while (riga != j && colonna != k){    
        if (controllo == 0){
            riga = j;
            colonna = k;
        }

        else {            
            
            indici.indiceRiga = riga;
            indici.indiceColonna = colonna;
            push (indici);
            indici.indiceRiga = 0;
            indici.indiceColonna = 0;

            controllo = 0;
            
            // SB: alla prima iterazione, le variabili "riga" e "colonna" sono entrambe uguali a 0.
            //     Per questo motivo, la condizione "riga != indici.indiceRiga" sarà sempre falsa e
            //     nessuno delle istruzioni condizionali qui sotto verrà eseguita. Alla seconda iterazione,
            //     la variabile "controllo" sarà uguale a 0, entrando quindi nell'if in riga 55 e terminando
            //     il ciclo.
            if (labirinto [riga+1][colonna] == 1 && riga != indici.indiceRiga && colonna+1 != indici.indiceColonna){
                riga += 1;
                controllo += 1;
            }
            else if (labirinto [riga][colonna+1] == 1 && riga != indici.indiceRiga && colonna+1 != indici.indiceColonna){
                colonna += 1;
                controllo += 1;
            }
            else if (labirinto [riga-1][colonna] == 1 && riga != indici.indiceRiga && colonna+1 != indici.indiceColonna){
                riga -= 1;
                controllo += 1;
            }
            else if (labirinto [riga][colonna-1] == 1 && riga != indici.indiceRiga && colonna+1 != indici.indiceColonna){
                colonna -= 1;
                controllo += 1;
            }

        }  
    }

    // SB: stampa corretta
    while (top(indici)){
            cout << "[" << indici.indiceRiga << ", " << indici.indiceColonna << "], ";
            pop();    
    }

    deinit();
    

    return;
}
