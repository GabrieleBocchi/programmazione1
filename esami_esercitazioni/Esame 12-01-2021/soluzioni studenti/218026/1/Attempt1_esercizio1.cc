// GDT: fare riferimento alla soluzione ufficiale per un esempio di svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

// massima dimensione di una parola
#define MAX_DIM_PAROLA 100

struct node {
  char* word;
  node* next;
};

typedef node* pila;

void addWord(pila &n, char* nword);
bool getWord(pila &n, char* gword);
void pop(pila &n);
void dealloc(pila &n);
int conta_caratteri(char array[MAX_DIM_PAROLA]);
void print_pila(pila &n);

int main(int argc, char * argv [])
{
  //  Controlli input
  if (argc != 3) {
    cout << " Esegui il programma con " << argv[0] << " <file input> <file output>";
    exit(EXIT_FAILURE);
  }
  // Apertura e controlli files
  fstream input, output;
  
  input.open(argv[1], ios::in);
  if (input.fail()) {
    cout << " File input non esistente o non accessibile!" << endl;
    input.close();
    exit(EXIT_FAILURE);
  }

  output.open(argv[2], ios::out);
  if (output.fail()) {
    cout << " Impossibile aprire o creare il file output!" << endl;
    output.close();
    exit(EXIT_FAILURE);
  }

  pila words = NULL;

  char buffer[MAX_DIM_PAROLA];

  while (!input.eof()) {
    input >> buffer;
    if (conta_caratteri(buffer) > 4) {
      cout << " Parola rilevata da aggiungere da input: " << buffer << endl;
      addWord(words, buffer);
    }
      
  }

  cout << " Parole da salvare su file: " << endl;
  print_pila(words);



  // while (getWord(words, buffer))
  //   output << buffer;

  // dealloc(words);
  input.close();
  output.close();

  return 0;
}

void addWord(pila &n, char* nword) {
  cout << " Adding " << nword << endl;
  node* np = new (nothrow) node;
  if (np != NULL)  
  {
    // np->word = new char[conta_caratteri(nword)];
    np -> word = nword;
    np -> next = n;
    n = np;
    cout << " n->word: " << n->word << endl;
  }
  // delete[] np->word;
  // delete np;
}

bool getWord(pila &n, char* gword) {
  bool retval = true;
  if (n == NULL)
    retval = false;
  else {
    node* np = n->next;
    cout << " word inside: " << n->word << endl;
    gword = n -> word;
    cout << " gword = " << gword << endl;
    n = np;
    // delete np;
  }
  cout << " Got " << gword << endl;
  return retval;
}

void dealloc(pila &n) {
  delete[] n->word;
  if(n->next != NULL)
    dealloc(n->next);
}

int conta_caratteri(char* array) {
  int ncaratteri = 0;
  for(int i = 0; array[i] != '\0'; i++){
    ncaratteri++;
  }
  return ncaratteri;
}

void pop(pila &n) {
  if (n != NULL) {
		pila primoNodo = n;
		n = n->next;
		delete primoNodo;
	}
}

void print_pila(pila &n) {
  if (n != NULL) {
    cout << n->word << " ";
    print_pila(n->next);
  }
}
