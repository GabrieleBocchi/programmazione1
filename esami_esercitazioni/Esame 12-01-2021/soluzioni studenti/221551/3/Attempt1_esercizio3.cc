#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

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
  char result;

  // SB: variabile non utilizzata
  bool fine = false;
  char valorePrecedente = '0';
  init();
  for( int i = 0; espressione[ i ] != '\0' && corretta; i++ )
  {
    if( !push( espressione[i] ) )
    {
      corretta = false;
    }
  }
  /*
  while (fine == false && top(result))
  {
    if( result == '&' ){
      result = valorePrecedente;
    }else if( result == '!' && valorePrecedente != '0' ){
      result = ( valorePrecedente == 'T' ) ? 'F' : 'T';
    }else{

    }
  }*/
  
  //controllo se corretta
  /*char temp;
  int contaVal = 0;
  while( corretta && top( temp ) ){
    if( temp == 'T' || temp == 'F' ){
      contaVal++;
    }
    if( valorePrecedente != '0'){
      cout<< "conta val = "<<contaVal<<endl;
      if( valorePrecedente == 'T' || valorePrecedente == 'F' ){
        if( temp == 'T' || temp == 'F' || temp == '&' || temp == '!' ){
        }else{
          corretta = false;
        }
      }else if( valorePrecedente == '&' || valorePrecedente == '!' ){
        if( (temp == '!' || temp == '&' ) && contaVal == 0 ){
          corretta = false;
        }else{
          contaVal = 0;
        }
      }
      if( temp == '&' ) {
        if( contaVal < 2 && (valorePrecedente != '&' || valorePrecedente != '!') ){
          corretta = false;
        }
        contaVal = 0;
      }else if( temp == '!' ){
        if( contaVal < 1 && (valorePrecedente != '&' || valorePrecedente != '!') ) {
          corretta = false;
        }
      }
    }
    valorePrecedente = temp;
    pop();
  }
  */
  if( corretta ) {
    /*valorePrecedente = '0';
    for( int i = 0; espressione[ i ] != '\0' && corretta; i++ ){
      if( !push( espressione[i] ) ){
        corretta = false;
      }
    }*/

    // SB: controllo correttezza espressione non implementato
    while ( top( result ) ) {
      //cout<<"Valuto r = "<<result<<endl; 
      switch (result){
      case '!':
        result = ( valorePrecedente == 'T' ) ? 'F':'T';
        break;
      case 'T':
        result = ( valorePrecedente == 'T' || valorePrecedente == '0') ? 'T':'F';
        break;
      case 'F':
        /* SB: per essere corretto, dovrebbe mettere sempre il valore di "result" uguale a 'F'.
         * Per esempio, l'espressione "&FF" viene valutata a "T" dal suo codice
         */
        result = ( valorePrecedente == 'T' || valorePrecedente == '0') ? 'F':'T';
        break;
      case '&':
        result = valorePrecedente;
        break;
      default:
        break;
      }
      //cout<<"In while vp : "<<valorePrecedente<<endl;
      //cout <<"In while r : "<< result<<endl;
      valorePrecedente = result;
      pop();
    }
  }
  //cout<<"Out while : "<<result<<endl;
  deinit();
  return result;
}

/*
prendo espressione, salvo in una pila, prendo top salvo in un altra pila, finchè non trovo ! || & 
result = calcolo operazione
*/