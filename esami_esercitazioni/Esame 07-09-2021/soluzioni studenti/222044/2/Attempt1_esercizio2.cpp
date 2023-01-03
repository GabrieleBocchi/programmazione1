#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */

/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

char* extract(char* input_string,char* extracted,int x,int i);

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char answer;
  int x,i=0;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;
    char* extracted;
    extracted=extract(input_string,extracted,x,i);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char* extract(char* input_string,char* extracted,int x,int i){
  // MR: La funzione doveva avere un solo argomento, la stringa da
  // analizzare! Qui ce ne sono diversi...
	if(input_string[x]=='\0'){
		return extracted;
		// MR: Dove e´ allocata?
	}
	else if(input_string[x]=='@'){
		extracted[i]=input_string[x];
		// MR: Prima di scrivere devo allocare la memoria!
		return extract(input_string,extracted,x+1,i+1);
	}
	else {
	extracted[i]=input_string[x];
	// MR: Prima di scrivere devo allocare la memoria!
	return extract(input_string,extracted,x,i+1);
	}

}
/* Inserire qui sopra la definizione della funzione estract */
