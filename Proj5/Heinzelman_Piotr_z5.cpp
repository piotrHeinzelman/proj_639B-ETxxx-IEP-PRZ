#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <regex>
#include <iterator>


using namespace std;



/*


Programowanie
zima 2021/2022
Zadanie 5 – z plikami (0.5 pkt)

1. Z pliku o nazwie podanej przez uzytkownika wczytac wierszami dane rzeczywiste
	(moga bya ujemne, moga byc bez kropki) do tablicy A[w][k] (w, k - stale).
	Jesli danych w pliku bedzie za malo, wolne miejsca w tablicy A powinny bya wypelnione wartoscia stala Z.

2. Wydrukowac tablice wierszami ze stala liczba P miejsc po kropce i stala szerokoscia D kolumn.

3. Dla kazdego wiersza tablicy:
   a. wydrukowac srednia wszystkich elementów w tym wierszu

   b. wydrukowac srednia skrajnych elementów w tym wierszu (czyli pierwszego i ostatniego)

   c. przesunca cyklicznie w lewo ten wiersz, jesli srednia wszystkich elementów w tym wierszu jest wieksza od sredniej skrajnych elementów tego wiersza.

4. Ponownie wydrukowac tablice (w formacie jak w p. 2).

5. Na koniec cala tablice zapisac wierszami (w formacie jak w p. 2) do pliku o nazwie
	"nowa.txt".

Wskazówki:
	1. nale¿y sygnalizowaæ brak pliku z danymi o podanej nazwie i zakoñczyæ program.
	2. najpierw wype³niamy sta³¹ Z ca³¹ tablicê, a potem z pliku wczytujemy wierszami tablicê
	analogicznie jak z klawiatury – wczyta siê co najwy¿ej tyle danych, ile jest w pliku (nie trzeba sprawdzaæ eof).
	3. Przesuwanie cykliczne w tablicy jest omówione w lekcji 3.2.

*/




int main()
{

    const int W=14; // mozna uzyc wielkiej zgodnie z konwencja wielkie dla stalych, czy trzeba malej jak w zadaniu ?
    const int K=5;
    const double Z=3.1415926535;
    double dbl=Z;

    const int P=3;
    const int D=10; //2. Wydrukowaæ tablicê wierszami ze sta³¹ liczb¹ P miejsc po kropce i sta³¹ szerokoœci¹ D kolumn.

    bool eof;

    double ary[W][K];

    double averageRow;
    double totalRow;

    double averageStartEnd;



    string fileName;
    string line;

    ifstream ifile;
    ofstream ofile;

    cout << "Podaj nazwe pliku: \n[enter] dla domyslnego pliku -> c:\\temp\\data.txt" << endl;
    getline( cin, fileName );
    if ( fileName.size()==0 ) fileName="c:\\temp\\data.txt";

    ifile.open( fileName.c_str()); //if (  writeFile ) ofile.open( fileName.c_str()); //file.open( fileName.c_str(), ios::app);
    if ( !ifile.is_open() ) { cout << "problem z otwarciem pliku do odczytu." ; return 1; }

    for ( int i=0; i<W; i++ ){
        for ( int j=0;j<K;j++) {
        if ( ifile.eof()) { eof=true; ifile.close(); }
        if ( !eof ) { ifile >> dbl; } else { dbl = Z; }
        ary[i][j]=dbl;
        }
    }


    //show data
    for ( int i=0; i<W; i++ ) {
        for ( int j=0; j<K; j++ ) {
            cout << setw(D) << setprecision(P) << fixed << ary[i][j];
        }
        cout<<"\n";
    }
      cout<<"\n\n***************\n\n";


    for ( int i=0; i<W; i++ ) {
    // pkt3. for every row.
        averageRow=0;totalRow=0;
        averageStartEnd=((ary[i][0])+(ary[i][K-1]))/2;

        //calcAverageRow
        for ( int j=0; j<K; totalRow+=ary[i][j], j++ );
        averageRow=totalRow/K;

        cout <<"\nRow["<<i<<"]: srednia: " << averageRow << ", skrajne: " << averageStartEnd << ", ";
        if ( averageRow<=averageStartEnd ) { cout << "nie przesuwam"; continue; }
        cout << "przesuwam.";
        double tmp = ary[i][0];
        for (int j=1;j<K;ary[i][j-1]=ary[i][j],j++);
        ary[i][K-1]=tmp;
    //
    }

   //c. przesunca cyklicznie w lewo ten wiersz, jesli srednia wszystkich elementów w tym wierszu jest wieksza od sredniej skrajnych elementów tego wiersza.

   cout<<"\n\n***************\n\n";

    //show data
    for ( int i=0; i<W; i++ ) {
        for ( int j=0; j<K; j++ ) {
            cout << setw(D) << setprecision(P) << fixed << ary[i][j];
        }
        cout<<"\n";
    }

    string nw="nowa.txt";
    int i=fileName.length();
    for ( i--;fileName[i]!=92;i-- );
    for ( int j=0;j<nw.length();i++,fileName[i]=nw[j],j++);fileName[1+i]=0;


    cout << "Zapisuje dane w pliku: " << fileName;
    ofile.open( fileName.c_str() );
    //dataToFile
    for ( int i=0; i<W; i++ ) {
        for ( int j=0; j<K; j++ ) {
            ofile << setw(D) << setprecision(P) << fixed << ary[i][j];
        }
        ofile<<"\n";
    }
    ofile.close();


    return 0;
}
