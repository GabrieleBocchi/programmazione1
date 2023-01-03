#include <iostream>
#include <fstream>

using namespace std;

int main(int argn, char **argv) {

    char *in, *out;
    if (argn <= 1) {
        cout << "Errore" << endl;
        return 0;
    } else {
        in = argv[1];
        out = argv[2];
    }
    char **arrayParole = new char *[1000];
    int n = 0;
    char b;
    fstream fin, fout;
    fin.open(in, ios::in);
    fin >> std::noskipws;
    int i = 0;
    arrayParole[0] = new char[4];
    while (fin >> b) {
        if (b == ' ') {
            if (i <= 4) {
                n++;
                arrayParole[n] = new char[4];
            }
            i = 0;
            arrayParole[n] = new char[4];

        } else {
            arrayParole[n][i % 4] = b;
            i++;
        }
    }
    fin.close();
    fout.open(out, ios::out);
    for (int j = n - 1; j >= 0; j--) {
        fout << arrayParole[j] << " ";
        delete arrayParole[j];
    }
    fout.close();
    cout << "Done" << endl;
    return 0;
}
