#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float r, V;
    cout << "Inserire raggio: ";
    cin >> r;
    V = float(4) / float(3) * M_PI * r * r * r;
    cout << "Il volume della sfera di raggio " << r << " è: " << V << endl;
    return 0;
}