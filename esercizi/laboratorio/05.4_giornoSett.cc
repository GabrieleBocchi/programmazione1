#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Inserire un numero compreso fra 1 e 7: ";
    cin >> n;
    switch (n)
    {
        case 1:
            cout << "Il giorno n." << n << " della settimana e' lunedi'" << endl;
            break;
        case 2:
            cout << "Il giorno n." << n << " della settimana e' martedi'" << endl;
            break;
        case 3:
            cout << "Il giorno n." << n << " della settimana e' mercoledi'" << endl;
            break;
        case 4:
            cout << "Il giorno n." << n << " della settimana e' giovedi'" << endl;
            break;
        case 5:
            cout << "Il giorno n." << n << " della settimana e' venerdi'" << endl;
            break;
        case 6:
            cout << "Il giorno n." << n << " della settimana e' sabato" << endl;
            break;
        case 7:
            cout << "Il giorno n." << n << " della settimana e' domenica" << endl;
            break;
        default:
            cout << "Il numero inserito non e' compreso fra 1 e 7" << endl;
    }
    return 0;
}