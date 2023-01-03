#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
    if(argc == 3){

        fstream myin, myout;
        myin.open(argv[1], ios::in);
        myout.open(argv[2], ios::out);
        if(myin.fail() || myout.fail()){
            cerr << "errore apertura files" << endl;
        }
        else{
            char **mat = new char*[10000];
            for(int i = 0; i < 10000; ++i){
                mat[i] = new char[101];
            }

            int i = 0;
            bool check = true;
            while(myin>>mat[i]){
                check = true;
                for(int c = 0; c < 5; c++){
                    if(mat[i][c] == '\0'){
                        check = false;
                    }
                }
                if(check == true){
                    i++;
                }
            }

            for(int j = i-1; j >= 0; j--){
                myout << mat[j] << " ";
            }

            myin.close();
            myout.close();

            for(int i = 0; i < 10000; ++i){
                delete[] mat[i];
            }
            delete[] mat;
        }
    }
    else{
        cerr << "usage: ./a.out input_A output" << endl;
    }
    return 0;
}
