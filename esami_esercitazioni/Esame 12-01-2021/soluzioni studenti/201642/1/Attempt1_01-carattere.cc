// GDT: il codice non esegue correttamente. Stai inoltre utilizzando una libreria
// non ammessa. Fai riferimento alla soluzione ufficiale per un possibile svolgimento
// dell'esercizio.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv[])
{

  if (argc != 3){
    std::cout << "errore sequenza" << '\n';
    exit(EXIT_FAILURE);
  }
  fstream file_in, file_out;
  file_in.open(argv[1], ios::in);
  file_out.open(argv[2], ios::out);
  if(file_in.fail()){
    std::cout << "errore apertura file" << '\n';
    exit(EXIT_FAILURE);
  }
  char buffer[10000];
  char buffer2[10000];
  file_in >> buffer;
  if(strlen(buffer)%2 == 1){
    for(int i=0;file_in.eof();i++){
    buffer2[i]=buffer[i];
      for(int j=i;j<0 ; j++){
        file_out << buffer2[j] << endl;
        }
  }
}
  file_in.close();
  file_out.close();
  return(0);
  }
