#include <iostream>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/*
Programowanie zima 2021/22
Zadanie 6 - z rekordami (0. 5 pkt)

1. Do tablicy towarów A[n][n] (n - sta³a) wylosowaæ rekordy o polach
 (nazwa towaru - typu char, cena - typu int) w taki sposób, aby:
• nazwy towarów by³y du¿ymi literami na obwodzie i na obu przek¹tnych tablicy, zaœ
ma³ymi literami w pozosta³ym obszarze tablicy.
• ceny by³y jedno- lub dwucyfrowe.
2. Tablicê wydrukowaæ wierszami w postaci kolejnych rekordów, np. A10 c7 w93...
3. Zamieniæ miejscami najtañszy towar le¿¹cy na drugiej przek¹tnej tablicy z najdro¿szym
towarem le¿¹cym w trzech ostatnich wierszach tej tablicy.
4. Ponownie wydrukowaæ wierszami tablicê.
Wskazówka: Najpierw nale¿y zdefiniowaæ strukturê rekordów.
Przypomnienie: losowanie liczb i znaków jest omówione na koñcu lekcji 3.3.
*/


struct Item {
    char nazwa;
    int cena;
};

int main()
{
    srand(time(NULL));
    const int n=8;
    Item A[n][n];
    int const interv=97-65;


    for ( int i=0;i<n;i++){
        for ( int j=0;j<n;j++){
            A[i][j].cena=1+rand()%(98); //cout<<"\n"<<A[i][j].cena;
            A[i][j].nazwa=65+rand()%(90-65+1);
            if (i*j==0 || i==n-1 || j==n-1)continue;
            if (i==j || i+1==n-j ) continue;
            //if (i==nj)continue;
            A[i][j].nazwa+=interv;
        }
    }

    cout << "\n\n";

    for (int i=0;i<n;i++){
        for ( int j=0;j<n;j++){
            //printf("%c%2i " , A[i][j].nazwa, A[i][j].cena );
            cout<<A[i][j].nazwa<<setw(2)<<fixed<<A[i][j].cena<<"  ";
        }
        cout << "\n";
    }

    int light=A[0][n-1].cena;
    int lightI=0;

    int heavyX=0;
    int heavyY=n-3;
    int heavy=A[heavyY][heavyX].cena;

    for ( int i=0; i<n; i++)if(A[i][n-1-i].cena<light){ light=A[i][n-i-1].cena;lightI=i;};
    cout << "\nLight:[" <<lightI << "]:" <<light;

    for ( int Y=n-3;Y<n;Y++){
        for (int X=0;X<n;X++) {
            if (A[Y][X].cena>heavy){ heavyX=X;heavyY=Y;heavy=A[Y][X].cena; }
        }
    }
    cout << "\nHeavy:[" <<heavyX << ","<<heavyY << "]:" <<heavy;


    cout << "\nXCHG\n";
    Item tmp = A[lightI][n-lightI-1];
    A[lightI][n-lightI-1]=A[heavyY][heavyX];
    A[heavyY][heavyX]=tmp;
    //

    cout << "\n\n";

    for (int i=0;i<n;i++){
        for ( int j=0;j<n;j++){
            //printf("%c%2i " , A[i][j].nazwa, A[i][j].cena );
            cout<<A[i][j].nazwa<<setw(2)<<fixed<<A[i][j].cena<<"  ";
        }
        cout << "\n";
    }
    return 0;
}
