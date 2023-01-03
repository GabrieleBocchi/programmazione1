#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char* argv[])
{



    fstream my_in, my_out;


    char tmp[101];
    char input_array[10000][101];
    char output_array[10000][101];



    if (argc != 3) {
        cout << "Usa: ./a.out  <input_file> <output_file>\n";
        exit(0);
    }


    my_in.open(argv[1], ios::in);
    my_out.open(argv[2], ios::out);

    int word_counter = 0;



    my_in >> tmp;



    while (!my_in.eof()) {
        int letter_counter = 0;

//conta i caratteri che ci sono nella parola fino a incontrare il fine stringa '\0'

        for (int i = 0; tmp[i] != '\0'; i++) {
            letter_counter++;
        }


        if (letter_counter <= 4) {
            for (int i = 0; tmp[i] != '\0'; i++) {
                input_array[word_counter][i] = tmp[i];
            }

            word_counter++;
        }

        my_in >> tmp;
    }

//le parole con 4 o meno caratteri vengono copiate nell'array di input
    for (int i = word_counter - 1; i >= 0; i--) {
        for (int e = 0; tmp[e] != '\0'; e++) {
            output_array[word_counter - i - 1][e] = input_array[i][e];
        }
    }

    for (int i = 0; i < word_counter; ++i) {
        my_out << output_array[i] << " ";
    }

    my_in.close();
    my_out.close();
    return (0);
}
