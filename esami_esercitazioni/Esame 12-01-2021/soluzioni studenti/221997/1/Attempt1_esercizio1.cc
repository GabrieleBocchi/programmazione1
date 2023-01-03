#include <iostream>
#include <fstream>

using namespace std;

bool grandezza(char* parola){
  int dim = 0;
  bool corretta = false;
  while(parola[dim] != '\0'){
    dim++;
  }
  if(dim >= 4){
    corretta = true;
  }
  

  return corretta;
}

int main(int argc, char * argv [])
{
  int returnValue = 0;

  if(argc != 3){
    cout << "Usage : <fileInput> <fileOutput>"<<endl;
    returnValue = 1;
  }
  else{

    fstream input, output;
    char buffer[100];
    
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail()){
      cout << "Errore nell'apertura del file" << endl;
      returnValue = 2;
    }
    else{
      int indice = 0;
      char** testo = new char*[10000];
      input >> buffer;
      while(!input.eof()){
        testo[indice] = new char[100];
        testo[indice] = buffer;
        indice++;
        input >> buffer;
      }
    

      input.close();

      //scivo nel file
      for(int i = indice-1 ; i >= 0 ; i--){

        if(grandezza(testo[i])){
          output << testo[i] << " ";
        }
      }
      
      for(int i = 0; i < indice ; i++){
          delete[] testo[i];
        }
        delete [] testo;
    }

    output.close();
  }

  return returnValue;
}
