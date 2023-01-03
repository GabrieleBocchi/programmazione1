#include <iostream>
#include <fstream>
using namespace std;

const int DIM=101;

int lung(const char *v){
  int i=0;
  for(;v[i]!='\0';++i){

  }
  return i;
}

bool compatibile(char * v){
  bool compatibile=true;
  if(v[0]=='U' && v[lung(v)-1]!='M'){
    compatibile=false;
  }
  int iCounter=0; 
  for(int i=0;compatibile && i<lung(v);++i){
    if(v[i]=='I'){
      iCounter++;
    }
    if(v[i]=='M' && v[i+1]=='I'){
      compatibile=false;
    }
  }
  if(iCounter%2!=0){
    compatibile=false;
  }
  return compatibile;
}

int main(int argc, char * argv []){
  if(argc!=3){
    cerr<<"Errore in input\n";
  }
  else{
    fstream in,out;
    in.open(argv[1],ios::in);
    out.open(argv[2],ios::out);
    if(in.fail() || out.fail()){
      cerr<<"Errore nei file\n";
    }
    else{
      char* tmp=new char[DIM];
      while(in>>tmp){
        if(!compatibile(tmp)){
          out<<tmp<<endl;
        }
      }
      delete [] tmp;
    }
    in.close();
    out.close();
  }
  return 0;
}
