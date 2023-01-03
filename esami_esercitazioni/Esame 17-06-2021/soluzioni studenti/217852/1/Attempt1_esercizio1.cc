// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>
using namespace std;



bool controlloParola(char p[]){

	int cont=0;
	int contaNI=0;
	bool flagNI, flagMU, flagIM, flagG;
	flagIM=true;

	// Giovanni: il ciclo di controllo per le lettere I ed M dovrebbe arrivare
  // solo fino alla penultima lettera della parola e non fino alla fine. 
	for(int i=0; p[i]!='\0'; i++){
		cont++;

		if(p[i]=='I'){
			contaNI++;
			if(p[i+1]=='M')
				flagIM=false;
		}

	}

	if(p[0]=='M' && p[cont-1]=='U')
		flagMU=true;
	else
		flagMU=false;

	if(contaNI%2!=0 || contaNI==0)
		flagNI=true;
	else
		flagNI=false;

	if(flagNI && flagIM && flagMU)
		flagG=true;
	else
		flagG=false;

	return flagG;

}

int main(int argc, char * argv [])
{

	fstream input, outp;
	char buffer[100];

	if(argc!=3){
		cout << "errore numero argomenti" << endl;
		exit(0);
	}

	input.open(argv[1], ios::in);
	outp.open(argv[2], ios::out);

	if(input.fail() || outp.fail()){
		cout << "errore apertura file" << endl;
		exit(0);
	}

	bool check;

	while(input >> buffer){
		check=controlloParola(buffer);

		// Giovanni: da come leggo il tuo codice, qua dovrebbe essere !check, visto
		// che devi controllare se la parola non appartiene a MIU.
		if(check){
			outp << buffer << endl;
		}
	}

	input.close();
	outp.close();

  return 0;
}
