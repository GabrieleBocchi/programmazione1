#include <iostream>


//funzione ausiliaria ricorsiva per il calcolo della lunghezza senza @
int finalLength(char[], int, int);

/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(char[]);     //wrapper

void extract1(char*, char[], int, int);     //funzione ricorsiva
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
//funzione wrapper
char* extract(char s[]){
  //chiamata a funzione ricorsiva per trovare la lunghezza senza @
  int length = finalLength(s, 0, 0);
  length++;

  char* rtn = new char[length];

  //chiamata a funzione ricorsiva per la copia della stringa
  extract1(rtn, s, 0, 0);

  return rtn;
}

//funzione ricorsiva
void extract1(char* rtn, char s[], int rtnIndex, int sIndex){
  if(s[sIndex] != '\0'){
    if(s[sIndex] != '@'){
      rtn[rtnIndex] = s[sIndex];
      rtnIndex++;
    }

    sIndex++;

    //chiamata ricorsiva
    extract1(rtn, s, rtnIndex, sIndex);
  }else
     rtn[rtnIndex] = '\0';
}

/* Inserire qui sopra la definizione della funzione estract */


//funzione ausiliaria ricorsiva per il calcolo della lunghezza senza @
int finalLength(char rtn[], int i, int length){
  if(rtn[i] != '\0'){
    if(rtn[i] != '@'){
      length++;
    }

    i++;
    length = finalLength(rtn, i, length);
  }

  return length;
}
