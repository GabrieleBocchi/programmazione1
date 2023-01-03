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
   init ();
   int cont = 0;
   
   while (espressione[cont] != '\0') {
      // SB: bisognerebbe controllare il valore di "corretta" ad ogni operazione di "push"
      corretta = push(espressione[cont]);
      cont++;
   }
   
   bool prosegui = true;
   char top1;
   char top2;
    
   while (corretta && prosegui) {
      corretta = top(top1);
      corretta = pop();
      prosegui = top(top2);
      prosegui = pop();
      
      if (top1 != '0' && top1 != '1') {
         corretta = false;
      }
      else if (prosegui) {
         
         if (top2 != '!' && top2 != '0' && top2 != '1') {
            corretta = false;
         }
         else if (top2 == '!') {
            if (top1 == '0') {
               push ('1');
            }
            else {
               push ('0');
            }
         }
         else if (top2 == '0' || top2 == '1') {
            char op;
            corretta = top (op);
            corretta = pop ();
             
            if (op == '|') {
               int num1 = int (top1 - '0');
               int num2 = int (top2 - '0');
               if ( (num1 || num2) == 0) {
                  push ('0');
               }
               else{
                  push ('1');
               }
            }
            else if (op == '!') { 
               if (top2 == '0') {
                  push ('1');
               }
               else {
                  push ('0');
               }
               push (top1);
            }
            else {
               corretta = false;
            }
         }     
      }
   } 
   deinit ();
    
   return top1;
}















