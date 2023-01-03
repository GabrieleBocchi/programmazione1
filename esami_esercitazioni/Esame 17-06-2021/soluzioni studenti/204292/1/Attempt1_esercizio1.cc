// Giovanni: alcune condizioni sono errate. Ad esempio, la condizione 1 indica che,
// se la parola inizia con la lettera M, allora deve per forza terminare con la lettera U.
// Però, se la parola non inizia con la lettera U, allora quella condizione non si
// applica. Vedi commenti nel codice.

#include <iostream>
#include <fstream>
using namespace std;

const int dim = 101; //dim = 100 + 1, per aggiungere il carttere '\0'

int strlen (char a[]);

int main (int argc, char * argv [])
{

  fstream input, output;

  char buffer[dim];

  if (argc != 3){ //controllo numeri di argomenti
    cerr << "Usage: ./a.out <input> <<output>\n";
    exit (0);
  }

  input.open (argv[1], ios::in); //apertura stream di input

  if (input.fail()){ //controllo se l'apertura delllo stream fallisce oppure no
    cerr << "File non trovato\n";
    exit (0);
  }

  output.open (argv[2], ios::out); // apertura stream di output

  if (output.fail()){ //controllo se ho il diritto di scrivere nella directory
    cerr << "Non hai il permesso di scrive nella directory\n";
    exit (0);
  }



  while (input >> buffer){ //leggo e salvo nel buffer le parole presente in input

    bool conforme = false;
    char prima_lettera = buffer[0];
    int l = strlen (buffer);
    char ultima_lettera = buffer[l-1];
    int i = 0;

    // Giovanni: di default, conforme dovrebbe essere true (e dovresti cambiarlo a false
    // se una condizione NON è verificata). Infatti, parole come UUU sono comunque
    // valide, ma attualmente il tuo codice ritornerebbe falso.
    if (prima_lettera == 'M'){ // condizione 1
      if (ultima_lettera == 'U'){
	conforme = true;
      }
      else{
	conforme = false;
      }
    }

    if (conforme){ //condizione 2
      for (int j = 0; buffer[j] != '\0'; j++){
	if (buffer[j] == 'I'){
	  i++;
	}
      }

      if (i == 0 || i % 2 != 0){
	conforme = true;
      }
      else{
	conforme = false;
      }
    }

    bool lettera = false;
    if (conforme){ // condizione 3
      for (int k = 0; buffer[k] != '\0'; k++){
	if (buffer[k] == 'I'){
	  lettera = true;
	}

  // Giovanni: k dovrebbe essere k+1 in questo punto
	if (lettera){
	  char attuale = buffer[k];

	  if (attuale != 'M'){
	    conforme = true;
	  }
	  else{
	    conforme = false;
	  }
	  lettera = false;
	}
      }
    }

    //se la parola scritta in input e' conforme alle tre condizioni
    //la salvo nel file di output

    if (conforme){
      output << buffer << endl;
    }

  }

  //chiusura stream precedentemente aperti

  input.close();
  output.close();




  return 0;
}

int strlen (char a[]){

  int res = 0;

  for (int i = 0; a[i] != '\0'; i++){
    res++;
  }

  return res;
}
