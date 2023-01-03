// GDT: per leggere un file, è sempre meglio utilizzare dei cicli. La funzione scrivi
// implementata in modo ricorsivo non è il metodo ottimale e potrebbe causare anche degli
// errori (se il file di testo è molto grande ad esempio). 

#include <fstream>
#include <iostream>
using namespace std;

//DIM = dimensione massima per una parola + carattere terminatore
const int DIM = 101;

void scrivi(fstream &input, fstream &output);
bool parolaDispari(const char *);

int main(int argc, char *argv[]) {
    //controllo che il numero dei parametri corrisponda a quello richiesto
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <nome file input> <nome file output>" << endl;
        exit(0);
    }

    //apertura degli stream
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    //controllo se gli stream si sono aperti senza errori
    if (input.fail() || output.fail()) {
        cout << "Errore: almeno uno dei due file non si può aprire!" << endl;
        exit(-1);
    }

    scrivi(input, output);

    //chiusura stream
    input.close();
    output.close();

    return 0;
}

//controlla che il numero di elementi in un array di caratteri sia dispari
bool parolaDispari(const char *parola) {
    int contatore = 0;
    while (parola[contatore] != '\0')
        contatore++;

    return contatore % 2 != 0;
}

//scrive sul file di output le parole dispari in ordine inverso
void scrivi(fstream &input, fstream &output) {
    char buffer[DIM];

    //controllo di non aver raggiunto l'eof
    if (input >> buffer) {
        scrivi(input, output);

        //se la parola è dispari la scrivo in output
        if (parolaDispari(buffer)) {
            output << buffer << " ";
        }
    }
}
