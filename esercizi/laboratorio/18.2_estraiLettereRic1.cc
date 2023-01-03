#include <iostream>
#include "18.2_estraiLettereRic.h"
using namespace std;

int main()
{
    char stringaIniziale[80], stringaFinale[80];
    cout << "Inserire una stringa di caratteri senza spazi: ";
    cin >> stringaIniziale;
    estrai(stringaIniziale, stringaFinale, 0, 0);
    if(stringaFinale[0] != '\0')
        cout << endl << "La stringa inserita, senza le lettere minuscole, corrisponde a: " << stringaFinale << endl;
    else
        cout << endl << "La stringa inserita non presenta lettere maiuscole" << endl;
    return 0;
}