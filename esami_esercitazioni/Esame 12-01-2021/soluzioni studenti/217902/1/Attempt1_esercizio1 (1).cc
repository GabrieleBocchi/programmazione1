#include <iostream>
#include <fstream>
using namespace std;

const int DIM_PAROLA = 100;
const int NUM_PAROLE = 10000;

int main(int argc, char * argv [])
{
  int ris = 0;
  if(argc != 3){
    cout<<"parametri errati, usare: ./a.out inputfile.txt outputfile.txt"<<endl;
    ris = 1;
  }else{
    fstream input, output;
    input.open(argv[1],ios::in);
    if(input.fail()){
      cout<<"errore apertura file di input"<<endl;
      ris = 1;
    }else{
      int Ncaratteri = 0;
      int Nparole = 0;
      char* parola = new char[DIM_PAROLA];
      char ** parole = new char*[NUM_PAROLE];
      input>>parola;
      do{
	for(int i = 0; parola[i] != '\0'; i++){
	  Ncaratteri++;
	}
	if(Ncaratteri > 4){
	  parole[Nparole] = new char[DIM_PAROLA];
	  parole[Nparole] = parola;
	  cout<<parole[Nparole]<<" ";
	  Nparole++;
	}
	Ncaratteri = 0;
	
      }while(input>>parola);
      input.close();
      
      output.open(argv[2], ios::out);
      if(output.fail()){
	cout<<"errore nel file di output"<<endl;
	ris = 1;
      }else{
	int i = Nparole-2;
	while(i>=0){
	  output<<parole[i]<<" ";
	  //delete[] parole[i]
	  i--;
	}
	output.close();
      }
      delete[] parole;
    }
  }
  return ris;
}
