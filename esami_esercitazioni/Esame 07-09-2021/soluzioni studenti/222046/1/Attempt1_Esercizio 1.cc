// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int controllaparola(char buffer[]);
char * convertimaiuscola(char buffer[]);
char * convertiminuscola(char buffer[]);

int main(int argc, char * argv[])
{
    fstream input, output;

    if (argc!=3) {
        cout << "Da linea di comando: ./a.out <input> <output> ";
        exit(0);
    }

    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);

    if (input.fail()) {
        cerr << "Il file " << argv[1] << " non esiste ";
        exit(0);
    }

    char buffer[256];

    input>> buffer;
    convertimaiuscola(buffer);
    output<<buffer<<" ";

    // GDT: manca una nuova lettura dall'input per leggere la seconda parola.
    input >> buffer;

    // GDT: la logica di questo while è un po' complicata e non è robusta a
    // certi tipi di input. Fare riferimento alla soluzione ufficiale per un esempio
    // di svolgimento. 
    while(!input.eof())
    {

        if(controllaparola(buffer)==1)
        {
            // GDT: non era richiesto dall'esercizio di convertire la prima lettera delle parole
            // non precedute dalla punteggiatura in maiuscolo.
            input>>buffer;
            convertimaiuscola(buffer);
        }
        else
        {
            input>>buffer;
            convertiminuscola(buffer);
        }
        output<<buffer<<" ";
    }

    output.close();
    input.close();

    return 0;

}
char * convertiminuscola(char buffer[])
{
    buffer[0]=tolower(buffer[0]);
    return buffer;
}

char * convertimaiuscola(char buffer[])
{
     buffer[0]=toupper(buffer[0]);
     return buffer;
}

int controllaparola(char buffer[])
{
    int lunghezza = strlen(buffer);

    if(buffer[lunghezza-1]==',' || buffer[lunghezza-1]==';' || buffer[lunghezza-1]==':')
    {
        return 0;
    }
    return 1;
}
