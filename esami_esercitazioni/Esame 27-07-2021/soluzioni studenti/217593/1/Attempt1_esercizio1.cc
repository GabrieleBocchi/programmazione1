#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool check_block(char* str, int block_len){
    bool res = true;
    for (int i = 0; i < block_len; ++i) {
        if(!isdigit(str[i]))res = false;
    }
    return res;
}

bool check(char* str){
    int blocks = 4;
    int block_len = 4;
    char separator = '-';
    bool res = true;
    if(strlen(str) == blocks*block_len + blocks-1){
        // OKAY ha 4 blocchi di 4 caratteri con 3 separatori
        for (int i =0,j=0; i<blocks; ++i){

            int index_sep = block_len*(i+1)+i;
            res = res && str[index_sep] == separator || str[index_sep] == '\0' && check_block(str+j, blocks);
            j = index_sep+1;

        }
    }else{
        res = false;
    }
    return res;

}



int main(int argc, char * argv [])
{
    if(argc < 3){
        cout << "Usage: /a.out input_file output_file" << endl;
        exit(1);
    }
    fstream input, output;

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail() || output.fail()){
        cout << "Errore. Impossibile aprire i file" << endl;
        input.close();
        output.close();
        exit(1);
    }

    char buffer[100];
    int n = 0;
    while(!input.eof()){
        input >> buffer;
        if(check(buffer)){
            n++;
        }
    }
    output << n;
    input.close();
    output.close();

    return 0;
}
