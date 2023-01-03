#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
char confronto ();

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
	char risultato;
	
	init();
	int i = 0;
	/* SB: il codice ignora l'ultimo carattere dell'espressione, 
	 * compromettendo così la valutazione dell'espressione.
	 * Per esempio, l'espressione "|!TT" viene erroneamente valutata a "F".
	 * La condizione dovrebbe essere " espressione[i] != '\0' "
	 */
	while (espressione[i+1] != '\0') {
		push(espressione[i]);
		i++;
	}

	while (!vuota() && corretta) {
		risultato = confronto();
		if (risultato == 'c') {
			corretta = false;
		}
	}

	deinit();

	return risultato;
}

char confronto () {
	char res;
	char tmp, tmp2;
	
	/* SB: il codice assume che ci siano almeno due valori nella pila, 
	 * ignorando così espressioni semplici composta da una sola lettera,
	 * per esempio "F". Si deve controllare il valore di ritorno delle
	 * chiamate alla funzione "top()"
	 */
	top(tmp);
	pop();
	top(tmp2);
	pop();


	if (tmp == 'T' || tmp == 'F') {
		switch (tmp2) {

			/* SB: il codice non controlla se ci sono già due valori sulla pila. 
			 * Di conseguenza, il codice accetta espressioni composta da un numero
			 * eccessivo di valori, come per esempio "FFFFF".
			 */
			case 'T':
				res = (tmp == tmp2) ? tmp : 'T'; break;
			case 'F':
				res = (tmp == tmp2) ? tmp : 'T'; break;
			case '|':
				res = tmp; break;
			case '!':
				if (tmp == 'T') {
					res = tmp = 'F';
				}
				else {
					res = tmp = 'T';
				}
				break;
			default :
				res = 'c'; break;
		}
		if (!vuota()) {
			push(res);	
		}
	}
	else {
		res = 'c';
	}
	return res;
}
