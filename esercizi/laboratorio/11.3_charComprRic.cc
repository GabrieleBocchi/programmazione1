#include <iostream>
using namespace std;

void stampaCharRic(char a, char b);

int main()
{
    char a, b;
    cout << "Inserire due lettere entrambe maiuscole o entrambe minuscole. La prima deve precedere la seconda!" << endl;
    cout << "Inserire la prima lettera: ";
    cin >> a;
    cout << "Inserire la seconda lettera: ";
    cin >> b;
    if (((a >= 65 && b <= 90) || (a >= 97 && b <= 122)) && a < b)
    {
        cout << "Tra le lettere " << a << " e " << b << " sono comprese le lettere: ";
        stampaCharRic(a, b);
        cout << endl;
    }
    else
        cout << "Non sono state inserite lettere valide oppure la prima non precede la seconda" << endl;
    return 0;
}

void stampaCharRic(char a, char b)
{
    if (a - 1 == b)
        return;
    else
    {
        cout << a << "  ";
        stampaCharRic(a + 1, b);
    }
    return;
}