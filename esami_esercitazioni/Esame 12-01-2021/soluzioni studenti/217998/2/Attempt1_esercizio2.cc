#include <cstddef>
#include <iostream>

using namespace std;

void print(const int a[], const int s, const char *prefix) {
    cout << prefix;
    for (int i = 0; i < s; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void read_elements(int s[], const int ms, int &s_s) {
    int r = 0;
    for (s_s = 0; ((s_s < ms) && (r != -1));) {
        cin >> r;
        if (r != -1)
            s[s_s++] = r;
    }
}

void get_elements(const int src[], const int srcLength, int dest1[], const int dest1Length, int &dest1I, int dest2[], const int dest2Length, int &dest2I, int srcI = 0) {
    if (srcI < srcLength) {
        if (srcI % 2 == 0 && src[srcI] % 3 == 0) {
            if (dest1I < dest1Length) {
                dest1[dest1I++] = src[srcI++];
            }
        } else {
            if (dest2I < dest2Length) {
                dest2[dest2I++] = src[srcI++];
            }
        }
        get_elements(src, srcLength, dest1, dest1Length, dest1I, dest2, dest2Length, dest2I, srcI);
    }
}

int main() {
    const int maxdim = 10;

    const int md1_s = maxdim;
    int d1[md1_s];
    int d1_s = 0;

    const int md2_s = maxdim;
    int d2[md2_s];
    int d2_s = 0;

    const int ms = maxdim;
    int s[ms];
    int s_s = 0;

    read_elements(s, ms, s_s);

    get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

    print(s, s_s, "Source = ");
    print(d1, d1_s, "D1     = ");
    print(d2, d2_s, "D2     = ");
}
