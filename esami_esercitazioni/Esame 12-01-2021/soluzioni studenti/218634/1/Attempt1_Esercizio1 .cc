// GDT: soluzione abbastanza complicata. Fare riferimento alla soluzione ufficiale
// per un esempio di svolgimento. Non viene effettuata la deallocazione dei nodi, quindi
// si genera memory leak. Inoltre, il controllo degli argomenti e dell'apertura degli
// stream dovrebbe essere sempre accompagnato da un messaggio di errore per l'utente (problema
// minore). 

#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
  char text[101];
  nodo* next = NULL;
};

void copiaStringa(char destinazione[], char sorgente[], int i=0){
  while(sorgente[i] != '\0'){
    destinazione[i] = sorgente[i];
    i++;
  }
}

bool contaLettere(char buffer[], int i=0){
  while(buffer[i] != '\0')
    i++;
  return (i > 4);
}

nodo* add(nodo* pointer, char buffer[]){
  nodo* newnodo = new nodo;
  copiaStringa(newnodo->text, buffer);
  newnodo->next = pointer;
  return newnodo;
}

void print(nodo* pointer, char* file_o){
  fstream output;
  output.open(file_o, ios::out);
  if(!output.fail()){
    while(pointer != NULL){
      output << pointer->text << " ";
      pointer = pointer->next;
    }
  }
}

int main(int argc, char* argv[]){
  nodo* first = NULL;
  fstream input;
  fstream output;
  char buffer[101];

  if(argc == 3){
    input.open(argv[1], ios::in);
    if(!input.fail()){
      input >> buffer;
      while(!input.eof()){
	if(contaLettere(buffer)){
	  first = add(first, buffer);
	}
	input >> buffer;
      }
    }
    input.close(); 
    print(first, argv[2]);
  }
  return 0;
}
