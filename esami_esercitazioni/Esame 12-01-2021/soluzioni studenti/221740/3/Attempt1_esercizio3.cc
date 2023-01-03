#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
void exec( char& a, char& b, char op );

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
    pila = new lista; 
	for ( int i = 0; espressione[i] !='\0' ; i++ )
		pila.push( espressione[i] );
	char a = 0, b = 0, buf;
	while( !vuota( pila ) && corretta ){
 
		if ( pila.top(buf) && pila.pop() ){
			if ( buf == '|' && a != 0 && b != 0 )
				exec( a, b, buf );
			else if ( buf == '!' && a != 0)
				exec( a, buf );
			else if ( buf == 'T' || buf == 'F' ){
				if ( a == 0 )
					a = buf;
				else
					b = buf;
			}else
				corretta = false;
		}else
			corretta = false;
	}
	
	return a;
}

void exec( char& a, char& b, char op ){
	bool v1,v2,ris;
	v1 = getBinValue( a );

	switch( op ){
		case '|':
			v2 = getvalue( b );
			ris = v1 || v2;
			break;
		case '!':
			ris = ! v1;
			break;
	}
	
	a = getCharValue( ris );
}