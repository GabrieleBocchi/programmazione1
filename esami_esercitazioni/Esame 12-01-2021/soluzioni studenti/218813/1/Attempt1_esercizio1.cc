// GDT: fare riferimento alla soluzione ufficiale per un possibile svolgimento

//esercizio 1, esame programmazione 1, Federico Caporale, 12/01/2020 


#include <iostream>
#include <fstream>
using namespace std;


const int DIM=100;

int main(int argc, char * argv [])
{
  char c;                      //variabile di supporto
  int car=0;                   //variabile che contiene il numeri dei caratteri di ogni parola (max 100)
  int par=0;                   //variabile che contiene il numero di parole del testo (max 10k)
  char parole[car][par];       //matrice che contiene i caratteri di ogni parola(come se ricreasse un file di testo 100x10000)

  fstream file;                //inizializzo un fstream di nome file

  
  file.open(argv[0],ios::in);
    
  //controllo se l'apertura avviene correttamente
  if(!file)
    cout<<"\nErrore nell'apertura del file"<<endl;
  
  else
    {
      //ciclo: viene effettuato fino a quando non raggiunge EndOfFile
      while(!file.eof())
		{
		  file.get(c);   //prendo il carattere e lo metto nella variabile c
		  cout<<c;        //esco all'utente la variabile
		  
		  if(c!='\0')
			{
			  parole[car][par]=c;
			  car++;
			}
		  
		   else
			par++;
		}
    }
  
  //chiudo il file
  file.close();

  
  
  file.open(argv[1],ios::out);
  
  do{

	if(parole[car][par]!='\0')
	  {
		parole[car][par];
		car--;
		cin>>parole[car][par];
		cout<<parole[car][par];
	  }

	else
	  par--;
   
  }while(par==0);
  
  file.close();
  

  return 0;
}

