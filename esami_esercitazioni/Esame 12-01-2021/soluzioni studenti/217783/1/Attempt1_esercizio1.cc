#include <iostream>
#include <fstream>
using namespace std;

void initMat(char **&matriceStringhe, int dim);
void deinitMat(char **&matriceStringhe, int dim);
void letturaFile (char **&matriceStringhe, char *file);

int main(int argc, char * argv [])
{
	if (argc != 3) {
		cout << "Inserire parametri: <./a.out> <input.txt> <output.txt>" << endl;
		exit(1);
	}
	
	int maxdim = 10000;
	char **matriceStringhe; //vettore di stringhe del file
	initMat(matriceStringhe, maxdim); //inizializzazione matrice
	
	letturaFile(matriceStringhe, argv[1]);
	
	int contatore; int stringaPari; int sottoIndice=0;
	fstream scrittura;
	scrittura.open(argv[2], ios::out); //apertura file output
	
	if (!(scrittura.is_open())) {
		cout << "Errore apertura file di output" << endl;
		exit(1);
	}
	
	for (contatore = maxdim-1; contatore >= 0; contatore--){
		
		//conto caratteri stringhe
		for (sottoIndice=0; sottoIndice<101 && matriceStringhe[contatore][sottoIndice] != '\0'; sottoIndice++);
		if ((sottoIndice % 2) == 0 && sottoIndice != 0) {
			scrittura << matriceStringhe[contatore] << " ";
		}
	}
	
	scrittura.close(); //chiusura file output
	deinitMat(matriceStringhe, maxdim);	//deallocazione matrice
	
  return 0;
}

void initMat(char **&matriceStringhe, int dim){
	
	matriceStringhe = new char*[dim];
	for (int i=0; i<10000; i++) {
		matriceStringhe[i] = new char[101];
	}
}

void deinitMat(char **&matriceStringhe,int dim){
	
	for (int i=0; i<dim; i++) {
		delete [] matriceStringhe[i];
	}
	
	delete [] matriceStringhe;
}

void letturaFile (char **&matriceStringhe, char *file){
	
	int indice=0; //indice di posizione per la matrice
	fstream lettura;	//apertura file
	lettura.open(file, ios::in);
	
	if (lettura.fail()) {
		cout << "Errore lettura file" << endl;
		exit(1);
	}
	
	while (lettura >> matriceStringhe[indice]) {
		indice++;
	}
	
	lettura.close(); //chiusura file
}
