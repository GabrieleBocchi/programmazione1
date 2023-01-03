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
void risolviLabirinto(int labirinto[6][6], int righe, int colonne);


// SB: se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  
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
    risolviLabirinto(labirinto, 2, 5);
   
    return 0;
}

void risolviLabirinto(int labirinto[6][6], int righe, int colonne)
{
    lista nuovalista = NULL;
    init();
    cella nuovacella;
    for(int i = 0; i < righe; i++)
    {
        bool found = false; 

        for (int j = 0; j < colonne && !found; j++)
        { 
            if(labirinto[i][j] == 1)
            { 
                found = true;
                nuovacella.indiceRiga = i;
                nuovacella.indiceColonna = j;
                push(nuovacella);
            }
        }
    }
    while(pop())
            {
                if(top(nuovacella)) {
                    int col = 0;
                    int rig = 0;
                    nuovacella.indiceColonna = col;
                    nuovacella.indiceRiga = rig;
                    pop();
                    cout << "[" << rig << "," << col <<  "]" <<  " ";
                }
            }

    deinit();
}

