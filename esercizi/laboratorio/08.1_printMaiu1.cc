#include <iostream>
using namespace std;

bool isMinu(char a);
char convert(char a);

int main()
{
    char a;
    cout << "Inserire una lettera minuscola: ";
    cin >> a;
    if (isMinu(a))
        cout << "La corrispondente lettera maiuscola e': " << convert(a) << endl;
    else
        cout << "Deve essere inserita una lettera minuscola" << endl;
    return 0;
}

bool isMinu(char a)
{
    if (a >= 97 && a <= 122)
        return true;
    else
        return false;
}

char convert(char a)
{
    return a - 32;
}