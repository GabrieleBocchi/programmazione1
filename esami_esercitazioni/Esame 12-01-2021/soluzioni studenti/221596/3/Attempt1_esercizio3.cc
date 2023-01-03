#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta);
void Not(char &boolean);
char And(char bool1, char bool2);
char Or(char bool1, char bool2);

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

    char boolVal1 = 'X';
    char boolVal2 = 'X';
    char tmp;

    for (int i = 0; espressione[i] != '\0'; i++)
    {
        push(espressione[i]);
    }

    while (top(tmp) && corretta)
    {
        switch (tmp)
        {
        case 'T':
        case 'F':
            if (boolVal1 == 'X')
                boolVal1 = tmp;
            else if (boolVal2 == 'X')
                boolVal2 = tmp;
            else
                corretta = false;
            break;

        case '!':
            if (boolVal2 == 'X')
            {
                if (boolVal1 == 'X')
                    corretta = false;
                else
                    Not(boolVal1);
            }
            else if (boolVal2 != 'X')
                Not(boolVal2);
            else
                corretta = false;
            break;

        case '&':
            if (boolVal1 != 'X' && boolVal2 != 'X')
            {
                boolVal1 = And(boolVal1, boolVal2);
                boolVal2 = 'X';
            }
            else
            {
                corretta = false;
            }
            break;

        case '|':
            if (boolVal1 != 'X' && boolVal2 != 'X')
            {
                boolVal1 = Or(boolVal1, boolVal2);
                boolVal2 = 'X';
            }
            else
            {
                corretta = false;
            }
            break;

        default:
            corretta = false;
            break;
        }

        pop();
    }

    if (boolVal2 != 'X')
        corretta = false;

    return boolVal1;

    deinit();
}

void Not(char &boolean)
{
    if (boolean == 'F')
        boolean = 'T';
    else if (boolean == 'T')
        boolean = 'F';
}

char And(char bool1, char bool2)
{
    char retVal;
    if (bool1 == 'T' && bool2 == 'T')
        retVal = 'T';
    else
        retVal = 'F';
    return retVal;
}

char Or(char bool1, char bool2)
{
    char retVal;
    if (bool1 == 'T' || bool2 == 'T')
        retVal = 'T';
    else
        retVal = 'F';

    return retVal;
}