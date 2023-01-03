#include <iostream>
using namespace std;

void inverti(int n);

int main()
{
    int n;
    cout << "Inserire un numero: ";
    cin >> n;
    cout << "L'inverso di " << n << " e': ";
    inverti(n);
    return 0;
}

void inverti(int n)
{
    int ris = 0, cont = -1, temp = n;
    while (temp != 0)
    {
        temp /= 10;
        cont++;
    }
    for (int i = cont; i >= 0; i--)
    {
        temp = n % 10;
        n /= 10;
        for (int j = 1; j <= i; j++)
            temp *= 10;
        ris += temp;
    }
    cout << ris << endl;
    return;
}