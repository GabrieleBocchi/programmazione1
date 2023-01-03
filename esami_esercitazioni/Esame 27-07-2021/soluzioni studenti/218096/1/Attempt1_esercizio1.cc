#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAX_STR 100+1

bool controlla(char* parola){

  if(strlen(parola)!=19)
    return false;

  for(int i=0;i<19;i++){
    cout << i;

    if(i==4||i==9||i==14){
      if(parola[i]!='-')
        return false;
    }else{
      if(parola[i]<'A'||parola[i]>'Z')
        return false;
    }
  }

  return true;

}

int main(int argc, char * argv [])
{
  fstream in, out;
  char parola[MAX_STR];
  int numStringhe = 0;

  if(argc != 3){
    cerr << "Numero argomenti errato!";
    exit(1);
  }

  in.open(argv[1],ios::in);
  if(in.fail()){
    cerr << "Impossibile aprire il file di input!";
    exit(2);
  }

  out.open(argv[2],ios::out);
  if(out.fail()){
    cerr << "Impossibile aprire il file di output!";
    exit(3);
  }

  in >> parola;
  while(!in.eof()){

    if(controlla(parola))
      numStringhe++;
      
    cout << "\n";
    in >> parola;
  }

  out << numStringhe;


  in.close();
  out.close();

  return 0;
}
