#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool controllo(char buffer[]){
	bool flagSize=true;
	bool flagNum=true;
	bool flagBarra=true;
	int contBarre=0;
	int contN=0;
	bool flagG;
	
	if(strlen(buffer)!=19)
		flagSize=false;
	
	for(int i=0; buffer[i]!='\0'; i++){
		if(buffer[i]>='0' && buffer[i]<='9')
			contN++;
		else if(buffer[i]!='-')
			flagNum=false;
			
		if(contN%4==0 && buffer[i]=='-'){
			contBarre++;
		}
		
		
	}
	
	if(contBarre!=3)
		flagBarra=false;
	
	if(flagSize && flagBarra && flagNum)
		flagG=true;
	else
		flagG=false;
		
	return flagG;
	
}

int main(int argc, char * argv [])
{
	fstream input, output;
	char buffer[100];
	int contaP=0;
	bool flag;
	
	if(argc!=3){
		cout << "errore numero argomenti" << endl;
		exit(0);
	}
	
	input.open(argv[1], ios::in);
	output.open(argv[2], ios::out);
	
	if(input.fail() || output.fail()){
		cout << "errore apertura file" << endl;
		input.close();
		output.close();
		exit(0);
	}
	
	while(input >> buffer){
		flag=controllo(buffer);
		if(flag)
			contaP++;
	}
	cout << contaP << endl;
	output << contaP;
	
	cout << endl;
	
	input.close();
	output.close();
	
  return 0;
}
