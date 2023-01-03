// GDT: il codice non rispetta la consegna. Bisognava copiare nel file di output
// tutte le parole con lunghezza maggiore a 4. Nel tuo caso, anche le parole con lunghezza
// uguale a 4 vengono considerate. La condizione del ciclo dovrebbe essere k<5.

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){

	if(argc != 3){
		cout << "Input non valido";
		exit(0);
	}

	fstream input, output;
	input.open(argv[1], ios::in);
	output.open(argv[2], ios::out);
	if(input.fail()){
		cout << "File non trovato";
		exit(0);
	}

	int i=0;
	char mat[1000][100];
	while(input >> mat[i]){
		i++;
	}

	bool controllo=true;
	for(int j=(i-1); j>=0; j--){
		for(int k=0; k<4; k++){
			if(mat[j][k]=='\0') {
				k=4;
				controllo=false;
			}
		}
		if(controllo) output << mat[j] << " ";
		else controllo = true;
	}

	input.close();
	output.close();
	return 0;
}
