// GDT: Il codice ritorna il seguente errore se si prova ad eseguirlo
// *** stack smashing detected ***: <unknown> terminated
// Aborted (core dumped)
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento
// Vedere commenti nel codice


#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int stringlength(char* str);
bool isValid(char* str);
bool isAZ(char c);
bool is09(char c);
void slice(char* str, int start, int end,char* slicedstr);

int main(int argc, char* argv[]){

    if(argc != 3){
        cout<<"Il numero di argomenti passati all'avvio e' incorretto"<<endl;
    }
    else{
        //nomi primo e secondo file
        char *infilename = argv[1];
        char* outfilename = argv[2];

        //cout<<infilename<<endl;
        //cout<<outfilename<<endl;

        // apertura file input e output
        ifstream in_file;
        ofstream out_file;
        in_file.open(infilename);
        out_file.open(outfilename);

        if (in_file.is_open() && out_file.is_open()) { //file aperto correttamente

            char word[100];
            char line[100];
            int n_valid = 0;

            int counter = 0;

            // GDT: non hai nessuna garanzia che le linee contengano fino a 100 caratteri.
            // Poichè stiamo considerando delle sequenze, era sufficiente leggere parola
            // per parola il file, così anche non avresti dovuto scrivere funzioni ausiliarie.
            // while(in_file >> word) {...}
            while (in_file.getline(line, 100)) { //richiedo linea per linea dal file

                int starting = 0;
                for(int x=0; x<100; x++){ //scansiono ogni linea per una parola

                    if((line[x] == ' ') || (line[x] == '\n') || (line[x] == '\0')){

                        slice(line, starting, x-1, word);

                        n_valid = n_valid + isValid(word);

                        starting = x+1;
                    }
                }
            }

            out_file << n_valid<<endl;

        }
        else {
            cout << "L'apertura del file non e' avvenuta correttamente" << endl;
        }

        // chiusura file input e output
        in_file.close();
        out_file.close();
    }
    return 0;
}


bool isValid(char* str){    //codice fiscale valido

    char c_part[5]{};
    char n_part[13]{};

    //divido le due parti del codice fiscale
    int counter = 0;
    for(int x=0; x<stringlength(str); x++){
        if(x<4){
            c_part[x] = str[x];
        }
        else{
            n_part[counter] = str[x];
            counter++;
        }
    }

    //controllo se la prima parte è tutta maiuscolo
    int uppercases = 0;
    for(int x=0; x<stringlength(c_part); x++){

        if(isAZ(c_part[x])){
            uppercases++;
        }
    }

    //controllo se la second parte è tutta un numero
    int digits = 0;
    for(int x=0; x<stringlength(n_part); x++){

        if(is09(n_part[x])){
            digits++;
        }
    }

    return (uppercases == stringlength(c_part)) && (digits == stringlength(n_part));
}

bool isAZ(char c){
    return c >= 'A' && c<= 'Z';
}

bool is09(char c){
    return c >= '0' && c<= '9';
}

// GDT: Non serve. Esiste la funzione strlen di cstring
int stringlength(char* str){    //lunghezza stringa
    int length = 0;

    int x = 0;
    while(str[x] != '\0'){
        length++;
        x++;
    }

    return length;
}

void slice(char* str, int start, int end,char* slicedstr){  //prendo una fetta di una stringa

    int counter = 0;
    for(int x=start; x<end; x++){
        //GDT: alla fine della copia non aggiungi il carattere terminatore \0.
        // Per questa operazione era meglio usare strcpy. 
        slicedstr[counter] = str[x];
        counter++;
    }
}
