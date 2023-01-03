#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Inserire due valori numerici che rappresenteranno un intervallo ASCII di cui verranno stampate le corrispondenti lettere!" << endl;
    cout << "Entrambi i valori devono essere compresi tra 65 e 90 o tra 97 e 122!" << endl;
    cout << "Inserire il primo valore: ";
    cin >> a;
    cout << "Inserire il secondo valore: ";
    cin >> b;
    if (((a >= 65 && a <= 90 && b >= 65 && b <= 90) || (a >= 97 && a <= 122 && b >= 97 && b <= 122)) && b >= a)
    {
        cout << "Le lettere corrispondenti ai valori ASCII da " << a << " a " << b << " sono: ";
        for (int i = a; i <= b; i++)
            cout << "  " << char(i) << "  ";
        cout << endl;
    }
    else
        cout << "I valori inseriti non sono compresi negli intervalli stabiliti oppure il primo valore e' maggiore del secondo" << endl;
    return 0;
}