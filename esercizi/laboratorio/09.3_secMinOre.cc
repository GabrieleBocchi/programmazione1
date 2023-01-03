#include <iostream>
using namespace std;

void converti(int &ore, int &minuti, int &secondi);

int main()
{
    int ore, minuti, secondi;
    cout << "Inserire le ore: ";
    cin >> ore;
    cout << "Inserire i minuti: ";
    cin >> minuti;
    cout << "Inserire i secondi: ";
    cin >> secondi;
    if (ore >= 0 && minuti >= 0 && secondi >= 0)
    {
        converti(ore, minuti, secondi);
        cout << "L'orario inserito e' equivalente a: " << ore << " ore, " << minuti << " minuti, " << secondi << " secondi" << endl;
    }
    else
        cout << "I tre valori devono essere maggiori o uguali a 0" << endl;
    return 0;
}

void converti(int &ore, int &minuti, int &secondi)
{
    minuti += secondi / 60;
    secondi %= 60;
    ore += minuti / 60;
    minuti %= 60;
    return;
}