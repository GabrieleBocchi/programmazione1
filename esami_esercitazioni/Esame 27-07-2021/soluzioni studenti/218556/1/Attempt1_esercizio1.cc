// GDT: il codice non da il risultato corretto per alcuni casi di test.
// Fare riferimeno alla soluzione ufficiale per un possibile svolgimento.
// vedere commenti nel codice.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 100;

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        ifstream input;
        ofstream output;

        input.open(argv[1]);
        output.open(argv[2]);
        if (input.fail() || output.fail())
        {
            cout << "Error opening files" << endl;
            exit(1);
        }
        char buffer[MAX];
        int counter = 0;
        while (input >> buffer)
        {
            bool pass = true;
            // GDT: l'idea è quasi corretta, però il tuo codice considera
            // valide anche stringhe composte da soli numeri, come 659.
            // Questo perchè manca il controllo che verifica se la stringa
            // è lunga 19 caratteri. 
            for (int i = 0; i < MAX; i++)
            {
                if (buffer[i] != '\0')
                {
                    if (i > 18)
                    {
                        pass = false;
                        i = MAX;
                    }
                    else if ((i + 1) % 5 == 0)
                    {
                        if (buffer[i] != '-')
                        {
                            pass = false;
                            i = MAX;
                        }
                    }
                    else if (!(buffer[i] <= '9' && buffer[i] >= '0'))
                    {
                        pass = false;
                        i = MAX;
                    }
                }
                else
                {
                    i = MAX;
                }
            }

            if (pass)
            {
                counter++;
            }
        }

        output << counter;

        input.close();
        output.close();
    }
    else
    {
        cout << "Missing params" << endl;
        exit(1);
    }

    return 0;
}
