#include <iostream>
using namespace std;

int main()
{
    cout << "Tabella di verita' operatore AND:" << endl;
    cout << "0 AND 0 = " << (0 && 0) << endl;
    cout << "1 AND 0 = " << (1 && 0) << endl;
    cout << "0 AND 1 = " << (0 && 1) << endl;
    cout << "1 AND 1 = " << (1 && 1) << endl;

    cout << "Tabella di verita' operatore OR:" << endl;
    cout << "0 OR 0 = " << (0 || 0) << endl;
    cout << "1 OR 0 = " << (1 || 0) << endl;
    cout << "0 OR 1 = " << (0 || 1) << endl;
    cout << "1 OR 1 = " << (1 || 1) << endl;
    return 0;
}