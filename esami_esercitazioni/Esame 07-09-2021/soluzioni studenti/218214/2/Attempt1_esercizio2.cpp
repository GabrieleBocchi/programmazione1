#include <iostream>
#include <cstring>

/* Inserire qui sotto la dichiarazione della funzione extract */
char *extract(const char *str);
/* Inserire qui sopra la dichiarazione della funzione extract */

void aux(const char *str, char *res, int index1, int index2, int length);

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char **argv)
{
    char input_string[DIM + 1];
    char *extracted;
    char answer;

    do
    {
        std::cout << "Inserire la stringa da controllare: ";
        std::cin >> input_string;

        extracted = extract(input_string);
        std::cout << "La stringa estratta e': " << extracted << std::endl;

        delete[] extracted;
        std::cout << "Si vuole inserire un'altra stringa? [*/n]";
        std::cin >> answer;
    } while (answer != '\0' && answer != 'N' && answer != 'n');
    return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char *extract(const char *str)
{
    int len = strlen(str);
    // MR: L'uso di strlen NON era consentito, infatti ha dovuto
    // aggiungere include <cstring>!
    char *str2 = new char[len];
    // Notare che qui avrebbe dovuto allocare len+1. Le stringhe hanno
    // N+1 elementi, elemento N contiene \0!
    int index1 = 0;
    int index2 = 0;
    /*for (int i = 0; i < len; i++)
    {
        if (str[i] == '@')
        {
            str2[index2] = str[i];
            index2++;
        }
    }*/
    aux(str, str2, index1, index2, len);

    return str2;
}
/* Inserire qui sopra la definizione della funzione estract */

void aux(const char *str, char *res, int index1, int index2, int length)
{
  // std::cout << index1 << "  " << index2 << std::endl;
    if (index1 < length)
    {
        if (str[index1] == '@')
        {
            res[index2] = str[index1];
            index2++;
        }
        aux(str, res, index1++, index2, length);
	// MR: Qui con index1++ non sta propagando il +1 alla chiamata
	// successiva, infatti index1++ ha come denotazione il valore
	// di index1 prima dell'incremento! Se avesse usato ++index1 o
	// meglio ancora index1 + 1, allora sarebbe stato corretto! In
	// questo modo avrebbe propagato la modifica alle chiamate
	// ricorsive. Si ricorda che a lezione ho sconsigliato
	// caldamente di usare ++ a meno che non si sappia bene cosa
	// si sta facendo!
    }
    else
    {
        res[index2] = '\0';
	// MR: Qui sta potenzialmente scrivendo in memoria NON
	// allocata! E.g. caso in cui la strina sia solo costituita da
	// @!
    }
}
