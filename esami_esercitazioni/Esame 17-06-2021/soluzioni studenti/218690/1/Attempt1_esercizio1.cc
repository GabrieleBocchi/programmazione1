// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>
#define MAXSTRINGLENGTH 101 //100 + terminatore

using namespace std;
void MIU(char* inFile, char* outFile);
bool MIUCheck(char* word);
int strLen(char* word);

int main(int argc, char * argv [])
{
  if(argc <3){
    cout<<"Wrong usage... Try ./a.out [input] [output]"<<endl;
    exit(0);
  }
  MIU(argv[1], argv[2]);
  return 0;
}

int strLen(char* word){
  int i=0;
  for(; word[i] != '\0'; i++);
  return i;
}

bool MIUCheck(char* word){
  cout<<"Word: "<<word<<endl;
  bool ret = true;
  if(word[0] == 'U' && word[strLen(word) - 1] != 'M'){
    ret = false;
    cout<<"Starting with U and not ending with M"<<endl;
  }
  int iCounter = 0;
  bool foundM;
  for(int i=0; i<strLen(word) && ret; i++){
    if(word[i] == 'I'){
      iCounter++;
    }
    // Giovanni: foundM non viene mai settato a false una volta
    // trovata una lettera M. Il controllo infatti deve essere fatto solo
    // per la lettera successiva ad M e non per tutte le altre.
    if(foundM && word[i] == 'I'){
      ret = false;
      cout<<"M succeded by I"<<endl;
    }
    if(word[i] == 'M' && !foundM){
      foundM = true;
    }
  }
  if(ret && iCounter%2 == 1){
    ret = false;
    cout<<"Number of I = "<<iCounter<<endl;
  }
  return ret;
}

void MIU(char* inFile, char* outFile){
  fstream input;
  input.open(inFile, ios::in);
  if(input.fail()){
    cout<<"Error during the opening of the input file. Terminating..."<<endl;
    exit(0);
  }
  fstream output;
  output.open(outFile, ios::out);
  if(output.fail()){
    cout<<"Error during the opening of the output file. Terminating..."<<endl;
    input.close();
    exit(0);
  }
  char buffer[MAXSTRINGLENGTH];
  input>>buffer;
  while(!input.eof()){
    if(MIUCheck(buffer)){
      output<<buffer<<endl;
    }
    input>>buffer;
  }
  input.close();
  output.close();
}
