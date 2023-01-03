#include <iostream>
#include <fstream>
using namespace std;

void strcopy(const char* in, char* out){
  while(*in != '\0'){
    *out = *in;
    out++;
    in++;
  }
  *out = '\0';
}

int numCaratteri(const char* input){
  int out = 0;
  while(*input != '\0'){
    out++;
    input++;
  }
  return out;
}

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Missing information" << endl; //todo: cambiare le parole
  }


  fstream fileInput, fileOutput;

  fileInput.open(argv[1], ios::in);
  fileOutput.open(argv[2], ios::out);


  if( !fileInput.fail() && !fileOutput.fail() ){
    char paroleInput[1000][100];
    int indexParole = 0;
    char parola[100];
    fileInput >> parola;
    while(!fileInput.eof()){
      fileInput >> parola;
      if(numCaratteri(parola) %2 == 1){
        strcopy(parola, paroleInput[indexParole]);
        indexParole++;;
      }
    }
    
    while(indexParole >= 0){
      fileOutput << paroleInput[indexParole] << " ";
      indexParole--;
    }
  }else{
    cout << "Errore nell' apertura di uno dei due file" << endl;
  }

  fileInput.close();
  fileOutput.close();

  return 0;
}
