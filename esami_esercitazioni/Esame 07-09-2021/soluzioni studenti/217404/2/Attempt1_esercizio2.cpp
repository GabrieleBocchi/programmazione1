#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */

char * extract(char[]);
void extract_aux(char input[], char * res, int i, int e);


/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
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

/* Inserire qui sotto la definizione della funzione estract */

char * extract(char input []){



char * res = new char[DIM];
// MR: Cosa c'e' di non chiaro in "Le uniche assunzioni che si possono
// fare sull’input e su dimensioni di eventuali strutture/array
// utilizzate nel file di partenza fornito sono solo quelle
// espressamente specificate in questo testo (e NON quelle riportate
// nel file fornito, che sono SOLO indicative per consentire di
// svolgere l’esame).". Qui sta assumendo dimensione DIM, ma NON era
// previsto. Doveva calcolare dimensione! Inoltre, avrebbe dovuto
// mettere +1 per tenere in conto del fatto che c'e´ terminatore di
// stringa (e.g. non compare il carattere da togliere).
extract_aux(input, res, 0,0);



return  res;

}

/* Inserire qui sopra la definizione della funzione estract */



void extract_aux(char input [], char * res, int i, int e){

  if(input[i]!='\0'){

    std::cout << input[i] << '\n';

    if(input[i]!='$'){
      res[e]=input[i];

      extract_aux(input,res, i+1, e+1);

    }

    else if(input[i]=='$'){

      extract_aux(input,res,i+1,e);

    }

  }

}
