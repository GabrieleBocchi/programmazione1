// GDT: la soluzione proposta è corretta, però si va ad aprire più volte lo stesso
// file (non è necessario visto che il numero totale di parole massimo viene dato nella
// consegna). Manca il controllo per vedere se gli stream di input e output sono stati
// aperti correttamente. 

#include <iostream>
#include <fstream>
#define MAXWORDLENGTH 101 // 100 caratteri di dimensione massima + 1 di terminatore '\0'

using namespace std;

int strlen(const char[]);
void strcpy(const char origin[], char destination[]);
void invertedCopy(const char fileInput[], const char fileOutput[]);

int main(int argc, char * argv [])
{
  if(argc!=3){
    cout<<"Wrong usage! Try ./a.out <file_input> <file_output>"<<endl;
    exit(0);
  }
  invertedCopy(argv[1], argv[2]);
  return 0;
}

int strlen(const char word[]){
  int i;
  for(i=0; word[i] != '\0' && i<MAXWORDLENGTH; i++);
  return i;
}

void strcpy(const char origin[], char destination[]){
  for(int i=0; i<strlen(origin); i++){
    destination[i] = origin[i];
  }
}

void invertedCopy(const char fileInput[], const char fileOutput[]){
  fstream in;
  in.open(fileInput, ios::in);
  char tmpBuff[MAXWORDLENGTH]; 
  int nWords = 0;
  in>>tmpBuff;
  while(!in.eof()){
    if(strlen(tmpBuff) % 2 == 0){
      nWords++;
    }
    in>>tmpBuff;
  }
  in.close();
  in.open(fileInput, ios::in);
  char** words = new char*[nWords];
  in>>tmpBuff;
  int i = 0;
  while(i<nWords){
    if(strlen(tmpBuff)%2 == 0){
      words[i] = new char[strlen(tmpBuff)];
      strcpy(tmpBuff, words[i]);
      i++;
    }
    in>>tmpBuff;
  }
  in.close();
  fstream out;
  out.open(fileOutput, ios::out);
  for(int i=nWords-1; i>=0; i--){
    out<<words[i]<<" ";
    delete[] words[i];
  }
  out.close();
  delete[] words;
}

