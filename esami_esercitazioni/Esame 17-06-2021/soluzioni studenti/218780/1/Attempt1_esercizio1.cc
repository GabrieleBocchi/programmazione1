#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  if(argc!=3){
    cout << "inserire il nome dei file" << endl;
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  if(input.fail()||output.fail()){
    cout << "problemi con i file" << endl;
  }
  char line[100]=" ";
  while(!input.eof()){
    input >> line;
    bool isMiu=true;
    int size=0;
    int n_I=0;
    bool is_M=false;
    while((line[size]=='M'||line[size]=='U'||line[size]=='I')&& isMiu==true){
      if(is_M==true){
        if(line[size]=='I'){
          isMiu=false;
        }
        is_M=false;
      }
      if(line[size]=='M'){
        is_M=true;
      }
      if(line[size]=='I'){
        n_I++;
      }
      size++;
    }
    size--;
    if((line[0]=='U')&&(line[size]!='M')){
      isMiu=false;
      cout<<line<<size;
    }
    if(isMiu==true){
      isMiu=(n_I%2)==0;
    }
    if(isMiu==true){
      output << line << endl;
    }
    
  }
  
  return 0;
}
