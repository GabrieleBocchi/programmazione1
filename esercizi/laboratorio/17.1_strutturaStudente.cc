#include <iostream>
#include <cstring>
using namespace std;

struct Studente
{
    char nome[16];
    char cognome[16];
    int matricola;
    float media_ponderata;
};

Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);
void stampa_studente(const Studente & S);

int main()
{
    char nome[16], cognome[16];
    int matricola;
    float media_ponderata;
    cout << "Inserire il nome dello studente: ";
    cin >> nome;
    cout << "Inserire il cognome dello studente: ";
    cin >> cognome;
    cout << "Inserire il numero di matricola dello studente: ";
    cin >> matricola;
    cout << "Inserire la media ponderata dello studente: ";
    cin >> media_ponderata;
    Studente s = genera_studente(nome, cognome, matricola, media_ponderata);
    stampa_studente(s);
    return 0;
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
    cout << endl;
    cout << "Studente: " << endl << endl;
    cout << "Nome: " << S.nome << endl;
    cout << "Cognome: " << S.cognome << endl;
    cout << "Matricola: " << S.matricola << endl;
    cout << "Media Ponderata: " << S.media_ponderata << endl;
    return;
}