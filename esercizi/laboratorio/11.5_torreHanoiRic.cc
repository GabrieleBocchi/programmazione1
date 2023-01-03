#include <iostream>
using namespace std;

void risolviTorre(int disco, char partenza, char supporto, char arrivo);

int main()
{
    int disco;
    cout << "Inserire quanti dischi avra' la torre di Hanoi: ";
    cin >> disco;
    if(disco >= 1)
        risolviTorre(disco, 'A', 'B', 'C');
    else
        cout << "Il numero di dischi deve essere maggiore o uguale a 1" << endl;
    return 0;
}

void risolviTorre(int disco, char partenza, char supporto, char arrivo)
{
    if (disco == 1)
        cout << "Spostare il disco " << disco << " dal paletto " << partenza << " al paletto " << arrivo << endl;
    else
    {
        risolviTorre(disco - 1, partenza, arrivo, supporto);
        cout << "Spostare il disco " << disco << " dal paletto " << partenza << " al paletto " << arrivo << endl;
        risolviTorre(disco - 1, supporto, partenza, arrivo);
    }
    return;
}