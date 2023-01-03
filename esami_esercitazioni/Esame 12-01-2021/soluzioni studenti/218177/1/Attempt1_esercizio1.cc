#include <iostream>
#include <fstream>
using namespace std;

bool controllo_parola(char s[]);
void copy_string(char r[][100], char b[], int j);

int main(int argc, char * argv [])
{
  if(argc>=3){
    fstream input;
    input.open(argv[1], ios::in);
    if(!input.fail()){
      fstream output;
      output.open(argv[2], ios::out);
      char buffer[100];
      char recorder[10000][100];
      int i=0;

      input>>buffer;
      if(controllo_parola(buffer)){
        copy_string(recorder, buffer, i);
        i++;
      }
      while(!input.eof()){
        input>>buffer;
        if(controllo_parola(buffer)){
          copy_string(recorder, buffer, i);
          i++;
        }
      }


      for(int j=i-1; j>=0; j--){
        
        output<<recorder[j]<<" ";
      }
      

      output.close();
    }else{
      cout<<"Il file di input specificato non esiste";
    }
    input.close();
  }else{
    cout<<"La dicitura da usare e': ./a.out NomeFileInput NomeFileOutput";
  }
  return 0;
}

bool controllo_parola(char s[]){
  int i=0;
  bool c=true;
  while(s[i]!='\0' && i<5){
    if(i>=4){
      c=false;
      i=100;
    }
    i++;
  }
  return c;
}

void copy_string(char r[][100], char b[], int j){
  int i=0;
  //cout<<b<<" ";
  while(b[i]!='\0'){
    r[j][i]=b[i];
    i++;
  }
  //cout<<r[j]<<"\n";
}
