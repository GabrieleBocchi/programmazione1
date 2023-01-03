#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Studente
{
    char nome[16];
    char cognome[16];
    int matricola;
    float media_ponderata;
};

Studente *riempiDatabase(fstream &file, int righe);
Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);
void stampa_studente(const Studente & S);

int main(int argc, char *argv [])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream file;
    file.open(argv[1], ios::in);
    if (file.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    int righe = atoi(argv[2]);
    Studente *database = riempiDatabase(file, righe);
    for (int i = 0; i < righe; i++)
    {
        cout << "Studente n. " << i + 1 << endl << endl;
        stampa_studente(database[i]);
    }
    file.close();
    delete [] database;
    return 0;
}

Studente *riempiDatabase(fstream &file, int righe)
{
    Studente *database = new Studente [righe];
    char nome[16];
    char cognome[16];
    int matricola;
    float media_ponderata;
    for (int i = 0; i < righe; i++)
    {
        file >> nome;
        file >> cognome;
        file >> matricola;
        file >> media_ponderata;
        database[i] = genera_studente(nome, cognome, matricola, media_ponderata);
    }
    return database;
}

Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata)
{
    Studente s;
    strcpy(s.nome, nome);
    strcpy(s.cognome, cognome);
    s.matricola = matricola;
    s.media_ponderata = media_ponderata;
    return s;
}

void stampa_studente(const Studente & S)
{
    cout << "Nome: " << S.nome << endl;
    cout << "Cognome: " << S.cognome << endl;
    cout << "Matricola: " << S.matricola << endl;
    cout << "Media Ponderata: " << S.media_ponderata << endl << endl;
    return;
}