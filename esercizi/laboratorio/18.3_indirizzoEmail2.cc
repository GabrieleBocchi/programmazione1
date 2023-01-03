#include "18.3_indirizzoEmail.h"

bool check(char parola[])
{
    int dim = 0;
    int chiocciola = 0;
    int posChiocciola;
    for (int i = 0; parola[i] != '\0'; i++)
    {
        if (parola[i] == '@')
        {
            chiocciola++;
            posChiocciola = i;
        }
        dim++;
    }
    if (chiocciola != 1)
        return false;
    if (posChiocciola == 0 || posChiocciola == dim - 1)
        return false;
    if (parola[0] == '.' || parola[dim - 1] == '.')
        return false;
    for (int i = 0; i < dim; i++)
        if (!(parola[i] == '@' || (parola[i] >= 48 && parola[i] <= 57) || (parola[i] >= 65 && parola[i] <= 90) || (parola[i] >= 97 && parola[i] <= 122) || parola[i] == '.' || parola[i] == '_'))
            return false;
    return true;
}