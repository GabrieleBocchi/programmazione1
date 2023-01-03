// GDT: il buffer di parole non rispetta la consegna. Sono al massimo 10000 parole. 
// L'esecizio non ritorna risultati corretti. In generale, fare riferimento alla soluzione
// ufficiale per un possibile svolgimento.
//
// L'equaglianza buffer[4] == NULL è errata. Sarebbe stato più giusto scrivere buffer[4] == '\0'.
// Quando scrivi nel file di output, il comando giusto sarebbe fileoutput << parole[i] << " ";
// Non è necessario scrivere carattere per carattere. 

#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char * argv [])
{

    if (argc!=3)
    {
      cout<<"errore: usare ./esercizio1 <file_input> <file_output>"<<endl;
      exit(0);
    }
    


    int indiceArray=0;
    
    //!=================================
    ifstream fileinput(argv[1]);
    
    //!=================================  
    
      char buffer[100];
      char parole[1000][100];
  

     if (fileinput.is_open())
    {
      
      
      int indice=0;
      fileinput >> buffer;
      while (!fileinput.eof()){
        
        if (buffer[4]!=NULL)
        {
          for (int i = 0; i < 100; i++)
          {
            parole[indice][i]=buffer[i];
              // cout<<parole[indice][i];
          }
         
          
         
          indice++;
        }
        
        fileinput >> buffer;
      } 
      
      if (buffer[4]!=NULL)
      {
         for (int i = 0; i < 100; i++)
          {
            parole[indice][i]=buffer[i];
          }
         
         
      }
       for (int i = 0; i < 100; i++)
          {
            cout<<parole[indice][i];
          }
       cout<<indiceArray<<endl;
      
      fileinput.close();
     } else cout << "Unable to open file";


     ofstream fileoutput (argv[2]);
      if (fileoutput.is_open())
      {
        for (int i = indiceArray; i > 0; i--)
        {
        
          for (int j = 0; j < 100; j++)
          {
              // cout<<parole[indice][i];
              fileoutput<<parole[i][j];
              
          }
          
        }
        
        fileoutput.close();
      }
      else cout << "Unable to open file";
  return 0;
}
