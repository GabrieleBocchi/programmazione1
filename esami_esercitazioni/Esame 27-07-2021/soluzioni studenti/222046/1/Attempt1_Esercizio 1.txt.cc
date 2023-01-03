// GDT: il codice non da il risultato corretto per alcuni casi di test.
// Fare riferimeno alla soluzione ufficiale per un possibile svolgimento.
// vedere commenti nel codice.

#include <iostream>
#include <fstream>

using namespace std;

bool controllaCodice(char stringa[]);


int main(int argc, char * argv[])
{
    fstream input, output;

    if (argc!=3) {
        cerr << "Da linea di comando: ./a.out <input> <output> ";
        exit(0);
    }

    // GDT: non utilizzi i nomi dati dall'utente a linea di comando.
    input.open("input.txt",ios::in);
    output.open("output.txt",ios::out);

    if (input.fail()) {
        cerr << "Il file " << argv[1] << " non esiste ";
        exit(0);
    }


    char buffer[256];

    int nCodici=0;
    while(!input.eof())
    {
        input>> buffer;
        if(controllaCodice(buffer))
        {
            nCodici++;
        }

    }

    output<<nCodici;
    output.close();
    input.close();

    return 0;
}

bool controllaCodice(char stringa[])
{
    bool Codice=true;
    int indice=0;

    while(Codice)
    {
        if(indice<12)
        {
            // GDT: utilizzare codici ASCII non è consentito ed è anche
            // una pratica scorretta (come detto molte volte a lezione).
            // Bisogna fare la comparazione tra i caratteri!!
            if(stringa[indice]<48 || stringa[indice]>57)
            {
                Codice=false;
                return Codice;
            }
        }

        else if(indice>=12 && indice<16)
        {
            if(stringa[indice]<65 || stringa[indice]>90)
            {
                Codice=false;
                return Codice;
            }
        }

        else if(indice>=16)
        {
            return Codice;
        }

        indice++;
    }

// GDT: manca un return di controllo (come anche segnalato da -Wall)
}
