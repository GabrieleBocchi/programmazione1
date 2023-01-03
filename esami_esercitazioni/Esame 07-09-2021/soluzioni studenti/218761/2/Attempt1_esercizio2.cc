#include <iostream>

/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(const char input_string []);
/* Inserire qui sopra la dichiarazione della funzione extract */
void extract_aux(int index, const char input_string [], char* & out_string ,int maxDim, int & actualDim);
int strLun (int i, const char input_string[]);

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
char* extract(const char input_string []){
    char* str;
    int actualDim = 0;

    extract_aux(0, input_string, str, strLun(0,input_string), actualDim);
    str[actualDim] = '\0';

    return str;
}
/* Inserire qui sopra la definizione della funzione estract */

int strLun (int i, const char input_string[]){
    if(input_string[i] == '\0')
        return 0;
    else
        return 1 + strLun(i+1, input_string);
}

void extract_aux(int index, const char input_string [], char* & out_string ,int maxDim, int & actualDim){
    if(index >= maxDim){
        out_string = new char [actualDim];
	// MR: Manca spazio per terminatore di stringa!
    }
    else if(input_string[index] != '$'){
        int tmp = actualDim++;
        extract_aux(index+1, input_string, out_string, maxDim, actualDim);

        out_string[tmp] = input_string[index];
    }
    else
        extract_aux(index+1, input_string, out_string, maxDim, actualDim);
}
