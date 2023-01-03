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
  int i=0;
  char c=espressione[i];
  bool res,op, tmp;
  init();
  while (c!='\0')
    {
      push(c);
      i++;

      // SB: "c=espressione[i];"
      c=espressione[1];
    }

  for(int j=0; j<=i && corretta; j++)
    {
      top(c);

      // SB: la condizione di equaglianza si esprime con "==" ("j=0" è un'operazione di assegnamento che
      // (1) provoca un ciclo infinito e (2) valuta sempre a "false" )
      if(j=0)
	{
	  if((c=='T')||(c=='t'))
	    {
	      res=true;
	      op=false;
	    }
	  else if ((c=='F')|| (c=='f'))
	    {
	      res=false;
	      op=false;
	    }
	  else
	    corretta=false;
	  pop();
	}
      else
	{
	  if(!op)
	    {
	      if (c=='t'||c=='T')
		{
		  tmp=true;
		  res=(res||tmp);
		  op=true;
		}
              // SB: l'OR logico si esprime con "||" (  " (c=='f'|c=='F') " è un'operazione OR bitwise, non logica)
	      else if(c=='f'|c=='F')
		{
		  tmp=false;
		  res=(res|tmp);
		  op=true;
		}
	      else if(c=='!')
		{
		  res= !res;
		}
	      else
		corretta=false;
	      pop();
	    }
	  else
	    {
	      if(c=='t'||c=='T'||c=='f'||c=='F')
		corretta=false;
	      else
		{
		  pop();
		  op=false;
		}
	    }
	   
	}
	    
	}
    
if (res)
  c='T';
 else
   c='F';

   // SB: manca la deallocazione ( "deinit()" )

return c;

}
