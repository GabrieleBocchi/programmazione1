#include "18.2_estraiLettereRic.h"

void estrai(char iniziale[], char finale[], int contI, int contF)
{
    if (iniziale[contI] == '\0')
    {
        finale[contF] = '\0';
        return;
    }
    else if (iniziale[contI] >= 65 && iniziale[contI] <= 90)
    {
        finale[contF] = iniziale[contI];
        estrai(iniziale, finale, ++contI, ++contF);
    }
    else
        estrai(iniziale, finale, ++contI, contF);
    return;
}