#include <iostream>
#include <fstream>
using namespace std;

struct nodo
{
    int value;
    nodo *next;
};

void stampaListaInversaRic(nodo *lista);

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
        nodo *lista = new nodo{n, NULL};
        nodo *temp = lista;
        while (file >> n)
        {
            temp->next = new nodo;
            temp = temp->next;
            temp->value = n;
        }
        file.close();
        temp = lista;
        cout << "Lista inversa: " << endl << endl;
        stampaListaInversaRic(lista);
        while (lista != NULL)
        {
            temp = lista;
            lista = lista->next;
            delete temp;
        }
    }
    else
        cout << "Il file e' vuoto" << endl;
    return 0;
}

void stampaListaInversaRic(nodo *lista)
{
    if (lista == NULL)
        return;
    else
    {
        stampaListaInversaRic(lista->next);
        cout << lista->value << endl;
    }
    return;
}