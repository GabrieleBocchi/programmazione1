#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

bool isCode(char string[]);
bool checkChars(char string[]);
bool checkMinus(char string[]);
int length(char string[]);

const int MAX_LENGTH = 100;

int main(int argc, char* argv[]) {
    ifstream input;
    ofstream output;

    input.open(argv[1]);
    output.open(argv[2]);

    char buffer[MAX_LENGTH];
    int codeCounter = 0;

    while (input >> buffer) {
        if (isCode(buffer)) {
            codeCounter++;
        }
    }

    output << codeCounter << endl;

    input.close();
    output.close();
    return 0;
}

// questa funzione esegue 3 controlli per verificare il giusto formato della
// stringa, prima di tutto verifica che la lunghezza di quella un codice seriale
// (ossia 19, 16 cifre e 3 trattini), poi verifica che la stringa contenga solo
// numeri e trattini (aka minus) e che siano nella posizione corretta
bool isCode(char string[]) {
    bool res = true;
    if (length(string) != 19) {
        res = false;
    } else {
        if (!checkChars(string)) {
            res = false;
        }
        if (!checkMinus(string)) {
            res = false;
        }
    }
    return res;
}

// questa funzione scorre tutto l'array e verifica che gli unici carratteri
// facenti parte della stringa o sono cifre o sono '-'
bool checkChars(char string[]) {
    bool res = true;

    for (int i = 0; i < length(string); i++) {
        if ((string[i] < '0' || string[i] > '9') && string[i] != '-') {
            res = false;
        }
    }

    return res;
}

// check minus prima conta il numero di '-' presenti nella stringa, e se sono un
// numero diverso da 3 (ovvero quelli presenti in un codice seriale) imposta la
// variabile di ritorno a false. Inoltre verifica che siano posizionati
// correttamente, ossia come 5°,10° e 15° carattere
bool checkMinus(char string[]) {
    bool res = true;
    int minusCounter = 0;

    for (int i = 0; i < length(string); i++) {
        if (string[i] == '-') {
            minusCounter++;
        }
    }

    if (minusCounter != 3) {
        res = false;
    } else if (string[4] != '-' || string[9] != '-' || string[14] != '-') {
        res = false;
    }

    return res;
}

// utilizzo questa funzione aggiuntiva per calcolare le dimensioni della stringa
// data
int length(char string[]) {
    int counter = 0;

    while (string[counter] != '\0') {
        counter++;
    }
    return counter;
}