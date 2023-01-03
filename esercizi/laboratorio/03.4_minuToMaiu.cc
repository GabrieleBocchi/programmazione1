#include <iostream>
using namespace std;

int main()
{
    char a;
    cout << "Inserire una lettera minuscola: ";
    cin >> a;
    a -= 32;
    cout << "La lettera maiuscola corrispondente e': " << a << endl;
    return 0;
}