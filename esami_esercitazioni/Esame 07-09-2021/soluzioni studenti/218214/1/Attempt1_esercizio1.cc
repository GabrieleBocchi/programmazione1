#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    // Valore stimato
    const int MAX_LUNGHEZZA = 50;

    if (argc != 3)
    {
        cout << "Errore nel passaggio dei parametri\n";
        exit(1);
    }
    else
    {
        // Apro i files
        fstream input, output;
        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        // Controllo se l'operazione è andata a buon fine
        if (input.fail())
        {
            cout << "Errore durante l'apertura del file di input " << argv[1] << endl;
            input.close();
            output.close();
            exit(1);
        }

        char buffer[MAX_LUNGHEZZA];
        bool toLow = false;
        bool toUp = true;

        while (input >> buffer)
        {
            //Setto il primo carattere del testo in maiuscolo
            if (toUp == true)
            {
                buffer[0] = toupper(buffer[0]);
                toUp = false;
            }
            if (toLow == true)
            {
                buffer[0] = tolower(buffer[0]);
            }

            //Controllo se la parola seguente deve essere trasformata in minuscola
            int lunghezza = strlen(buffer);
            if (buffer[lunghezza - 1] == ',' || buffer[lunghezza - 1] == ':' || buffer[lunghezza - 1] == ';')
                toLow = true;
            else
                toLow = false;

            //Scrivo la parola nel file di output
            output << buffer << ' ';
        }

        // Chiudo gli stream di input e output
        input.close();
        output.close();
    }
    return 0;
}
