// GDT: la lunghezza del buffer è errata. Dovrebbe essere 10000. Questo causa
// alcuni errori in fase di test.

#include <iostream>
#include <fstream>
using namespace std;


int lunghezza(char parola[]);

int main(int argc, char *argv[]){
  if(argc !=3){
    cout << "Il numero di parametri inseriti è errato" << endl;
    cout << "Utilizzo: ./a.out <input_file> <output_file>" << endl;
    exit (0);
  }

  fstream input, output;

  input.open(argv[1],ios::in);

  if(input.fail()){
    cout << "C'è stato un errore nell'apertura del file \"" << argv[1] << "\"" << endl;
    exit(0);
  }

  output.open(argv[2], ios::out);

  char buffer[1000][101]={};
  int i;
  
  for(i = 0; input >> buffer[i]; i++);

  for(int j = i; j>=0; j--){
    if(lunghezza(buffer[j]) > 4)
      output << buffer[j] << " ";
  }
  
  input.close();
  output.close();
  return 0;
}


int lunghezza(char parola[]){
  int i;
  for(i = 0; parola[i]!='\0'; i++);
  return i;
}
