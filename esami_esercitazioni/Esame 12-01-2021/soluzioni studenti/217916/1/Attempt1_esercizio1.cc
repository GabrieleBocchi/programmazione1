// GDT: nella scrittura su file vai ad inserire parole in più. L'indice
// j dovrebbe essere uguale a i-2.

#include <iostream>
#include <fstream>
using namespace std;

int calcola_lunghezza(char parola[]);
void copia(char parola[], char parole[][101], int pos);

int main(int argc, char * argv [])
{
    if (argc != 3){
        cout << "Errore: usage " << argv[0] << " <input> <output>" << endl;
        exit(1);
    }
    fstream input, output;
    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);

    if (input.fail() || output.fail()){
        cout << "Errore nella specifica dei file" << endl;
        exit(2);
    }

    char parole [10000] [101];
    char parola[100+1];
    int i = 0;
    int len;

    while(!input.eof()){
        input >> parola;
        len = calcola_lunghezza(parola);

        if (len > 4){
            copia(parola,parole,i);
            i++;
        }
    }

    input.close();

    for (int j = i ; j>=0 ; j--){
        output << parole[j] << " ";
    }
    
    output.close();

  return 0;
}

int calcola_lunghezza(char parola[]){
    int res = 0;

    for(int i = 0 ; parola[i] != '\0' ; i++){
        res++;
    }

    return res;
}

void copia(char parola[], char parole[][101], int pos){

    for (int i = 0 ; parola[i] != '\0' ; i++){
        parole[pos][i]=parola[i];
    }
}
