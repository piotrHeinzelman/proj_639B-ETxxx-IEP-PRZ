#include <iostream>

using namespace std;


/*

a. Definiuje stala calkowita N o dowolnej wartosci >1(jesli N<=1, program konczy dzialanie).
b. Wczytuje (petla for) N liczb calkowitychi drukuje dwie najwieksze z nich(bez uzycia tablic).
c. Wczytuje (petla for) N napisów i drukuje dwa ostatnie z nich(bez uzycia tablic).
d. Wczytuje (patla for) N znaków i drukuje co drugi wczytany znak w kolejnosci od ostatniego do pierwszego
 (tu trzeba zastosowaæ tablice jednowymiarowa).

Wskazówki:
  ad b) potrzebne sa dwie zmienne do zapamietywania aktualnie dwóch najwiekszych liczb;
  ad c) potrzebne sa dwie zmienne do zapamietywania aktualnie dwóch ostatnich napisów;
  ad c) i d) wczytywanie napisów wykonywac operatorem cin, oddzielajac je od siebie spacjami lub Enterami
  (analogicznie jak liczby), znaki (widoczne) tez wczytujemy operatorem cin, mozna ich od siebie nie oddzielac.

*/

int const N=3;
int twinOlder=0;
int twinYounger=0;
int helpingHand=0;
int inputInt=0;

string last;
string oneBeforeLast;

char chars[N];

int main()
{
    if (N<=1) { cout << "wartosc musi byc wieksza niz 1"; return 1; }

    //b
    cout << "Podaj N liczb: \n";
    for ( int i=0;i<N;i++) {
        cout << "\n: ";
        cin >> inputInt;

        if (i==0) { twinOlder = inputInt; }
        if (i==1) { twinYounger = inputInt; }

        if ( inputInt > twinYounger ) {
            twinYounger=inputInt;
            if ( twinOlder<twinYounger) { // xchg
                helpingHand=twinOlder;
                twinOlder=twinYounger;
                twinYounger=helpingHand;
            }
        }
    }
    cout << "Dwie najwieksze w kolejnosci rosnacej to: " << twinYounger << " i " << twinOlder;

    //c
    for (int i=0;i<N;i++) {
        oneBeforeLast=last;
        cout << "\npodaj kolejny ciag: ";
         cin >> last;
                //cout << "// oBL:" << oneBeforeLast << ", last:" << last;
    }
    cout << "Przedostatni ciag: \"" << oneBeforeLast << "\", ostatni: \"" << last << "\"";


    //d
    //char chars [N];


    for (int i=0;i<N;i++){

        if ( i==0 )       { cout << "\npodaj pierwszy znak znak: "; }
        else if ( i==N-1) { cout << "\npodaj ostatni znak: "; }
        else              { cout << "\npodaj kolejny znak: "; }

        cin >> chars[i];
    }


    cout << "\nprzesiany ciag: \n";
    for (int i=N-1;i>=0;i+=2) {     //   N-ty do drugiego
    // for (int i=N-1;i>=0;i--) { i--; // N-1-ty do pierwszego
        cout<<chars[i];
    }
    return 0;
}
