#include <iostream>

using namespace std;

/*

1.  *wymusza* wpisanie liczby calkowitej x zawartej w przedziale <A,B> gdzie A i B stale czyli tu: -20, -19 ... 19, 20
2.  drukuje (wyswietla) wartosc x
3.  wczytuje ciag liczb calkowitych az do wczytania liczby parzystej  lub podzielnej (bez reszty) przez x
4.  drukuje (wyswietla) najwieksza liczba ujemna z tego ciagu ( nie biorac pod uwage liczby konczacej ) lub informacje ze nie bylo liczb ujemnych
    info: największa ujemna to -1.

*/

int main()
{
    const int A=-20;
    const int B= 20;
    int x;
    int bigger=0;
    int input;
    string output;

    cout << " Podaj wartosc z przedzialu <" << A << " , " << B << ">";

    do {
        cout << "\nwartosc z przedzialu poporsze : (jeśli podasz zero - dostaniesz wyjątek)\n" ;
        cin >> x;
    } while ( (x<A) || (x>B) );

    cout << "\n\nWspaniale, wybrales liczbe : " << x << "\n\nTeraz poprosze o ciag wartosci.\n";

    do {
        if ( (input<0) && ( ( bigger==0 || input>bigger ))) {
            bigger=input;
        }

        cout << "\npoprosze nastepna: ";
        cin >> input;
    }
    while ( (input%2!=0) && (input%x!=0) );

    if ( bigger == 0 ) {
        cout << "nie podales ujemnych wartosci, zegnam.";
        return 0;
    }

    cout << "\nNajwieksza ujemna to:" << bigger;
    return 0;
}