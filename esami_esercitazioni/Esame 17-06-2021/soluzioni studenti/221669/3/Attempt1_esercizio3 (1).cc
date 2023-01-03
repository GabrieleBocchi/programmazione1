#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


albero generaAlbero(int numeroDiNodi = 10);
void stampaAlbero(albero radice, int spazio=0);

void StampaAlberoInOrdine(albero &root);
void deallocaAlbero(albero &root);
albero creaAlberoDiRicercaBinario(albero &alberoIniziale);
void inserisciNodiDispari(albero &alberoIniziale, albero &root);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale


    albero alberoIniziale = generaAlbero();
    //stampaAlbero(alberoIniziale); // nel caso in cui possa essere utile, la funzione "stampaAlbero" stampa graficamente l'albero a video

    albero alberoBinario = creaAlberoDiRicercaBinario(alberoIniziale);
    cout << "L'albero di ricerca binario è: ";
    StampaAlberoInOrdine(alberoBinario);
    cout << endl;

    deallocaAlbero(alberoIniziale);
    deallocaAlbero(alberoBinario);

    return 0;
}


albero generaAlbero(int numeroDiNodi) {
    
    // Se modificate la funzione "generaAlbero", ricordarsi poi di ripristinare il codice originale

    srand(time(NULL));
    nodo* nodi[numeroDiNodi];

    cout << "L'albero iniziale è:";

    for (int i = 0; i<numeroDiNodi; i++) {
        nodi[i] = new nodo;
        nodi[i]->value = rand() % 10;
        nodi[i]->left = NULL;
        nodi[i]->right = NULL;
        cout << " " << nodi[i]->value;
    }
    cout << endl;

    for (int i = 0; (2*i + 1)<numeroDiNodi; i++) {
        nodi[i]->left = nodi[2*i + 1];
        if ((2*i + 2) < numeroDiNodi) {
            nodi[i]->right = nodi[(2*i + 2)];
        }
    }

    return nodi[0];
}

void stampaAlbero(albero radice, int spazio) {

    // Se modificate la funzione "stampaAlbero", ricordarsi poi di ripristinare il codice originale

    if (radice != NULL) {
        spazio ++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++) {
            cout<<"\t";
        }
        cout<<radice->value<<"\n";

        stampaAlbero(radice->left, spazio);
    }
}


/* 
 * Inserire qui la definizione di "creaAlberoDiRicercaBinario", "StampaAlberoInOrdine", 
 * "deallocaAlbero" e di eventuali altre funzioni ausiliarie.
 */
albero creaAlberoDiRicercaBinario(albero &alberoIniziale)
{
    albero root = NULL;
    if (alberoIniziale != NULL)
    {
        inserisciNodiDispari(alberoIniziale,root);
    }

    return root;
}

// SB: alla funzione manca il passo ricorsivo in 3 casi (vedi sotto)
void inserisciNodiDispari(albero &alberoIniziale, albero &root)
{
    if (alberoIniziale != NULL)
    {
        if (alberoIniziale->value%2 != 0) //è dispari
        {
            // SB: manca lo passo ricorsivo
            if (root == NULL)
            {
                root = new nodo;
                root -> value = alberoIniziale->value;
                root -> left = NULL;
                root -> right = NULL;
            }
            else if (alberoIniziale->value <= root -> value)
            {
                // SB: manca lo passo ricorsivo
                if (root->left == NULL)
                {
                    root->left = new nodo;
                    root->left->value = alberoIniziale->value;
                    root->left = NULL;
                    root->right = NULL;
                }  
                else
                {
                    inserisciNodiDispari(alberoIniziale, root->left);
                }
            }
            else
            {
                // SB: manca lo passo ricorsivo
                if(root->right == NULL)
                {
                    root->right = new nodo;
                    root->right->value = alberoIniziale->value;
                    root-> right = NULL;
                    root->left = NULL;
                }
                else
                {
                    inserisciNodiDispari(alberoIniziale, root->right);
                }
            }
        }
        else
        {
            if (alberoIniziale->left != NULL)
            {
                inserisciNodiDispari(alberoIniziale->left, root);
            }
            else if(alberoIniziale->right != NULL)
            {
                inserisciNodiDispari(alberoIniziale->right, root);
            }
        }
        
        
    }
    
}

// SB: ok
void StampaAlberoInOrdine(albero &root)
{
    if (root != NULL)
    {
        StampaAlberoInOrdine(root->left);
        cout<< root->value;
        StampaAlberoInOrdine(root->right);
    }
}

// SB: ok
void deallocaAlbero(albero &root) //scorro prima a left poi a right e cancello tutti i nodi
{
    if (root != NULL)
    {
        deallocaAlbero(root->left);
        deallocaAlbero(root->right);
        delete root;
    }
    
}