#include <iostream>
using namespace std;

int main()
{
    char a;
    cout << "Inserire un carattere: ";
    cin >> a;
    a = (a + 10) % 256;
    cout << "Il carattere inserito nella codifica ASCII+10 corrisponde al carattere: " << a << endl;
    return 0;
}