#include <iostream>
#include "20.2_pilaParentesiBil.h"
using namespace std;

int main()
{
    bool isBalanced = true;
    int dim = 100, aperte = 0, chiuse = 0;
    char stringa[dim];
    cout << "Inserire una stringa di parentesi: ";
    cin >> stringa;
    init();
    for (int i = 0; stringa[i] != '\0'; i++)
        push(stringa[i]);
    int n;
    while (top(n) && isBalanced)
    {
        if ((char)n == '(')
            aperte++;
        else if ((char)n == ')')
            chiuse++;
        if (aperte > chiuse)
            isBalanced = false;
        pop();
    }
    if (aperte != chiuse)
            isBalanced = false;
    if (isBalanced)
        cout << "Le parentesi sono bilanciate" << endl;
    else
        cout << "Le parentesi non sono bilanciate" << endl;
    deinit();
    return 0;
}