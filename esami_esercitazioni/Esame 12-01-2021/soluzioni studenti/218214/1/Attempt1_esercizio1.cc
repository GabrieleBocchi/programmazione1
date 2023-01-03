// GDT: il codice non esegue in modo corretto. Il fatto di avere la funzione write ricorsiva
// non è il modo migliore per approcciare il problema. In caso di file molto lunghi, si potrebbe
// incappare in errori poichè si esaurisce la memoria riservata nello stack delle funzioni. Meglio
// usare un ciclo. 
//
// Inizializzare sempre gli interi. La variabile count dovrebbe essere int count=0;
// Non è mai garantito che int count; inizializzi la variabile a zero di default. Questo è il
// motivo per cui il tuo codice non esegue correttamente.

#include <iostream>
#include <fstream>

//Zambon Silvio

using namespace std;

void write(fstream& in, fstream& out);

const int DIM_PAROLA = 100;

int main(int argc, char * argv []) {
    //Controllo il numero degli argomenti
    if (argc == 3) {
        //Inizializzo gli stream di input/output dei file
        fstream in, out;
        in.open(argv[1], ios::in);
        out.open(argv[2], ios::out);

        //Gestione errori apertura file
        if (in.fail() || out.fail()) {
            cout << "Errore nell'apertura dei file" << endl;
        } else {
            //Richiamo la funzione ricorsiva che stampa le parole
            write(in, out);

            //Chiudo gli streams
            in.close();
            out.close();
        }
    } else {
        cout << "Incorrect number of parameters" << endl;
    }

    return 0;
}

void write(fstream& in, fstream& out) {
    char parola[DIM_PAROLA];
    //Leggo la parola dal file
    in>>parola;

    //Se l'ultima lettura dal file non raggiunge la fine richiamo ricorsivamente
    //Per stampare al contrario
    if (!in.eof()) {
        write(in, out);
    }

    //Conto il numero di caratteri della parola
    int count;
    bool guardia = true;
    //Uso il for per iterare nel vettore ed avere un ulteriore controllo sulla lunghezza massima, oltre che sul terminatore
    for (int i = 0; i < DIM_PAROLA && guardia; i++) {
        if (parola[i] == '\0') {
            guardia = false;
        } else {
            count++;
        }
    }

    //Se il numero rispetta i requisiti la stampo, altrimenti no
    if (count <= 4) {
        out << parola << ' ';
    }
}
