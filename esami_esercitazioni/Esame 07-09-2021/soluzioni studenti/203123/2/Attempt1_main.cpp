#include <iostream>
#define MAX_WORDLEN 200

using namespace std;

/* Inserire qui sotto la dichiarazione della funzione extract */
char *extract(char *string);
/* Inserire qui sopra la dichiarazione della funzione extract */
int countDelete(char *string, int i, int counter);
void writeString(char *string, int i, int number);

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
char *extract(char *string){
	int size = countDelete(string, 0, 0);
	cout << "counter = " << size;
	char *extracted = new char[size]();
	// MR: Qui se ha trovato size "@" avrebbe dovuto allocare un
	// array di caratteri di size+1 per memorizzare il fine
	// stringa '\0'!, oppure avrebbe dovuto ritornare counter+1
	// quando incontraa \0 nella funzione countDelete!
	writeString(extracted, 0, size);
	return extracted;
}
/* Inserire qui sopra la definizione della funzione estract */
int countDelete(char *string, int i, int counter){
	if(string[i] == '\0'){
		return counter;
	}
	if(string[i] != '@'){
		return(countDelete(string, i+1, counter));
	}
	return(countDelete(string, i+1, counter+1));
}

void writeString(char *string, int i, int number){
	if(i < number){
		string[i] = '@';
		return writeString(string, i+1, number);
	}
	string[i] = '\0';
	// MR: In questa istruzione sta scrivendo in memoria non
	// allocata, infatti lei se trova N caratteri da eliminare,
	// alloca un array di size N non N+1 come richiesto per
	// memorizzare una stringa (c'e' lo \0)!
	return;
}
