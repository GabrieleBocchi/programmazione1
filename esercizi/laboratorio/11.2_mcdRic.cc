#include <iostream>
using namespace std;

int mcdRic(int a, int b);

int main()
{
    int a, b;
    cout << "Inserire il primo numero (maggiore o uguale 1): ";
    cin >> a;
    cout << "Inserire il secondo numero (maggiore o uguale 1): ";
    cin >> b;
    if (a >= 1 && b >= 1)
    {
        int ris;
        if (a >= b)
            ris = mcdRic(a, b);
        else
            ris = mcdRic(b, a);
        cout << "Il massimo comune divisore tra " << a << " e " << b << " e' " << ris << endl;
    }
    else
        cout << "I due numeri devono essere maggiori o uguali a 1" << endl;
    return 0;
}

int mcdRic(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return mcdRic(b, a % b);
}