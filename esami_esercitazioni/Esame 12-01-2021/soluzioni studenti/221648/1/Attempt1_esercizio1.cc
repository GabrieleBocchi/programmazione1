// GDT: fai riferimento alla soluzione ufficiale per un possibile svolgimento

#include <iostream>
#include <fstream>

using namespace std;

bool checkWord(char w[]);
void copyText(fstream &input, fstream &output);

int main(int argc, char* argv[]){
  fstream input, output;

  //controllo argomenti in input
  if(argc != 3){
    cout << "Specificare file di input e output." << endl;
    exit(0);
  }

  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  //controllo apertura file corretta
  if(input.fail() || output.fail()){
    cerr << "Errore nell'apertura dei file." << endl;
    exit(0);
  }

  copyText(input, output);

  input.close();
  output.close();

  return 0;
}

bool checkWord(char w[]){
  int i=0;
  
  while(w[i] != '\0'){
    i++;
  }

  return i <= 4 ? true : false;
}

void copyText(fstream &input, fstream &output){
  bool exit = false;
  char buffer[101];
  
  while(!exit){
    input >> buffer;

    if(input.eof()){
      exit = true;
    }else{
      if(checkWord(buffer))
	output << buffer << " ";    
    }
  }
}
