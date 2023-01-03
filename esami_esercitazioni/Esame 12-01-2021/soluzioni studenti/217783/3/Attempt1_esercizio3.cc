#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
bool isLettera(char elemento);
bool typeOfBool(char elemento);
bool typeOfBool(char elemento1, char elemento2);

int main() { 

    int dimensioneMassima = 100;
    char espressioneBooleana [dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta) {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else {
        cout << "Espressione malformata" << endl;
    }
    
    return 0;
}


char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
    // Scrivere il codice qui
	bool risultato;
	init();
	
	int contaChar;
	for (contaChar=0; contaChar<100 && espressione[contaChar] != '\0'; contaChar++) {
		push(espressione[contaChar]);
	}
	
	/* SB: "contatore" non è stato inizializzato a 0. Per questo motivo, il 
	 * comportamento del codice è indefinito, e (quasi) sempre il ciclo "while"
	 * non viene eseguito
	 */
	int contatore; 
	char attuale;

	while (contatore <= contaChar) {
		top(attuale);
		contatore++;
		pop();
		
		if (attuale != 'T' && attuale != 'F' && attuale != '!' && attuale != '|' ) {
			corretta = false;
		}
		else{
			
			// SB: "contatore" non potrà mai essere uguale a 0, è stato appena incrementato
			if (contatore == 0 && (attuale == '!' || attuale == '|'))
				corretta = false;
			else{
				elem1 = attuale;
				
			}
			
			top(attuale);
			if(isLettera(attuale)){
				elem2 = attuale;
				pop();
				contatore++;
			}
			else if(!(isLettera(attuale) && attuale == '!')){
				operatore = attuale;

				/* SB: in questa istruzione, si sta moltiplicando 
				 * un carattere per un valore booleano (?)
				 */
				risultato = operatore*(typeOfBool(elem1));

				pop();
				contatore++;
			}
				
			top(attuale);
			if(!isLettera(attuale) && attuale == '|'){
				operatore = attuale;

				/* SB: in questa istruzione, si sta moltiplicando 
				 * un carattere per un valore booleano (?)
				 */
				risultato = operatore*(typeOfBool(elem1, elem2));

				pop();
				contatore++;
			}
			
			
		}
		
		
	}
	
	
	deinit();

	/* SB: per il commento a riga 44, "risultato" non sarà (quasi) mai inizializzato. 
	 * Per questo motivo, il comportamento del codice è indefinito, e (quasi) sempre 
	 * la funzione ritornerà "T".
	 */
	char returnVal;
	if(risultato)
		returnVal = 'T';
	else
		returnVal = 'F';
	
	return returnVal;
}

bool isLettera(char elemento){
	
	bool ret;
	
	if(elemento == 'T' || elemento == 'F')
		ret = true;
	else
		ret = false;
	
	return ret;
}

bool typeOfBool(char elemento){
	bool ret;
	
	if(elemento == 'T' )
		ret = false;
	else if(elemento == 'F')
		ret = true;
	
	return ret;
}

bool typeOfBool(char elemento1, char elemento2){
	bool ret;
	bool el1, el2;
	
	if(elemento1 == 'T' )
		el1 = true;
	else if(elemento1 == 'F')
		el1 = false;
	
	if(elemento2 == 'T' )
		el2 = true;
	else if(elemento2 == 'F')
		el2 = false;
	
	ret = el1 | el2;
	
	return ret;
	
}
