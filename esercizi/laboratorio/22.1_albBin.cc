#include <iostream>
#include <fstream>
using namespace std;

struct nodo
{
    int value;
    nodo *figlioSinistra;
    nodo *figlioDestra;
};

nodo *radice;

void alberoInit();
void alberoInserisci(int n);
void stampaAlbero(nodo *root, int spazio = 0);
void stampaAlbero();
void alberoDeinit();

int main(int argc, char *argv [])
{
    if (argc != 2)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream file;
    file.open(argv[1], ios::in);
    if (file.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    int n;
    if (file >> n)
    {
        alberoInit();
        alberoInserisci(n);
        while (file >> n)
            alberoInserisci(n);
        cout << "Albero di ricerca binaria: " << endl << endl;
        stampaAlbero(radice);
        alberoDeinit();
    }
    file.close();
    return 0;
}

void alberoInit()
{
    radice = NULL;
    return;
}

void alberoInserisci(int n)
{
    nodo *nodoCorrente = radice;
    if (radice == NULL)
        radice = new nodo{n, NULL, NULL};
    else
    {
        while ((n < nodoCorrente->value && nodoCorrente->figlioSinistra != NULL) || (n > nodoCorrente->value && nodoCorrente->figlioDestra != NULL))
        {
            if (n < nodoCorrente->value)
                nodoCorrente = nodoCorrente->figlioSinistra;
            else
                nodoCorrente = nodoCorrente->figlioDestra;
        }
        if (n < nodoCorrente->value)
            nodoCorrente->figlioSinistra = new nodo{n, NULL, NULL};
        else
            nodoCorrente->figlioDestra = new nodo{n, NULL, NULL};
    }
    return;
}

void stampaAlbero(nodo *root, int spazio)
{
    if (root != NULL)
    {
        spazio++;
        stampaAlbero(root->figlioDestra, spazio);
        for (int i = 1; i < spazio; i++)
        {
            cout << "\t";
        }
        cout << root->value << "\n";
        stampaAlbero(root->figlioSinistra, spazio);
    }
    return;
}

void alberoDeinit()
{
    while (radice->figlioSinistra != NULL || radice->figlioDestra != NULL)
    {
        nodo *nodoCorrente = radice;
        while (nodoCorrente->figlioSinistra != NULL || nodoCorrente->figlioDestra != NULL)
        {
            if (nodoCorrente->figlioSinistra != NULL)
            {
                if (nodoCorrente->figlioSinistra->figlioSinistra == NULL && nodoCorrente->figlioSinistra->figlioDestra == NULL)
                {
                    delete nodoCorrente->figlioSinistra;
                    nodoCorrente->figlioSinistra = NULL;
                }
                else
                    nodoCorrente = nodoCorrente->figlioSinistra;
            }
            else if (nodoCorrente->figlioDestra != NULL)
            {
                if (nodoCorrente->figlioDestra->figlioSinistra == NULL && nodoCorrente->figlioDestra->figlioDestra == NULL)
                {
                    delete nodoCorrente->figlioDestra;
                    nodoCorrente->figlioDestra = NULL;
                }
                else
                    nodoCorrente = nodoCorrente->figlioDestra;
            }
        }
    }
    delete radice;
    return;
}