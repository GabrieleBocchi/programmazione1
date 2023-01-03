//Leonardo Pivetta mat. 217395
#include <iostream>
#include <fstream>
using namespace std;

int countI(char* buffer);
bool checkCondition(char* buffer);
bool checkIM(char* buffer);

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Erorre nel formato" << endl;
    return 0;
  }

  char* inputName = argv[1]; 
  char* outputName = argv[2];

  fstream inputFile, outputFile;

  inputFile.open(inputName, ios::in);
  if(inputFile.fail()){
    cout << "Errore nell'apertura del file di input" << endl;
    inputFile.close();
    return 0;
  }

  outputFile.open(outputName, ios::out);
  if(outputFile.fail()){
    cout << "Errore nell'apertura del file di output" << endl;
    inputFile.close();
    outputFile.close();
    return 0;
  }
  

  char buffer[101];

  while(!inputFile.eof()){
    inputFile >> buffer;
    if(checkCondition(buffer)){
      outputFile << buffer << endl;
    }
  }

  inputFile.close();
  outputFile.close();

  return 0;
}



bool checkCondition(char* buffer){
  if(*buffer == 'M'){
    char* tempBuffer = buffer;
    while (tempBuffer[1] !='\0'){
      tempBuffer++;
    }
    if(*tempBuffer != 'U'){
      return false;
    }
  }
  int nI = countI(buffer);
  if(nI != 0 && nI%2 == 0){
    return false;
  }
  if(!checkIM(buffer)) return false;

  return true;
}

int countI(char* buffer){
  if(*buffer == '\0'){
    return 0;
  }
  if(*buffer == 'I'){
    return 1+countI(++buffer);
  }
  return countI(++buffer);
}

bool checkIM(char* buffer){
  if(*buffer == '\0'){
    return true;
  }
  if(*buffer == 'I'){
    if(buffer[1] == 'M'){
      return false;
    }
  }
  return checkIM(++buffer);
}