#include <iostream>
using namespace std;

int main()
{
    float prezzo, iva, ris;
    cout << "Inserire il prezzo del prodotto: ";
    cin >> prezzo;
    cout << "Inserire l'iva del prodotto: ";
    cin >> iva;
    ris = prezzo + prezzo * iva / 100;
    cout << "Il prezzo finale del prodotto e': " << ris << endl;
    return 0;
}