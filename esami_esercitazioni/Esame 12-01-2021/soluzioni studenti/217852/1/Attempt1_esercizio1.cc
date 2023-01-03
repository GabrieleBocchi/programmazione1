// GDT: il codice è corretto, però c'erano soluzioni meno complicate. Fare riferimento
// alla soluzione ufficiale per un esempio di svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
	char parola[100];
	nodo* next;
};

typedef nodo* punt;

int conta(char buffer[]);
punt nuovoNodo(punt testa, char buffer[]);
void dealloca(punt testa);

int main(int argc, char * argv [])
{
	
	fstream input, output;
	
	punt testa=NULL;
	
	int numeroCaratteri;
	int maxParole=10000;
	int contParole=0;
	
	if(argc==3){
	
		input.open(argv[1], ios::in);
		output.open(argv[2], ios::out);
		
		if(!input.fail() && !output.fail()){
			
			char buffer[100];
			
			while(input >> buffer && contParole < maxParole){
				
				numeroCaratteri=conta(buffer);
				
				if(numeroCaratteri%2 == 0){
					testa=nuovoNodo(testa, buffer);
				}
				
				contParole++;
				
			}
			
			punt q=testa;
			
			while(q!=NULL){
				cout << q->parola << " ";
				output << q->parola << " ";
				q=q->next;
			}
			cout << endl;
			
			input.close();
			output.close();
			dealloca(testa);
			
		}else{
			
			cout << "errore apertura file" << endl;
		}
	
	}else{
		cout << "Usage: a.out fileinput fileoutput " << endl;
	}
	

  return 0;
}


int conta(char buffer[]){
	int cont=0;
	
	for(int i=0; buffer[i]!='\0'; i++){
		cont++;
	}
	
	return cont;
}



punt nuovoNodo(punt testa, char buffer[]){
	
	punt s=new nodo;
	
	for(int i=0; buffer[i]!='\0'; i++){
		
		s->parola[i]=buffer[i];
		
	}
	
	s->next=testa; 
	testa=s;
	
	return testa;
	
}


void dealloca(punt testa){
	
	if(testa==NULL){
		return;
	}	
	else{
		
		dealloca(testa->next);
		delete testa;
		
	}
}
