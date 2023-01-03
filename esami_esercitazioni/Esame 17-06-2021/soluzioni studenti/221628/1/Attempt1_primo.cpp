using namespace std;
#include <iostream>
#include <fstream>

const int DIM_PAROLA = 101;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Errore in linea di comando!" << endl;
        exit(1);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if (input.fail())
    {
        cout << "Errore in fase di apertura del file '" << argv[1] << "'!" << endl;
        exit(1);
    }
    else if (output.fail())
    {
        cout << "Errore in fase di apertura del file '" << argv[2] << "'!" << endl;
        exit(1);
    }

    char *parola = new char[DIM_PAROLA];

    while (input >> parola)
    {
        int i, cont_I = 0;
        bool ultima = false, stampa = true, lettera_dopo_M;

        //Controllo se la prima lettera sia una 'U'
        if (parola[0] == 'U')
        {
            ultima = true;
        }

        //Scorro la parola
        for (i = 0; parola[i] != '\0' && stampa == true; i++)
        {
            //Controllo che le lettere siano solo 'M', 'I', 'U'
            if ((parola[i] != 'M') && (parola[i] != 'I') && (parola[i] != 'U'))
            {
                stampa = false;
            }

            //Se la parola contiene una 'I', aumento il conteggio
            if (parola[i] == 'I')
            {
                cont_I++;
            }

            //Se la lettera è una 'M' controllo che la lettera successiva non sia una 'I'
            if (parola[i] == 'M')
            {
                lettera_dopo_M = true;
            }

            // Giovanni: qui dovrebbe essere parola[i+1] e dovresti anche controllare
            // che i+1 < strlen(parola).
            if (parola[i] == 'I' && lettera_dopo_M == true)
            {
                stampa = false;
            }
        }

        //Controlli finali
        if ((ultima == true && parola[i - 1] != 'M') || (cont_I % 2 == 1))
        {
            stampa = false;
        }

        if (stampa == true)
        {
            output << parola << endl;
        }
    }

    delete[] parola;

    input.close();
    output.close();

    return 0;
}
