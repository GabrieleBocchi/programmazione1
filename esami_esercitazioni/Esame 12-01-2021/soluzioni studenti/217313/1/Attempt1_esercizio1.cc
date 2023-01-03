// GDT: dare sempre nomi significativi alle variabili.
// Manca la deallocazione dell'array a (delete[] a;).

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv []) {
  
  if(argc!=3){
    cout<<"Errore. Inserire ./a.out <input.txt> <output.txt>"<<endl;
    exit(1);
  }
  else{
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    if(input.fail() || output.fail()){
      cout<<"Errore apertura file input/output"<<endl;
      exit(1);
    }
    else{
      char **a=new char*[10001];
      int c=0, dim=101;
      char r[dim];
      
      for(int x=0; input>>r; x++){
        int i=0;
        while(r[i]!='\0'){
          i++;
        }
        if(i>4){
          a[c]=new char[i+1];
          for(int x=0; x<i; x++){
            a[c][x]=r[x];
          }
          a[c][i]='\0';
          cout<<a[c]<<endl;
          c++;
        }
      }
      for(int j=c-1; j>=0; j--){
        output<<a[j]<<" ";
        delete [] a[j];
      }
    }
    input.close();
    output.close();
  }
  
  return 0;
}
