#include <iostream>

using namespace std;

void get_elements(char *source, int source_s, char *dest1, int &dest1_s, char *dest2, int &dest2_s) {
    if (source_s == 0) {
        return;
    }
    char c = source[0];
    if ('a' <= c && c <= 'z') {
        dest1[0] = c;
        dest1 = (dest1 + 1);
    }

    if ('A' <= c && c <= 'Z') {
        dest2[0] = c;
        dest2 = (dest2 + 1);
    }
    source = (source + 1);
    source_s--;
    get_elements(source, source_s, dest1, dest1_s, dest2, dest2_s);
}

int main() {

    int soutce_s = 100, dest1_s = 100, dest2_s = 100, i = 0;
    char *source = new char[soutce_s], *dest1 = new char[dest1_s], *dest2 = new char[dest2_s];
    for (int j = 0; j < soutce_s; j++) {
        source[j] = 0;
    }
    for (int j = 0; j < dest1_s; j++) {
        dest1[j] = 0;
    }
    for (int j = 0; j < dest2_s; j++) {
        dest2[j] = 0;
    }
    cin >> std::noskipws;
    char b;
    bool ok = true;
    while (ok) {
        cin >> b;
        if (b == 10)ok = false;
        source[i] = b;
        i++;
        cout << int(b);
    }

    for (int j = 0; j < soutce_s; j++) {
        cout << source[j];
    }
    get_elements(source, soutce_s, dest1, dest1_s, dest2, dest2_s);
    cout << endl << "minuscole:" << endl;
    for (int j = 0; j < dest1_s; j++) {
        cout << dest1[j];
    }
    cout << endl << "Maiuscole:" << endl;
    for (int j = 0; j < dest2_s; j++) {
        cout << dest2[j];
    }
    return 0;
}

