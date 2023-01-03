#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float r;
    cout << "Inserire raggio: ";
    cin >> r;
    float A = M_PI * r * r;
    float C = 2 * M_PI * r;
    cout << "L'area del cerchio di raggio " << r << " è: " << A << endl;
    cout << "La circonferenza del cerchio di raggio " << r << " è: " << C << endl;
    return 0;
}