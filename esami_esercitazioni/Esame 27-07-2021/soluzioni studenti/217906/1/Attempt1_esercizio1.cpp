#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){
  if(argc != 3){
    cout << "Usage: ./a.out <input> <output>" << endl;
    exit(-1);
  }

  fstream in, out;
  in.open(argv[1], ios::in);
  if(in.fail()){
    cout << "Problems while opening the file!"<< endl;
    exit(-1);
  }

  const int DIM = 16;
  char sequenza[DIM+1];
  out.open(argv[2], ios::out);
  int counter = 0;
  bool isCod;

  while(!in.eof()){
    in >> sequenza;
    isCod = true;
    for(int i = 0; i< DIM; i++){
      if(i >= 0 && i < 12){
        if(!(sequenza[i] >= '0' && sequenza[i] <= '9')){
          isCod =false;
        }        
      }else{
        if(!(sequenza[i] >= 'A' && sequenza[i] <= 'Z')){
          isCod =false;
        }
      }      
    }
    if(isCod){
        counter++;
    }
  }

  out << counter;
  in.close();
  out.close();
  return 0;
}