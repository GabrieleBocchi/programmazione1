// Giovanni: Non compila
// ./code/3/218078 - Gheser Amir/Attempt1_esercizio1.cc: In function ‘int main(int, char**)’:
// ./code/3/218078 - Gheser Amir/Attempt1_esercizio1.cc:19:45: error: ‘strerror’ was not declared in this scope
//         cerr << "Something went wrong\n" << strerror(errno) << endl;
//                                             ^~~~~~~~
// ./code/3/218078 - Gheser Amir/Attempt1_esercizio1.cc:19:45: note: suggested alternative: ‘perror’
//         cerr << "Something went wrong\n" << strerror(errno) << endl;
//                                             ^~~~~~~~
//                                             perror
// ./code/3/218078 - Gheser Amir/Attempt1_esercizio1.cc:24:45: error: ‘strerror’ was not declared in this scope
//         cerr << "Something went wrong\n" << strerror(errno) << endl;
//                                             ^~~~~~~~
// ./code/3/218078 - Gheser Amir/Attempt1_esercizio1.cc:24:45: note: suggested alternative: ‘perror’
//         cerr << "Something went wrong\n" << strerror(errno) << endl;
//                                             ^~~~~~~~
//                                             perror


#include <iostream>
#include <fstream>
using namespace std;

bool isMIU(char*);

int main(int argc, char * argv [])
{
    if (argc != 3){
        cerr << "Inappropriate usage!\n Try-> " << argv[0]
        << " <input_file> <output_file> " << endl;
        exit(1);
    }

    fstream input, output;
    // controlli sullo stream
    input.open(argv[1], ios::in);
    if (input.fail()){
        cerr << "Something went wrong\n" << strerror(errno) << endl;
        exit(1);
    }
    output.open(argv[2], ios::out);
    if (output.fail()){
        cerr << "Something went wrong\n" << strerror(errno) << endl;
        exit(1);
    }


    char buffer[101]; // = 100 + 1 <- MaxDim + '\0'

    input >> buffer;
    while (!input.eof()){
        if (isMIU(buffer))
        output << buffer << endl;
        input >> buffer;
    }

    //chiusura stream
    input.close();
    output.close();
    return 0;
}

bool isMIU(char* word){
    bool res = true;
    int dim=0;
    int counter;
    for (counter=0; res && word[dim]!='\0'; dim++){
        if (word[dim] == 'I'){
            counter++; //increments count of occurances of 'I'
            if (dim > 0 && word[dim-1] == 'M') //char before an 'I' there mustn't be an 'M'
                res = false;
        }
    }

    if (res && word[0] == 'U')
        res = word[dim-1] == 'M';

    if (res)
        res = counter%2 == 0;

    return res;
}
