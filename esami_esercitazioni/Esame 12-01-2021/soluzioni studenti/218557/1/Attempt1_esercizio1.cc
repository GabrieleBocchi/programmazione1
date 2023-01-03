// GDT: fare riferimento alla soluzione ufficiale per lo svolgimento

#include <iostream>
#include <fstream>
using namespace std;

const int dim=256;

int main(int argc, char * argv [])
{
  fstream input,output;
  
  char buffer[dim];
  char riga[dim];
  
  if(argc!=3){
    cerr << "Usage: ./a.out <file_input> <file_output> \n";
    exit(0);
  }
  else{
    int i=0;
    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);
    if(!input.fail() && !output.fail()){
      while(!input.eof()){
	cout << i <<" \n";
	input >> buffer[dim];
	i++;
      }
    }
    for(int j=i-1;j>=0;j--){
      output << buffer[j];
    }
     
    
  }
  input.close();
  output.close();
  return 0;
}
