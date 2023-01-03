#include "18.1_cifrCesare.h"

void crypt(char parola [], int chiave)
{
    int n;
    for (int i = 0; parola[i] != '\0'; i++)
    {
        n = (int)parola[i];
        n += chiave;
        if (n > 122)
            n = 96 + (n % 122);
        parola[i] = n;
    }
    return;
}

void decrypt(char parola [], int chiave)
{
    int n;
    for (int i = 0; parola[i] != '\0'; i++)
    {
        n = (int)parola[i];
        n -= chiave;
        if (n < 97)
            n = 123 - (97 - n);
        parola[i] = n;
    }
    return;
}