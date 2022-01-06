#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <random>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/*

Zadanie 4�z tablic� dwuwymiarow� (0.75 pkt)
a. Tablic� A[n][n] (n-sta�a) wype�ni� liczbami losowymi
   ca�kowitymi z przedzia�u <D,G> (D, G-sta�e).

b. Wydrukowa� tablic� wierszami z ustawion� za pomoc� sta�ej W szeroko�ci� wydruku.

c. W dodatkowym wierszu pod tak wydrukowan� tablic� wydrukowa�:
   - pod kolumn� o indeksie 0 �ilo�� liczb parzystych w tej kolumnie
   - pod ka�d� nast�pn� kolumn� � r�nic� pomi�dzy ilo�ci� liczb parzystych w tej kolumnie
     a ilo�ci� liczb parzystych w kolumnie poprzedniej.

d. Znale�� najwi�kszy element g��wnej przek�tnej w tablicy A
   i zapami�ta� oraz wydrukowa� indeks wiersza, w kt�rym si� on znajduje.

e. Zamieni� miejscami znaleziony najwi�kszy element z najmniejszym elementem wiersza,
   w kt�rym go znaleziono.

f. Wydrukowa� zawarto�� tego wiersza po dokonanej zamianie.

   Wskaz�wka:
   1. Za najwi�kszy/najmniejszy element przyj�� pierwszy znaleziony
   (bo mo�e by� kilka najwi�kszych/najmniejszych w danym obszarze).
    *//*

   2. Nie nale�y u�ywa� funkcji swap()do wykonania zamiany.

*/
const int n=5;       // array size // width (table in column)
const int W=60;      // width (table)
const int w=((W-2)/n)-1; // width (one column)
const int D=-3;       // Down Limit
const int G=10;      // Greatest :)
const int GmD = G-D+1;
char h(int i){cout<<(char)((i&1*(i%4)-((i&2)>>1)));}
int parity[n]{0};
int row=0;
int delta=0;
int colNum=0;


int main()
{
    srand( time(NULL) );
    int A[n][n];


    for (int r=0;r<n;r++){  // Fill table
        for (int i=0;i<n;i++){
            if (( A[r][i]=D+rand()%GmD )&1 ) {} else parity[i]++;
        }
    }

                                                        cout<<"\n";
                                                        for (int i=0; i<W; h(i++));  // show header
                                                        cout<<"\n\n";

    for ( int r=0;r<n;r++){       // Show table

        //oneRow
        cout << " " << ""+h(r+3) << " ";
        for ( int i=0 ; i<n ; i++ ) {
          cout << setw(w) << setprecision(w) << A[r][i] << " ";
        }
        cout << " " << ""+h(w+r+3) << "" << endl;
    }


                                                        // Extra row
                                                        cout << " " << ""+h(n+3); for ( int i=3;i<W;cout<<" ",i++); cout << ""+h(w+n+3) << "\n";
                                                        cout << " " << ""+h(n+4);


    for ( int i=0 ; i<n ; i++ ) {
          cout << setw(w) << setprecision(w) << ((i==0)? parity[i] : parity[i]-parity[i-1]) << " ";
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


    int youngest = A[row][0];
    for ( int i=1 ; i<n ; i++ ) {
          if ( i == row ) continue;
          if (A[row][i]<youngest) {
            youngest=A[row][i];
            colNum = i;
          }
    }

    delta = eldest-youngest;

    cout<< "\n\n "<< "Najwieksza: A["<<row<<"]["<<row<<"] : " << A[row][row] << ", najmniejsza poza nia: " << A[row][colNum] <<"\n\n Wiersz po zmianie: \n\n ";

    // XCHG
    A[row][row]-=delta;
    A[row][colNum]+=delta;

    // show row
    for ( int i=0 ; i<n ; i++ ) {
          cout << setw(w) << setprecision(w) << A[row][i] << " ";
        }

    cout<<"\n\n";

    return 1;
}
