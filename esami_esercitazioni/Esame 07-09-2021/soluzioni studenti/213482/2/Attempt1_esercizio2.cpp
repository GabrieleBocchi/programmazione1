#include <iostream>
using namespace std;


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(char* input_string);
/* Inserire qui sopra la dichiarazione della funzione extract */

void  extract(char* input_string,char*& res,int& dim,int index);

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;
const char CHAR_ELIM='$';

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
char* extract(char* input_string){
	char* res;
	int dim=0;
	extract(input_string, res, dim, 0);
	return res;
}
/* Inserire qui sopra la definizione della funzione estract */

void  extract(char* input_string,char*& res,int& dim,int index){
res=new char[dim];
// MR: Qui ad ogni chiamata ricorsiva alloca un array di dimensione
// dim, ma non lo dealloca mai, se non nell'ultima chiamata. Quindi
// spreco di memoria, memory leak! Inoltre, mi pare che non stia
// allocando la slot per contenere il terminatore di stringa!
char c=input_string[index];
	if(c!='\0'){
		if(c!=CHAR_ELIM){
			int pos=dim;

			dim++;
			extract(input_string, res, dim, index+1);
			res[pos]=c;

		}
		else{
			extract(input_string, res, dim, index+1);
		}
		//cout<<input_string[index]<<endl;

	}
	// MR: Manca inserimento di terminatore di stringa in res per
	// renderla ben formata!
}
