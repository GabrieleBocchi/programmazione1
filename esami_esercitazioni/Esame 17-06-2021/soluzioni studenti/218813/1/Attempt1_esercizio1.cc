// Giovanni: l'esercizio consegnato non compila.
//
// ./code/4/218813/Attempt1_esercizio1.cc: In function ‘int main(int, char**)’:
// ./code/4/218813/Attempt1_esercizio1.cc:57:24: error: a function-definition is not allowed here before ‘{’ token
//  bool is_MUI(char *word){
//                        ^
// ./code/4/218813/Attempt1_esercizio1.cc:104:1: error: expected ‘}’ at end of input
// }


#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool is_MUI(char *word);

int main(int argc, char* argv[]){

    //primo file
    char *infilename = argv[1];
    //secondo file
    char* outfilename = argv[2];

    cout << "Infile: " << infilename << endl;
    cout << "outfile: " << outfilename << endl;


    // apertura file input
    ifstream in_file;
    in_file.open(infilename);
	if( in_file.fail() ){
      cout << "IO Error: file not found " << endl;
    }else{

    // apertura file output
    ofstream out_file;
    out_file.open(outfilename);

    if (in_file.is_open() && out_file.is_open()) { //file aperto correttamente

        char line[100];
        while (in_file.getline(line, 100)) {

            if (!is_MUI(line)) {
                out_file << line << endl;
            }
        }
    }
    else {
        cout << "L'apertura del file non e' avvenuta correttamente" << endl;
    }

    // chiusura file input
    in_file.close();

    //chiusura file output
    out_file.close();


    return 0;
}


// funzione per la logica delle parole
bool is_MUI(char *word){

    bool control1 = false; //controllo lettere I
    bool control2 = false; //controllo lettera inzio U e fine M
    bool control3 = false; //controllo lettera successiva alla M

    int wordlength = strlen(word);

    //controllo lettere I
    int icounter = 0;
    for (int x = 0; x < wordlength; x++) {
        if (word[x] == 'I') {
            icounter++;
        }
    }

    if (icounter == 0 || (icounter % 2) == 0) {
        control1 = true;
    }


    //controllo lettera inzio U e fine M
    if (word[0] == 'U') {
        if (word[wordlength - 1] == 'M') {
            control2 = true;
        }
        else {
            control2 = false;
        }
    }
    else {
        control2 = true;
    }

    //controllo lettera successiva alla M
    int errori = 0;
    for (int x = 0; x < wordlength; x++) {
        if (word[x] == 'M' && word[x + 1] == 'I') {
            errori++;
        }
    }

    if (errori == 0) {
        control3 = true;
    }

    return control1 && control2 && control3;
}
