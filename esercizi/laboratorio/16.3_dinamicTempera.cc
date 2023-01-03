#include <iostream>
#include <fstream>
using namespace std;

void bubbleSort(float array[], const int dimArray);

int main(int argc, char *argv [])
{
    if (argc != 4)
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
    int N = atoi(argv[2]);
    int M = 0;
    char temp[16];
    while (!file.eof())
    {
        file >> temp;
        M++;
    }
    if (M != atoi(argv[3]))
    {
        cout << "Il numero inserito non corrisponde con il numero di temperature effettivamente presenti nel file" << endl;
        return 0;
    }
    if (N > M)
    {
        cout << "Il numero di temperature che si desidera e' piu' grande del numero di temperature effettivamente presenti nel file" << endl;
        return 0;
    }
    file.clear();
    file.seekg(0, ios::beg);
    float *array = new float [M];
    for (int i = 0; i < M; i++)
        file >> array[i];
    bubbleSort(array, M);
    cout << "Le " << N << " temperature piu' alte presenti nel file sono: " << endl << endl;
    for (int i = 0; i < N; i++)
        cout << i + 1 << ") " << array[i] << endl;
    file.close();
    delete [] array;
    return 0;
}

void bubbleSort(float array[], const int dimArray)
{
    bool order = false;
    while (order == false)
    {
        order = true;
        for (int i = 1; i < dimArray; i++)
            if (array[i] > array[i - 1])
            {
                array[i] = array[i] + array[i - 1];
                array[i - 1] = array[i] - array[i - 1];
                array[i] = array[i] - array[i - 1];
                order = false;
            }
    }
    return;
}