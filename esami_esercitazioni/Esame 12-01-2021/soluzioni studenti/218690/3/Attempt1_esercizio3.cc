#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta);

int main()
{

  int dimensioneMassima = 100;
  char espressioneBooleana[dimensioneMassima];
  bool corretta = true;
  char risultatoEspressione;

  cout << "Inserisci l'espressione: ";
  cin >> espressioneBooleana;

  risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

  if (corretta)
  {
    cout << "Risultato: " << risultatoEspressione << endl;
  }
  else
  {
    cout << "Espressione malformata" << endl;
  }

  return 0;
}

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta)
{
  init();
  for (int i = 0; espressione[i] != '\0'; i++)
  {
    push(espressione[i]);
  }
  bool res = true, valore = true, valoreValido = false, notV = false;
  int nValues = 0;
  char tmpBuff;
  while (!vuota() && corretta)
  {
    top(tmpBuff);
    pop();
    switch (tmpBuff)
    {
      case '1':
      {
        res = res && valore;
        notV = false;
        valore = true;
        valoreValido = true;
        if(++nValues > 2){
          corretta = false;
        }
      }
      break;

      case '0':
      {
        res = res && valore;
        notV = false;
        valore = false;
        valoreValido = true;    //  !&1&!0&11
        if(++nValues > 2){
          corretta = false;
        }
      }
      break;

      case '!':
      {
        /* SB: manca il controllo "nValues > 0", altrimenti il codice accetta
         * espressioni malformate come "!"
         */
        valore = !valore;
      }break;

      case '&':
      {
        /* SB: manca il controllo "nValues == 2", altrimenti il codice accetta
         * espressioni malformate come "&1"
         */
        res = res && (notV? !valore: valore);
        valore = res;
        nValues = 1;
      }
    }
  }

  /* SB: manca il controllo "nValues = 1", altrimenti il codice accetta
   * espressioni malformate come "11" oppure "!11"
   */


  // SB: manca la "deinit()"

  res = valore;
  return res? '1' : '0';
}