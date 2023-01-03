// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXDIM = 200;

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        fstream input, output;
        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        if (input.fail() || output.fail())
        {
            cout << "Error opening files, exiting" << endl;
            exit(1);
        }
        else
        {
            char buffer[MAXDIM];
            bool maiuscolo = true;
            while (input >> buffer)
            {
                for (int i = 0; i < strlen(buffer); i++)
                {
                    // GDT: il codice qui assume che tutte le parole comincino con
                    // una lettera minuscola. In caso le parole abbiano una lettera
                    // maiuscola, la variabile maiuscolo non viene mai settata a false.
                    //
                    // Se allo script viene data la seguente stringa
                    // Ciao. Come va?
                    // Lui lo convertirà in:
                    // Ciao. Come Va?
                    // che è ovviamente sbagliato (va dovrebbe essere minuscolo).
                    if (i == 0 && maiuscolo && buffer[i] <= 'z' && buffer[i] >= 'a')
                    {
                        buffer[i] = buffer[i] + 'A' - 'a';
                        maiuscolo = false;
                    }

                    if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?')
                    {
                        maiuscolo = true;
                    }
                }

                // GDT: poteva andare benissimo anche output << buffer << " ".
                // Visto che il testo specifica che non ci sono caratteri nuova linea.
                char c;
                c = input.get();

                output << buffer << c;
            }

            output.close();
            input.close();
        }
    }
    else
    {
        cout << "Missing parameters" << endl;
    }
}
