#include <iostream>

using namespace std;

/*

1.  *wymusza* wpisanie liczby ca�kowitej x zawartej w przedziale <A,B> gdzie A i B sta�e
2.  drukuje (wy�wietla) warto�� x
3.  wczytuje ci�g liczb ca�kowitych a� do wczytania liczby parzystej  lub podzielnej (bez reszty) przez x
4.  drukuje (wy�wietla) najwi�ksz� liczb� ujemn� z tego ci�gu ( nie bior�c pod uwag� liczby ko�cz�cej) lub informacj� �e nie by�o liczb ujemnych

*/

int main()
{
    const int A=-20;
    const int B= 20;
    int x=A-1;
    int bigger=NULL;
    int input;
    string output;

    cout << " Podaj wartosc z przedzialu <" << A << " , " << B << ">";

    while ( (x<A) || (x>B) ) {
      cout << "\nwartosc z przedzialu poporsze : " << endl;
      cin >> x;
    }

    cout << "\n\nWspaniale, wybrales liczbe : " << x << "\n\n";

    cout << "Teraz poprosze o ciag wartosci.\n";

    do {
        // szukam przedostatniej wiekszej niz bigger a mniejszej niz 0
        if ( (input<0) && ( (input>bigger) || ( bigger==NULL ) )  ) { bigger=input; }

        cout << "\npoprosze nastepna: ";
        cin >> input;
        cout << "\n wpisales: " << input;
    }
    while ( (input%2!=0) && (input%x!=0) );

    //cout << "\nostatnia to:"  << input ;
    cout << "\nnajwieksza to:"  << bigger ;

    output = bigger < 0 ? "\najwieksza ujemna to:"+bigger : "nie podales ujemnych wartosci, zegnam.";

    cout << output;

    return 0;
}
