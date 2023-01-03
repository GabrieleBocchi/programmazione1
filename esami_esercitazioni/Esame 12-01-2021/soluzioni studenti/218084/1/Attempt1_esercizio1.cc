// GDT: la dumensione della variabile DIM_ARRAY è errata. Dovrebbe essere 10000.
// Manca la deallocazione delle parole allocate da copia_stringa().

#include <iostream>
#include <fstream>
using namespace std;

const int DIM_BUFFER = 101;
const int DIM_ARRAY = 1000;

bool conservare_parola(char buffer[]);
int conta_caratteri(char buffer[]);
char* copia_stringa(char str[]);

int main(int argc, char * argv [])
{

  if (argc != 3){
    cout << "Errore nel numero di parametri" << endl;
    cout << "<FILE_INPUT> <FILE_OUTPUT>" << endl;
  }
  else{
    fstream in, out;
    char buffer[DIM_BUFFER];
    char* parole[DIM_ARRAY];
    in.open(argv[1], ios::in);
    if (in.fail()){
      cout << "Errore nell'apertura del file di input" << endl;
    }
    else{
      int i = 0;
      while(in >> buffer){
        if (conservare_parola(buffer) == true){
          parole[i] = copia_stringa(buffer);
          i++;
        }
      }
      out.open(argv[2], ios::out);
      if (out.fail()){
        cout << "Errore nell'apertura del file di output" << endl;
      }
      else{
        for (int j = i-1; j >= 0; j--){
          out << parole[j] << " ";
        }
        out.close();
      }
      in.close();
    }
  }

  return 0;
}

bool conservare_parola(char buffer[]){
  if (conta_caratteri(buffer) > 4){
    return true;
  }
  else{
    return false;
  }
}

int conta_caratteri(char buffer[]){
  int i = 0;
  while(buffer[i] != '\0'){
    i++;
  }

  return i;
}

char* copia_stringa(char str[]){
  int dim_str = conta_caratteri(str);
  char* s = new char[dim_str+1];
  int i = 0;
  for (int i=0; i<dim_str; i++){
    s[i] = str[i];
  }
  s[dim_str] = '\0';

  return s;
}
