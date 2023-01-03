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
void risolviLabirinto(int [6][6], int, int);

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

void risolviLabirinto(int m [6][6], int j, int k){
    init();
    
    cella tmp;
    tmp.indiceColonna = 0;
    tmp.indiceRiga = 0;

    push(tmp);

    bool found = false;

    // SB: il codice non gestisce labirinti senza una soluzione (e.g., se la cella di destinazione è [0,1])
    //     poiché non tiene traccia delle celle già visitate.
    while (!found){
        if(top(tmp)){
            if(!(tmp.indiceRiga == j && tmp.indiceColonna == k)){
                m[tmp.indiceRiga][tmp.indiceColonna] = 0;

                if(tmp.indiceColonna+1 < 6 && m[tmp.indiceRiga][tmp.indiceColonna+1] == 1){
                    cella tmp2;
                    tmp2.indiceColonna = tmp.indiceColonna+1;
                    tmp2.indiceRiga = tmp.indiceRiga;
                    
                    push(tmp2);
                }
                else if (tmp.indiceColonna-1 >= 0 && m[tmp.indiceRiga][tmp.indiceColonna-1] == 1){
                    cella tmp2;
                    tmp2.indiceColonna = tmp.indiceColonna-1;
                    tmp2.indiceRiga = tmp.indiceRiga;

                    
                    push(tmp2);
                }
                else if(tmp.indiceRiga-1 >= 0 && m[tmp.indiceRiga-1][tmp.indiceColonna] == 1){
                    cella tmp2;
                    tmp2.indiceColonna = tmp.indiceColonna;
                    tmp2.indiceRiga = tmp.indiceRiga-1;

                    push(tmp2);
                }
                else if(tmp.indiceRiga+1 < 6 && m[tmp.indiceRiga+1][tmp.indiceColonna] == 1){
                    cella tmp2;
                    tmp2.indiceColonna = tmp.indiceColonna;
                    tmp2.indiceRiga = tmp.indiceRiga+1;

                    push(tmp2);
                }
                else{
                    pop();
                }
            }
            else{
                found = true;
            }
        }
    }

    // SB: stampa corretta
    if(found){
        cella tmp2;
        while(top(tmp)){
            pop();
            cout << "m[" << tmp.indiceRiga << "][" << tmp.indiceColonna << "], ";
        }
        cout << endl;
    }

    deinit();
}
