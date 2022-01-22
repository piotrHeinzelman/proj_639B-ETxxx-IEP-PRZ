#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/*

Zadanie 4–z tablic¹ dwuwymiarow¹ (0.75 pkt)
a. Tablicê A[n][n] (n-sta³a) wype³niæ liczbami losowymi
   ca³kowitymi z przedzia³u <D,G> (D, G-sta³e).

b. Wydrukowaæ tablicê wierszami z ustawion¹ za pomoc¹ sta³ej W szerokoœci¹ wydruku.

c. W dodatkowym wierszu pod tak wydrukowan¹ tablic¹ wydrukowaæ:
   - pod kolumn¹ o indeksie 0 –iloœæ liczb parzystych w tej kolumnie
   - pod ka¿d¹ nastêpn¹ kolumn¹ – ró¿nicê pomiêdzy iloœci¹ liczb parzystych w tej kolumnie
     a iloœci¹ liczb parzystych w kolumnie poprzedniej.

d. ZnaleŸæ najwiêkszy element g³ównej przek¹tnej w tablicy A
   i zapamiêtaæ oraz wydrukowaæ indeks wiersza, w którym siê on znajduje.

e. Zamieniæ miejscami znaleziony najwiêkszy element z najmniejszym elementem wiersza,
   w którym go znaleziono.

f. Wydrukowaæ zawartoœæ tego wiersza po dokonanej zamianie.

   Wskazówka:
   1. Za najwiêkszy/najmniejszy element przyj¹æ pierwszy znaleziony
   (bo mo¿e byæ kilka najwiêkszych/najmniejszych w danym obszarze).
    *//*

   2. Nie nale¿y u¿ywaæ funkcji swap()do wykonania zamiany.

*/
const int n=3;       // array size // width (table in column)
const int w=4;      // width (table)
const int W=(w*n)+10;
const int D=-3;       // Down Limit
const int G=10;      // Greatest :)
const int GmD = G-D+1;
char h(int i){cout<<(char)((i&1*(i%4)-((i&2)>>1)));}
int parity[n]{0};
int row=0;
int delta=0;
int colNum=0;
int yoCol;


int main()
{
    srand( time(NULL) );
    int A[n][n]{{0,1,2},{0,1,2},{4,3,2}};


    if (false) {
        for (int r=0;r<n;r++){  // Fill table
            for (int i=0;i<n;i++){
                if (( A[r][i]=D+rand()%GmD )&1 ) {} else parity[i]++;
            }
        }
    }
                                                        cout<<"\n";
                                                        for (int i=0; i<W; h(i++));  // show header
                                                        cout<<"\n\n";



    for ( int r=0;r<n;r++){       // Show table

        //oneRow
        cout << " " << ""+h(r+3) << " ";
        for ( int i=0 ; i<n ; i++ ) {
          cout << setw(w) << A[r][i] << " ";
        }
        cout << " " << ""+h(w+r+3) << "" << endl;
    }


                                                        // Extra row
                                                        cout << " " << ""+h(n+3); for ( int i=3;i<W;cout<<" ",i++); cout << ""+h(w+n+3) << "\n";
                                                        cout << " " << ""+h(n+4);


    for ( int i=0 ; i<n ; i++ ) {
          cout << setw(w) << ((i==0)? parity[i] : parity[i]-parity[i-1]) << " ";
        }

    cout << "  " << ""+h(w+n+4) << "" << endl;

                                                        cout<<"\n";
                                                        for (int i=0; i<W; h(i++));  // show header
                                                        cout<<"\n\n";

    int eldest = A[0][0];
    for ( int i=1 ; i<n ; i++ ) {
          if ( A[i][i]>eldest) {
              eldest=A[i][i]; row=i;
          }
    }
    cout<< "\n\n "<< "Najwieksza liczba w wierszu o indeksie: " << row;
    cout<< "\n\n "<< "Najwieksza: A["<<row<<"]["<<row<<"] : " << A[row][row];



    int youngest = A[row][0];
    for ( int i=1 ; i<n ; i++ ) {
          if (A[row][i]<youngest) {
            youngest=A[row][i];
            yoCol = i;
          }
    }


    delta = eldest-youngest;
    cout << ", najmniejsza w wierszu: " << A[row][yoCol] ;

    //cout <<"\n\n Zmiana: \n\n ";
        // XCHG
        A[row][row]-=delta;
        A[row][yoCol]+=delta;

    cout <<"\n\n Wiersz po zmianie: \n\n ";

        // show row
        for ( int i=0 ; i<n ; i++ ) {
              cout << setw(w) << A[row][i] << " ";
            }

        cout<<"\n\n";

        if ( row == yoCol)  cout <<"\n *** Zmiana miala charakter wirtualny *** \n";

    return 0;
}
