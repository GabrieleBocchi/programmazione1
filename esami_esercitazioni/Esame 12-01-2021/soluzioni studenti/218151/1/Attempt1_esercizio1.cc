// GDT: esercizio corretto. Non è il massimo vedere una funzione stampa() che
// dealloca anche della memoria. Ogni funzione deve avere uno scopo unico e non
// provocare effetti aggiuntivi "nascosti". 

#include <iostream>
#include <fstream>
using namespace std;

const long qta_parole = 10000;
const int qta_lettere = 100;

int inserisci (char ** testo, char inputfile[], long& indice);
void stampa(char ** testo, char outputfile[], const long indice);
int lunghezza(char * stringa);

int main(int argc, char * argv [])
{	
	int retval = 0;
	if (argc != 3) {
		cerr << "Usage <a.out> <input file> <output file>\n";
		retval = 1;
	}
	else {
		char ** testo = new (nothrow) char*[qta_parole];
		long indice = 0;
		retval = inserisci(testo, argv[1], indice);
		if (retval == 0) {
			stampa(testo, argv[2], indice);
		}
		delete[] testo;
	}
  return retval;
}

int inserisci (char ** testo, char inputfile[], long& indice) {
	int retval = 0;

	fstream input;
	input.open(inputfile, ios::in);

	if (input.fail()) {
		cerr << "Input file is not correct or doesn't exist\n";
		retval = 2;
	}
	else {
		while (!input.eof() && indice < qta_parole) {
			testo[indice] = new (nothrow) char [qta_lettere];
			input >> testo[indice];
			indice++;
		}
	}
	input.close();
	return retval;
}

void stampa(char ** testo, char outputfile[], const long indice) {
	fstream output;
	output.open(outputfile, ios::out);

	for (int i = indice-1; i >= 0; i--) {
		if (lunghezza(testo[i])%2 == 1) {
			output << testo[i] << " ";
		}
		delete[] testo[i];
	}
	output.close();
}

int lunghezza(char * stringa) {
	int res;
	for (res = 0; stringa[res]!= '\0'; res++) {
		;
	}
	return res;
}
