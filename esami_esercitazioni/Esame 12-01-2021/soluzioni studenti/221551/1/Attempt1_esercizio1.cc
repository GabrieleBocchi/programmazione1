// GDT: fare riferimento alla soluzione ufficiale per un esempio di svolgimento.
// Per leggere un file, è sempre meglio usare dei cicli. La funzione scrivi() come l'hai
// pensata tu può portare ad un blocco del PC se eseguita su un file molto grande.

#include <iostream>
#include <fstream>
using namespace std;

const int LUNGHEZZA_PAROLA = 100 + 1;

int length( char buffer[] );
void scrivi( fstream &in, fstream &out );

int main(int argc, char * argv []) {
  if ( argc != 3 ) {
    cout << "Usage : ./a.out <fileInput> <fileOutput>\n";
    exit( 1 );
  }
  fstream fileIn, fileOut;
  fileIn.open( argv[ 1 ], ios::in );
  fileOut.open( argv[ 2 ], ios::out );
  if ( fileOut.fail() || fileIn.fail() ) {
    cout << "Impossibile aprire file\n";
    exit( 1 );
  }
  scrivi( fileIn, fileOut );
  fileOut.close();
  fileIn.close();
  return 0;
}

int length( char buffer[] ){
  int i = 0;
  for(; buffer[ i ] != '\0'; i++ );
  return i;
}

void scrivi( fstream &in, fstream &out ){
  char buffer[ LUNGHEZZA_PAROLA ];
  if ( !in.eof() ) {
    in>>buffer;
    scrivi( in, out );
  }
  if( length( buffer ) % 2 == 1 ) {
    out<<buffer<<" ";
  }
}
