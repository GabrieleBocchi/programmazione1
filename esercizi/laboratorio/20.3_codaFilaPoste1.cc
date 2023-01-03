#include <iostream>
#include "20.3_codaFilaPoste.h"
using namespace std;

int main()
{
    init();
    int scelta;
    do
    {
        system("clear");
        cout << "Sistema di coda dell'ufficio postale!" << endl << endl;
        cout << "Inserire 1 se si vuole aggiungere una persona alla coda" << endl;
        cout << "Inserire 2 se si vuole rimuovere una persona dalla coda" << endl;
        cout << "Inserire 3 per visualizzare la situazione corrente" << endl;
        cout << "Scegliere: ";
        cin >> scelta;
        char nome[30];
        switch (scelta)
        {
            case 1:
            cout << endl << "Inserire il nome della persona che si vuole aggiungere: ";
            cin >> nome;
            if (enqueue(nome))
                cout << endl << "Persona aggiunta correttamente alla coda" << endl;
            else
                cout << "Non e' stato possibile aggiungere la persona alla coda" << endl;
            break;
            case 2:
            if (dequeue())
                cout << endl << "Persona rimossa correttamente dalla coda" << endl;
            else
                cout << endl << "Non e' stato possibile rimuovere la persona dalla coda" << endl;
            break;
            case 3:
            cout << endl << "Situazione attuale: " << endl << endl;
            print();
            break;
            default:
            cout << endl << "Numero inserito errato" << endl;
        }
        cout << endl << "Se si vuole lavorare ancora sulla coda inserire 1, altrimenti inserire un altro numero per uscire: ";
        cin >> scelta;
    } while (scelta == 1);
    deinit();
    return 0;
}