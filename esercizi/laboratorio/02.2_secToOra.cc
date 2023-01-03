#include <iostream>
using namespace std;

int main()
{
    int input, ore, minuti, secondi;
    cout << "Inserire i secondi passati da mezzanotte: ";
    cin >> input;
    ore = (input % 86400) / 3600;
    minuti = (input % 3600) / 60;
    secondi = input % 3600 % 60;
    cout << "L'ora attuale e': " << ore << ":" << minuti << ":" << secondi << endl;
    return 0;
}