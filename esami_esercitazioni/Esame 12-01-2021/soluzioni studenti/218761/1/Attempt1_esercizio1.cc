#include <iostream>
#include <fstream>
using namespace std;

int str_lungh (char *);
void str_copia (char *, char *, int);
void copia_pari_inversa (char *, char *);
typedef char** matrix;


int main(int argc, char * argv [])
{
  if(argc != 3){
    cerr << "Error! Missing parameters" << endl;
    exit(EXIT_FAILURE);
  }

  copia_pari_inversa(argv[1] ,argv[2]);

  return 0;
}

int str_lungh (char * str){
  int dim = 0;

  while(str[dim] != '\0'){
    dim++;
  }

  return dim;
}
void str_copia (char * dest, char * source, int dim){
  for (int i = 0; i < dim; i++){
    dest[i] = source[i];
  }
  dest[dim] = '\0';
}

void copia_pari_inversa (char * in_file, char * out_file){
  fstream in, out;
  in.open(in_file, ios::in);
  out.open(out_file, ios::out);

  if(in.fail() || out.fail()){
    cerr << "Error! File not found!" << endl;
    exit(EXIT_FAILURE);
  }

  matrix m = new char * [10000];
  char word [101];
  int i = 0;
  int k = 0;    //numero di elementi con numero di cifre pari
  int lungh;

  while (in >> word && i < 10000){
    lungh = str_lungh(word);
    
    if(lungh % 2 == 0){
      m[k] = new char [lungh+1];
      str_copia(m[k], word, lungh+1);
      k++;
    }
      
    i++;
  }

  for(int j = k-1; j >= 0; j--){  //stampa al contrario
    out << m[j] << " ";
    delete [] m[j]; //delete righa
  }
  
  delete [] m;

  in.close();
  out.close();
}
