#include <iostream>
using namespace std;

int main(int argc, char *argv [])
{
    if (argc != 4)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    int a = atof(argv[1]);
    int b = atof(argv[3]);
    switch (*argv[2])
    {
        case '+':
        cout << a << " + " << b << " = " << a + b << endl;
        break;
        case '-':
        cout << a << " - " << b << " = " << a - b << endl;
        break;
        case 'x':
        cout << a << " * " << b << " = " << a * b << endl;
        break;
        case '/':
        cout << a << " / " << b << " = " << a / b << endl;
        break;
        default:
        cout << "E' stato inserito un operatore non valido" << endl;
    }
    return 0;
}