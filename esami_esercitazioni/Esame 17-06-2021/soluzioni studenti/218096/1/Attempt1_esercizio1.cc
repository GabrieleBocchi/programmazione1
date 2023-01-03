#include <iostream>
#include <fstream>
using namespace std;

#define MAX_STR 100+1

bool isMIU(char* str){
  bool firstIsM = false;
  bool isMIU = true;
  int numI=0;
  int i;

  if(str[0]=='M'||str[0]=='m')
    firstIsM = true;

  for(i=0;str[i]!='\0' && isMIU;i++){

    if(str[i]=='I'||str[i]=='i'){
      numI++;
    }else if( (str[i]=='M'||str[i]=='m') && i>0){
      if(str[i-1]=='I'||str[i-1]=='i')
        isMIU = false;
    }

  }

  if(i>0){
    if( firstIsM && str[i-1]!='U' && str[i-1]!='u' )
      isMIU = false;
  }

  if(numI!=0 && numI%2==0){
    isMIU = false;
  }

  return isMIU;

}

int main(int argc, char * argv [])
{

  fstream in, out;
  char parola[MAX_STR];

  if(argc!=3){
    cerr << "Numero di argomenti errato" << endl;
    exit(1);
  }

  in.open(argv[1],ios::in);
  if(in.fail()){
    cerr << "Impossibile aprire il file di input" << endl;
    exit(2);
  }


  out.open(argv[2],ios::out);
  if(out.fail()){
    cerr << "Impossibile aprire il file di output" << endl;
    exit(3);
  }

  in>>parola;
  while(!in.eof()){

    if(isMIU(parola))
      out<<parola<<endl;

    in>>parola;
    
  }


  in.close();
  out.close();

  return 0;
}
