#include <iostream>
#include "pila.h"

using namespace std;

/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
void risolviLabirinto(int lab[][5], int x, int y);
void move(int lab[5][5], int x, int y, int endX, int endY, bool *end, cella visited[25], int i);
bool checkMove(int lab[5][5], int startX, int startY, int x, int y, cella visited[25]);
bool coordinateValid(int x, int y);
bool isvisited(cella visited[25], int x, int y);

int main(int argc, char *argv[])
{

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale

    // E' possibile modificare la matrice per effettuare dei test
    int labirinto[5][5] = {
        {1, 0, 1, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}};

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])
    cout << "Percorso: ";
    risolviLabirinto(labirinto, 4, 2);

    return 0;
}
void risolviLabirinto(int lab[5][5], int x, int y)
{
    init();

    // SB: una matrice sarebbe più efficiente, ma anche così va bene
    cella visited[25];
    bool *end;
    move(lab, 0, 0, x, y, end, visited, 0);

    // SB: stampa corretta 
    cella tmp;
    while (top(tmp))
    {
        pop();
        cout << "[" << tmp.indiceRiga << "," << tmp.indiceColonna << "], ";
    }
    
    // SB: la chiamata a "deinit()" non è necessaria (in quanto la stampa delle 
    //     celle svuota la pila), ma è sempre meglio aggiungerla
}

void move(int lab[5][5], int x, int y, int endX, int endY, bool *end, cella visited[25], int i)
{
    cella tmp;
    tmp.indiceRiga = x;
    tmp.indiceColonna = y;
    visited[i] = tmp;
    i++;

    if (x == endX && y == endY)
    {
        // SB: il ciclo dovrebbe partire da (i-1), altrimenti si aggiunge alla pila
        //     una cella non inizializzata (che di default ha valori settati a 0),
        //     ed è per questo motivo poi che il programma stampa un altro [0,0].
        //     Basta aggiungere l'istruzione "i--;" prima dell'inizio del ciclo for.  
        for (i; i >= 0; i--)
        {
            push(visited[i]);
        }
        *(end) = true;
    }

    if (!*(end))
    {

        if (checkMove(lab, x, y, x, y - 1, visited))
        {
            move(lab, x, y - 1, endX, endY, end, visited, i);
        }
        if (checkMove(lab, x, y, x, y + 1, visited))
        {
            move(lab, x, y + 1, endX, endY, end, visited, i);
        }
        if (checkMove(lab, x, y, x - 1, y, visited))
        {
            move(lab, x - 1, y, endX, endY, end, visited, i);
        }
        if (checkMove(lab, x, y, x + 1, y, visited))
        {
            move(lab, x + 1, y, endX, endY, end, visited, i);
        }
    }
}

bool checkMove(int lab[5][5], int startX, int startY, int x, int y, cella visited[25])
{
    if (coordinateValid(startX, startY) && coordinateValid(x, y))
    {

        // SB: controllo non necessario ma corretto
        int xDif = (startX - x < 0) ? ((startX - x) * (-1)) : startX - x;
        int yDif = (startY - y < 0) ? ((startY - y) * (-1)) : startY - y;

        if (xDif + yDif > 1)
        {
            cout << "sas" << endl;
            return false;
        }
        else
        {
            if ((lab[x][y]) == 1 && !isvisited(visited, x, y))
            {
                //cout << "da:" << startX << startY << " " << x << y << endl;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

bool coordinateValid(int x, int y)
{
    if (x > 4 || y > 4 || y < 0 || x < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isvisited(cella visited[25], int x, int y)
{
    for (int i = 0; i < 25; i++)
    {
        cella tmp = visited[i];
        if (x == tmp.indiceRiga && y == tmp.indiceColonna)
        {
            return true;
        }
    }
    return false;
}