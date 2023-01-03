#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool controlloStringa (char *);

int main (int argc, char * argv[]) {
    if (argc != 3) {
        cerr << "Usage: ./a.out <fileInput> <fileOutput>.\n";
        exit (0);
    }

    fstream input, output;
    input.open (argv[1], ios::in);
    if (input.fail ()) {
        cerr << "Il file " << argv[1] << " non esiste.\n";
        exit (1);
    }

    output.open (argv[2], ios::out);

    const int CARATTERI = 100;
    char buffer[CARATTERI];

    int count = 0;

    while (input >> buffer) {
        if (controlloStringa (buffer)) {
            count++;
        }
    }

    input.close ();
    output << count << endl;
    output.close ();
    return 0;
}

bool controlloStringa (char * parola) {
    bool check = true;
    for (int i = 0; parola[i] != '\0' && check; i++) {
        if (i == 4 || i == 9 || i == 14) {
            if (parola[i] != '-') {
                check = false;
            }
        }
        else {
            if (parola[i] < 'A' || parola[i] > 'Z') {
                check = false;
            }
        }
    }
    return check;
}