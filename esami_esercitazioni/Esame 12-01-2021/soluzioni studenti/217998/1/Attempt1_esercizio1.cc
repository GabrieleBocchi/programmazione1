// GDT: il codice non rispetta la consegna d'esame. Il programma doveva accettare
// da linea di comando il nome del file in input e in output.

#include <fstream>
#include <iostream>

using namespace std;

char *stringCopy(const char *strToCopy);
int stringLength(const char *str);

int main(int argc, char *argv[]) {
    char *words[10000];
    int readWords = 0;

    if (argc < 2) {
        cout << "Utilizzo: eseguibile <nomeFileInput>" << endl;
        return 1;
    }

    fstream inputFile;
    inputFile.open(argv[1], ios::in);

    if (!inputFile) {
        cout << "Impossibile aprire il file \"" << argv[1] << "\" in lettura" << endl;
        return 1;
    }

    fstream outputFile;
    outputFile.open("output.txt", ios::out);

    if (!outputFile) {
        cout << "Impossibile aprire il file \"output.txt\" in scrittura" << endl;
        return 1;
    }

    char buffer[100];
    while (inputFile >> buffer) {
        if (stringLength(buffer) <= 4) {
            words[readWords++] = stringCopy(buffer);
        }
    }

    for (int i = readWords - 1; i >= 0; i--) {
        outputFile << words[i] << (i == 0 ? "" : " ");
        delete[] words[i];
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

char *stringCopy(const char *strToCopy) {
    char *str = new char[stringLength(strToCopy) + 1];
    int currentChar = 0;

    while (*strToCopy != '\0') {
        str[currentChar++] = *(strToCopy++);
    }
    str[currentChar] = '\0';

    return str;
}

int stringLength(const char *str) {
    int length = 0;
    while (*str++ != '\0') {
        length++;
    }
    return length;
}
