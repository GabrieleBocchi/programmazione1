#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_DIM = 100+1;

bool is_code(char * code);

int main(int argc, char * argv [])
{
  if(argc!=3){
    cout << "Numero di elementi inserito da terminale errato " << endl;
    exit(-1);
  }
  fstream in, out;
  in.open(argv[1],ios::in);
  out.open(argv[2],ios::out);
  if(in.fail()){
    cout << "Errore in lettura del file " << argv[1] << endl;
    out.close();
    exit(-2); 
  }
  char parola[MAX_DIM];
  int count=0;
  while(!in.eof()){
    //cout << parola << endl;
    in >> parola;
    if(is_code(parola))
      count++;
  }
  out << count;
  out.close();
  in.close();
  return 0;
}


bool is_code(char * code){
  bool res = true;
  int i=0;
  if(strlen(code)==19){
      for(int i=0; code[i]!='\0' && res; i++){
        if(code[i]<'A' || code[i]>'Z'){
            if(i == 4 || i == 9 || i == 14){
              if(code[i] != '-')
                res = false;
            } else {
              res = false;
            }
          
        }
      } 
  }else {
    res = false;
  }  
    return res;
  }
  