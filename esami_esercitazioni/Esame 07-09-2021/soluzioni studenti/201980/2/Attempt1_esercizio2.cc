#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
void estrai(const char input_string[], int i, char out[], int indice);
char* extract(const char input[]);

/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char* extracted;
  char answer;


  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

char* extract(const char input[]) {
  char* output = new char[DIM + 1];
  // MR: Cosa c'e' di non chiaro in "Le uniche assunzioni che si
  // possono fare sull’input e su dimensioni di eventuali
  // strutture/array utilizzate nel file di partenza fornito sono solo
  // quelle espressamente specificate in questo testo (e NON quelle
  // riportate nel file fornito, che sono SOLO indicative per
  // consentire di svolgere l’esame).". Questo doveva essere calcolato!

  estrai(input, 0, output, 0);
  return output;
}
/* Inserire qui sotto la definizione della funzione estract */
void estrai(const char input_string[], int i, char output[], int indice){
    int contatore;
    char c= input_string[i];
    if(c=='\0'|| i==DIM){
        output[indice]= '\0';
    }else{
        if(c=='$'){
            contatore++;
            output[indice]=c;
            indice++;
        }
    }

   estrai(input_string,i+1,output,indice);
   // MR: Questa funzione va in ricorsione quasi infinita, risultando
   // in seg fault! Infatti la chiamata ricorsiva finale e' non
   // condizionata, e quindi presa sempre!
}

/* Inserire qui sopra la definizione della funzione estract */
