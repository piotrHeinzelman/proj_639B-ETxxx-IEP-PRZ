#include <iostream>

using namespace std;


/*

Wczytaæ dwie liczby ca³kowite i wydrukowaæ wiêksz¹ z nich.
Uwzglêdniæ przypadek, gdy dwie liczby s¹ sobie równe i odpowiednio sygnalizowaæ
to komentarzem.

only if

*/

/*

https://www.p-programowanie.pl/cpp/polaczenie-assemblera-i-cpp

void funkcja1() {
    __asm("mov eax, 5");
    __asm("push eax");
    __asm("add esp, 4");
}

void funkcja2() {
    asm("\
        mov eax, 5 \n\
        push eax \n\
        add esp, 4 \n\
    ");
}

*/


int main(){

    int first, second;

    cout << "Podaj dwie liczby: " << (char)0x0a <<  (char)0x0d;
    cout << "Liczba pierwsza: ";

    cin >> first;

    cout << "Liczba druga: ";

    cin >> second;

    if ( first == second ) { cout << "Liczby s¹ jednakowe"<< (char)0x0a << (char)0x0d; return 1; }
    if ( first > second )  { cout << "Liczba pierwsza jest wiêksza. (" << first << ")" << (char)0x0a << (char)0x0d; return 0;}
    cout << "Liczba druga jest wiêksza. (" << second << ")" << (char)0x0a << (char)0x0d;


    system("pause");
    return 0;

}


