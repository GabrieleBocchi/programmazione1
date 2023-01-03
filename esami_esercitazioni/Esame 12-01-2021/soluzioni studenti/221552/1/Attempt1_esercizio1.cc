#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  int returnValue = 0;

  if(argc != 3){
    cout << "Usage: ./a.out <file1> <file2>" <<endl;
    returnValue = 1;
  }
  else{

    //apro il file input
    fstream input, output;
    input.open(argv[1], ios::in);

    if (input.fail()) {
        cout << "errore nell'apertura del file" << endl;
        returnValue = 2;
    }
    else{
      char parola[100];
      output.open(argv[2], ios::out);

      if (output.fail()){
        cout << "File di output non valido" << endl;
        returnValue = 3;
      }
      else{
        //matrice che contiene tutte le stringhe
        char** matrix = new char*[10000];

        int i = 0;
        while(input >> parola) {
          matrix[i] = new char[100];        
          int k = 0;
          while(parola[k] != '\0'){
            k++;
          }
          if (k%2 == 0){
            matrix[i] = parola;
            cout << k << endl;
            i++;
          }
        }
        input.close();

        
        for (int j = i-1; j >= 0; j--){
            cout << matrix[j] << endl;
          }
        }
        output.close();
      }
    //chiudo il file 
    input.close();
    }
  return returnValue;
}