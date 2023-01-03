#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
bool isSerial(char buffer[]);
bool isNum(char letter);
int main(int argc, char * argv [])
{
  if(argc!=3){
    cout << "inserire il nome dei file" << endl;
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  if(input.fail()||output.fail()){
    cout << "problemi con i file" << endl;
  }
  char buffer[100];
  int n=0;
  while(!input.eof()){
    input >> buffer;
    if(isSerial(buffer)){
      n++;
    }
  }
  output << n;
  input.close();
  output.close();
  return 0;
}

bool isSerial(char buffer[]){
  int pos=0;
  if(strlen(buffer)!=19){
    return false;
  }
  for(int a=0;a<4;a++){
    for(int i=0;i<4;i++){
      if(!isNum(buffer[i+pos])){
        return false;
      }
    }
    pos+=5;
  }
  if(buffer[4]!='-'||buffer[9]!='-'||buffer[14]!='-'){
    return false;
  }
  return true;
}
bool isNum(char letter){
  if('0'<=letter && letter<='9'){
    return true;
  }
  return false;
}
