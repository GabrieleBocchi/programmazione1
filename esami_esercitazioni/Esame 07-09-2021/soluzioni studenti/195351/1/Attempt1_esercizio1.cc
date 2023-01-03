#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv[]) {

    fstream input, output;

    if (argc != 3) {
        cout << "Usage: ./a.out <sourcefile> <targetfile>" << endl;
    }
    else {

        input.open(argv[1], ios::in);

        if (input.fail()) {
            cerr << "Il file di input non esiste!" << endl;
        }
        else {

            output.open(argv[2], ios::out);

            if (output.fail()) {
                cout << "Errore in output" << endl;
            }
            else {
                char lettera;
                bool maiuscola = true;

                input >> noskipws;

                while (input >> lettera) {
                    if (maiuscola && lettera >= 'A' && lettera <= 'Z') {
                        maiuscola = false;
                    }
                    else if (maiuscola && lettera >= 'a' && lettera <= 'z') {
                        lettera += ('A' - 'a');
                        maiuscola = false;
                    }
                    else if (lettera == '.' || lettera == '?' || lettera == '!') {
                        maiuscola = true;
                    }

                    output << lettera;
                }

                input.close();
                output.close();
            }
        }
    }

    return 0;
}
