#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]){
  fstream input, output;
  if(argc!=3){
    cout<<"Usage: ./esercizio1.out <sourcefile> <destinationfile>"<<endl;
    exit(0);
  }
  input.open(argv[1],ios::in);
  output.open(argv[2],ios::out);
  if(input.fail() || output.fail()){
    cout<<"i file indicati non esistono"<<endl;
    exit(0);
  }
  bool sniffer=false;
  char stringa[100];
  while(input>>stringa){
    char codice[20];
    for(int i=0;i<100;i++){
      if(stringa[i]>='0' && stringa[i]<='9'){
	codice[i]=stringa[i];
	sniffer=true;
      }
      else if(stringa[i]=='-'){
	codice[i]=stringa[i];
	sniffer=true;
      }
    }
  }
  int n=2;
  if(sniffer==true){
    output<<n<<endl;
    cout<<"sniffing riuscito"<<endl;
    }
  else{
    cout<<"sniffing fallito"<<endl;
  }


  
  input.close();
  output.close();
  
  return 0;
}
