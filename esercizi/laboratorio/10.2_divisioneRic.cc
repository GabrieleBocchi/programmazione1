#include <iostream>
using namespace std;

int divisioneRic(int dividendo, int divisore);

int main()
{
    int dividendo, divisore;
    cout << "Inserire il dividendo: ";
    cin >> dividendo;
    cout << "Inserire il divisore (diverso da 0): ";
    cin >> divisore;
    if (divisore != 0)
    {
        int ris = divisioneRic(dividendo, divisore);
        cout << dividendo << " / " << divisore << " = " << ris << endl;
    }
    else
        cout << "Il divisore deve essere diverso da 0" << endl;
    return 0;
}

int divisioneRic(int dividendo, int divisore)
{
    if (dividendo >= 0 && divisore > 0)
        if (dividendo >= divisore)
        {
            dividendo -= divisore;
            return 1 + divisioneRic(dividendo, divisore);
        }
        else
            return 0;
    else if (dividendo >= 0 && divisore < 0)
        if (dividendo >= -divisore)
        {
            dividendo += divisore;
            return -1 + divisioneRic(dividendo, divisore);
        }
        else
            return 0;
    else if (dividendo < 0 && divisore > 0)
        if (dividendo <= -divisore)
        {
            dividendo += divisore;
            return -1 + divisioneRic(dividendo, divisore);
        }
        else
            return 0;
    else
        if (dividendo <= divisore)
        {
            dividendo -= divisore;
            return 1 + divisioneRic(dividendo, divisore);
        }
        else
            return 0;
}