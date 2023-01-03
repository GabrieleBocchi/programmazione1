#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool controlla (char parola[]);

int main(int argc, char * argv []){

  //creo l'array contenente le lettere che formano una parola che estrarrò dal file (100 +1 per il carattere '\0')
  char parola[101];
  
  //controllo che gli argomenti passati da linea di comando siano tutti
  if(argc != 3){
    cout << "Usage <file_input> <file_output>" << endl;
    exit(1);
  }

  fstream input, output;

  //apro il file di input e controllo che esista
  input.open(argv[1], ios::in);

  if (input.fail()){
    cout << "Il file di input non esiste" << endl;
    exit(1);
  }

  //creo un contatore per i codici seriali
  int cont = 0;

  //leggo la prima parola
  input >> parola;

  //ora leggo tutte le parole presenti nel file finchè non arrivo al termine
  while(!input.eof()){
    
    //ora richiamo la funzione controlla 
    if(controlla(parola)){
      cont++;
    }
    
    input >> parola;
  }
  
  input.close();

  //terminata la lettura del file, scrivo nel file di output il numero di codici
  output.open(argv[2], ios::out);
  
  if (output.fail()){
    cout << "Il file di output non esiste" << endl;
    exit(1);
  }

  output << cont;

  output.close();

  return 0;
}

//funzione che controlla se le parole passate sono un codice seriale
bool controlla (char parola[]){
  bool esito = true;

  //inizio con i controlli di lunghezza
  if(strlen(parola) != 19){
    esito = false;
  }
  else{

    //controllo la presenza di - e delle lettere maiuscole
    int pos = 0;

    while (esito && pos <= 18){

      //controllo -
      if (pos == 4 || pos == 9 || pos == 14){
        if(parola[pos] != '-'){
          esito = false;
        }
      }
      //controllo lettera maiuscola
      else{
        if(parola[pos] < 'A' || parola[pos] > 'Z'){
          esito = false;
        }
      }
      pos++;      
    } 
  }

  return esito;
}