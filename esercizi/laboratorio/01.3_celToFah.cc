#include <iostream>
using namespace std;

int main()
{
    float F;
    cout << "Inserire temperatura in gradi Fahrenheit: ";
    cin >> F;
    float C = (F - 32) / 1.8;
    cout << F << " gradi Fahrenheit equivalgono a " << C << " gradi Celsius" << endl;
    return 0;
}