// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

	if(argc != 3){cout << "Input non valido"; exit(0);}

	fstream input, output;
	input.open(argv[1], ios::in);
	if(input.fail()){cout << "File non trovato"; exit(0);}

	output.open(argv[2], ios::out);

	char c[101];	//parola del file
	char a;		//lett precedente a c[j]
	int i=0;	//contatore delle lett i
	bool controllo = true;

	input.getline(c, 101);
	while(!input.fail()){

		// Giovanni: la variabile a non viene mai inizializzata, difatto non
		// permettendo l'esecuzione corretta. Inoltre, manca la logica per assicurare
    // che a contenga il carattere j-1 della parola.
		int j;
		for(j=0; c[j] != ' '; j++){
			if(c[j] == 'I') i++;
			if(j>0 && a=='I' && c[j]=='M') controllo = false;
		}

		if(controllo == true && (i==0 || i%2==0)){
			if(c[0] == 'M'){
				if(c[j] == 'U') output << c;
			}
			else output << c;
		}

		input.getline(c, 101);

	}


	input.close();
	output.close();
	return 0;
}
