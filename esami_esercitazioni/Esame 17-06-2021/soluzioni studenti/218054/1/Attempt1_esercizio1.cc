// Giovanni: il programma funziona correttamente, però la soluzione proposta
// è molto convoluta. Fai riferimento alla soluzione ufficiale per un possibile
// svolgimento che non usa liste concatenate.

#include <iostream>
#include <fstream>
using namespace std;

const int LETTERE = 100;

struct Node{
  char vet[LETTERE];
  Node * next;
};

void stampa(Node * list);
bool controllo(char vet[]);
int lunghezza(char vet[]);
void dealloca(Node * n);

int main(int argc, char * argv [])
{
  int i;
  fstream input,output;
  input.open(argv[1],ios::in);
  Node * list = NULL;
  char buffer[LETTERE];


  if(argc == 3){
    if(!input.fail()){

      while(!input.eof()){
        //cout << "Ciao" << endl;
        if(list == NULL){
          list = new Node;
          list -> next = NULL;
          input.getline(list -> vet,LETTERE);
          //input.getline(buffer,LETTERE);
          //cout << buffer << endl;
        }else{
          Node * s = list;
          Node * temp = new Node;
          temp -> next = NULL;
          input.getline(temp -> vet,LETTERE);
          //input.getline(buffer,LETTERE);
          //cout << buffer << endl;

          while(s -> next != NULL){
            s = s -> next;
          }
          s -> next = temp;
        }


      }

      //stampa(list);

      output.open(argv[2],ios::out);
      if(!output.fail()){
        for(Node * s = list; s != NULL; s = s -> next){
          if(controllo(s -> vet)){
          //cout << s -> vet << endl;
          output << s -> vet << endl;
          }
        }
      }else{
        cout << "Problema con il file 2";
      }



      //cout << lunghezza(list -> vet) << endl;

    }else{
      cout << "File 1 inesistente" << endl;
    }

  }else{
    cout << "<Wrong usage>" << endl;
  }

  dealloca(list);
  return 0;
}

void stampa(Node * list){
  for(Node * s = list; s != NULL; s = s -> next){
    cout << s -> vet << endl;
  }
}

bool controllo(char vet[]){
  bool res = true;
  int l = lunghezza(vet);
  int i = 0,j;
  int i_count = 0;

  if(vet[i] == 'U'){
    if(vet[l - 1] != 'M'){
      res = false;
    }
  }

  for(i = 0; vet[i] != '\0'; i++){
    if(vet[i] == 'I'){
      i_count++;
    }
  }
  if(i_count%2 != 0){
    res = false;
  }

  for(i = 0; vet[i] != '\0'; i++){
    if(vet[i] == 'M'){
      if(vet[i + 1] == 'I'){
        res = false;
      }
    }
  }

  return res;
}

int lunghezza(char vet[]){
  int res = 0;
  int i = 0;
  while(vet[i] != '\0'){
    i++;
    res++;
  }
  return res;
}


void dealloca(Node * n){
  while(n != NULL){
    Node * t = n;
    n = n -> next;
    delete(t);
  }
}
