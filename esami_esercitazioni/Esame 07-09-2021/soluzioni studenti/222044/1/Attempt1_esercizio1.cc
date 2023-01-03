// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
	if(argc!=3){
		cout<<"Usage: ./a.out input.txt output.txt"<<endl;
		exit(0);
	}
	fstream input,output;
	input.open(argv[1],ios::in);
	output.open(argv[2],ios::out);
	if(input.fail()){
		cout<<"Errore in apertura input"<<endl;
		exit(0);
	}
	bool maiusc=true;

	// GDT: la funzione input >> x, legge SOLO i caratteri di testo e quindi non
	// salva spazi/nuova riga etc. Per leggere tutti i caratteri possibili, avresti
	// dovuto usare la funzione getline().

	char x;
	char spazio='\n';
	input>>x;
	while(!input.eof()){
		if(!maiusc&&x!=spazio){
			x=tolower(x);
		}
		else if(maiusc&&x!=spazio){
			x=toupper(x);
			maiusc=false;
		}
		if(x=='.'||x=='!'||x=='?'){
			maiusc=true;
		}
		output<<x; // GDT: non leggendo gli spazi, lui va a scrivere tutto sulla stessa riga
		input>>x;

	}

  return 0;
}
