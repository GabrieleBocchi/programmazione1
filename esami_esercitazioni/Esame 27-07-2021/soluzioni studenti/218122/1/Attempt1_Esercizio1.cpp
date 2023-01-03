#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{

if(argc!=3){
    cout<<"argc!=3"<<endl;
}
else{

    fstream input, output;

    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);

    if(input.fail()||output.fail()){
        cout<<"stream error"<<endl;
    }
    else{

    char buffer[100];
    int coun=0;

    while(input>>buffer){



        bool check=true;

        if(strlen(buffer)==16){

            for(int i=0;i<16&&check;i++){

            if(i<=11)if(buffer[i]<48||buffer[i]>57){
                    check=false;
                }

            if(i>11)if(buffer[i]<65||buffer[i]>90){
                    check=false;
                }

            }

        }
        else
            check=false;

        if(check){
            coun++;
        }

    }

    output<<coun;
    }

    input.close();
    output.close();

}
  return 0;
}
