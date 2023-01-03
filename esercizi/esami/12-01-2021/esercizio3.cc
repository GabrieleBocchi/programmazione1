#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main()
{ 
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


char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta)
{
    init();
    for (int i = 0; espressione[i] != '\0'; i++)
        push(espressione[i]);
    char c;
    int first = -1, second = -1, last = -1, result = -1;
    while (top(c) && corretta)
    {
        if(c == 'T')
        {
            if (first == -1)
            {
                first = 1;
                last = 1;
            }
            else if (second == -1)
            {
                second = 1;
                last = 2;
            }
            else
                corretta = false;
        }
        else if(c == 'F')
        {
            if (first == -1)
            {
                first = 0;
                last = 1;
            }
            else if (second == -1)
            {
                second = 0;
                last = 2;
            }
            else
                corretta = false;
        }
        else if (c == '!')
        {
            if (last == 1)
            {
                if (first == 0)
                    first = 1;
                else if (first == 1)
                    first = 0;
                if (result == -1)
                    result = first;
                last = -1;
            }
            else if (last == 2)
            {
                if (second == 0)
                    second = 1;
                else if (second == 1)
                    second = 0;
                if (result == -1)
                    result = second;
                last = -1;
            }
            else
                corretta = false;
        }
        else if (c == '&')
        {
            if (result != -1 && first != -1)
                result = first * result;
            else if (first != -1 && second != -1)
                result = first * second;
            else
                corretta = false;
            first = -1;
            second = -1;
        }
        else
            corretta = false;
        pop();
    }
    deinit();
    if (result)
        return 'T';
    else
        return 'F';
}