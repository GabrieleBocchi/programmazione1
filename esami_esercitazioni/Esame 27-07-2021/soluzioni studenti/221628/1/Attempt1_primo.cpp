using namespace std;
#include <iostream>
#include <fstream>

const int MAX_CARATTERI = 100+1;

int length(char* a);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Errore in linea di comando!" << endl;
        exit(1);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if (input.fail()) {
        cout << "Errore in fase di apertura del file '" << argv[1] << "'!" << endl;
        exit(1);
    }
    if (output.fail()) {
        cout << "Errore in fase di apertura del file '" << argv[2] << "'!" << endl;
        exit(1);
    }

    char seriale[] = {"CCCC-CCCC-CCCC-CCCC"};

    int cont_output = 0, l_seriale = length(seriale);
    char* parola = new char[MAX_CARATTERI];

    while (!input.eof()) {
        input >> parola;
        int l_parola = length(parola);
        bool out = true;
        int cont_gruppi = 0, cont_lettere = 0;

        if (l_seriale == l_parola) {

            for (int i = 0; parola[i] != '\0' && out == true; i++) {
                
                if (cont_lettere == 4 && parola[i] == '-') {
                    cont_gruppi++;
                    cont_lettere = 0;
                }
                else if (parola[i] >= 'A' && parola[i] <= 'Z') {
                    cont_lettere++;
                }
                else {
                    out = false;
                }

                if (cont_gruppi == 3 && cont_lettere > 4) {
                    out = false;
                }
            }

            if (cont_gruppi == 3 && cont_lettere == 4) {
                cont_output++;
            }
        }
    }

    output << cont_output << endl;

    delete[] parola;


    input.close();
    output.close();

    return 0;
}

int length(char* a) {
    int l = 0;
    while (a[l] != '\0')
        l++;

    return l;
}