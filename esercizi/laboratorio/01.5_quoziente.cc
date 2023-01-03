#include <iostream>
using namespace std;

int main()
{
    int dividendo, divisore;
    cout << "Inserire dividendo: ";
    cin >> dividendo;
    cout << "Inserire divisore: ";
    cin >> divisore;
    cout << dividendo << " / " << divisore << " = " << dividendo / divisore << endl;
    cout << "Resto: " << dividendo % divisore << endl;
    return 0;
}