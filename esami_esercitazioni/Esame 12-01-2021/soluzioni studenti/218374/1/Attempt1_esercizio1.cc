// GDT: array[i] = parola non assegna correttamente le parole. Viene solo copiato il puntatore.
// Alla fine, la variabile array conterrà soltanto puntatori alla variable parola.
// Quando inserisci i valori nel file di output, dovresti anche mettere uno spazio tra le varie parole.
// Manca la deallocazione dell'array.
// Non era consentito utilizzare il tipo string (non veniva specificato nel testo d'esame, quindi era
// da considerarsi non utilizzabile).  

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  fstream input,output;
  
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  
  string * array = new string[10000];
  char parola[256];
  int cont = 0;
  int i=0;
  
  if(!input.fail()){
    if(argc <= 3){
      while(!input.eof()){
	input>>parola;
	
	while(parola[cont]){
	  cont++;
	}
	if(cont <= 100){
	  if(cont%2 == 0){
	    array[i] = parola;
	    cont = 0;
	    i++;
	  }
	}
      }
      for(int j = i-2; j > 0; j--){
	output<<array[j];
      }
       
    }else{
      cout<<"Argomenti non validi. Inserire un file input e uno per l'output"<<endl;
    }
  }else{
    cout<<"errore"<<endl;
  }
  return 0;
}
