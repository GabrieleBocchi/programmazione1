#include <iostream>
using namespace std;

int main()
{
    int ore, minuti, secondi, ris;
    cout << "Inserire ore: ";
    cin >> ore;
    cout << "Inserire minuti: ";
    cin >> minuti;
    cout << "Inserire secondi: ";
    cin >> secondi;
    ris = (ore % 24) * 3600 + minuti * 60 + secondi;
    cout << "Da mezzanotte sono passati " << ris << " secondi" << endl;
    return 0;
}