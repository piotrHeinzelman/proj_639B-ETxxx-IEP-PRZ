#include <iostream>
#include <time.h>

using namespace std;

/*
Programowanie zima 2021/2022
Zadanie 8 – z funkcjami cz. 2 (0. 5 pkt)
Wylosowaæ dane rekordowe zawodników o polach (nrStartowy: int, wiek: int, wzrost: double)
do tablic K[n] (kobiety) i M[n] (mê¿czyŸni) (n - sta³a), a nastêpnie wydrukowaæ:

1. dane wszystkich kobiet i dane wszystkich mê¿czyzn.
2. numery startowe kobiet w wieku poni¿ej 20 lat i wzroœcie powy¿ej 185
   oraz numery startowe mê¿czyzn w wieku poni¿ej 25 lat i wzroœcie powy¿ej 195.
3. ró¿nicê miêdzy wiekiem najm³odszych kobiet i wiekiem najm³odszych mê¿czyzn.
4. ró¿nicê miêdzy œrednim wzrostem najm³odszych kobiet i œrednim wzrostem najm³odszych mê¿czyzn.

W programie nale¿y zdefiniowaæ strukturê rekordów oraz napisaæ i wykorzystaæ jedn¹
funkcjê (bez definiowania ¿adnych innych funkcji), która kolejno wykonuje nastêpuj¹ce
czynnoœci:

• losuje dane zawodników do jakiejœ tablicy podanego typu w granicach okreœlonych
  zdefiniowanymi sta³ymi

• drukuje dane wszystkich zawodników w tej tablicy

• drukuje numery startowe zawodników w wieku poni¿ej jakiejœ wartoœci i wzroœcie
  powy¿ej jakiejœ innej wartoœci w tej tablicy
• przekazuje przez parametr wiek najm³odszych zawodników w tej tablicy i zwraca
(przez return) ich œredni wzrost (mo¿e byæ kilka najm³odszych osób w tej tablicy).
UWAGA : s³owo jakiœ oznacza parametr funkcji.

*/

struct Person{
    int nrStartowy;
    int wiek;
    double wzrost;
};

const int n=5;

const double MIN_HEIGHT=160;
const int DELTA_HEIGHT=400;
const int MIN_AGE=17;
const int DELTA_AGE=20;

int startNumber=123;
Person M[n];
Person K[n];
int young=0;

double myFunction( Person A[n], int &startNumber, int maxAge, double minHeight, int &young ){


    //fill Ary
    for (int i=0;i<n;i++){
        A[i]=Person();
        startNumber+=rand()%9;
        A[i].nrStartowy=startNumber;
        A[i].wzrost= MIN_HEIGHT+(rand()%DELTA_HEIGHT)*.1;
        A[i].wiek=MIN_AGE+rand()%DELTA_AGE;


        printf( "\nZawodnik: nr.:%i, wiek: %i, wzrost: %.1f",A[i].nrStartowy, A[i].wiek, A[i].wzrost );
    }

     int tmp=990;
     for (int i=0;i<n;i++){
        Person p=A[i];
        if ( (p.wiek<maxAge) && (p.wzrost>minHeight) ) {
            printf( "\nNumer: %i",p.nrStartowy );
        }
        if (p.wiek<tmp) tmp=p.wiek;
     }
     young=tmp;

     double sum=0.0;
     int number=0;

     for (int i=0;i<n;i++){
        if (A[i].wiek!=young) continue;
            number++;
            sum+=A[i].wzrost;
     }
     return sum/number;
}


int main()
{
    srand(time(0));

    printf("\nKobiety:");
    myFunction( K, startNumber, 25, 180.0 , young);
    printf("\nnajmlodsza: %o" , young);


    printf("\n\n\nMezczyzni:");
    // nie powiedziano w zadaniu co zrobic ze zwracana wartoscia sredniego wzrostu.
    // dlatego w jednym przypadku drukuje te wartosc z opisem
    printf( "\n\nSredni wzrost najmlodszych: %f", myFunction( M, startNumber, 28, 182.0 ,young ));
    printf("\nnajmlodszy: %i" , young);


    return 0;
}
