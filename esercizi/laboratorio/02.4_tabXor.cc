#include <iostream>
using namespace std;

int main()
{
    bool A = true, B = true;
    cout << "Tabella di verita' operatore XOR:" << endl;
    cout << "0 XOR 0 = " << (!A ^ !B) << endl;
    cout << "1 XOR 0 = " << (A ^ !B) << endl;
    cout << "0 XOR 1 = " << (!A ^ B) << endl;
    cout << "1 XOR 1 = " << (A ^ B) << endl;
    return 0;
}