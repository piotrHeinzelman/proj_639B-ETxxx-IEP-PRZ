#include <iostream>

using namespace std;


/*

Napisaæ program, który:
1. Pyta u¿ytkownika o imiê,  wczytuje  je do  zmiennej  typu  string
   i drukuje powitanie z wykorzystaniem tego imienia.

2. Prosi o podanie dowolnych dwóch liczb ca³kowitych i wczytuje je do zmiennych typu int.

3. Sprawdza obie liczby i drukuje, ile wœród nich wczytano liczb jednocyfrowych
   (dodatnich i ujemnych -³¹cznie).

4. Jeœli obie wczytane liczby s¹ sobie równe, program sygnalizuje to odpowiednim komunikatem
   i koñczy dzia³anie, w przeciwnym razie:

5. Drukuje informacjê, czy mniejsza z wczytanych liczb jest dodatnia,
   czy ujemna, czy te¿ jest równa zeru.

6. Drukuje dok³adny wynik dzielenia wiêkszej liczby przez potrojon¹ wartoœæ mniejszej.

Wskazówki
1. Nie wolno dopuœciæ do dzielenia przez zero (nale¿y wydrukowaæ odpowiedni komunikat).
2. W programie mo¿na kilkakrotnie wykorzystaæ instrukcjê return.

Uwagi
1. Pisanie komentarzy w programach nie jest potrzebne (nie wp³ywa na ocenê),
   chyba ¿e pomaga to autorowi wuporz¹dkowaniu programu.

2. Przy  wczytywaniu i drukowaniu napisównie u¿ywamy polskich znaków diakrytycznych
   (tzw. ogonkowych), aby na wydrukach nie powsta³y „krzaczki”
   - natomiast dopuszczalne s¹ polskie znaki ogonkowe w komentarzach.

*/




int main(){

    string name, test;
    int first, second, singleDigit = 0 , smaller, bigger ;

// 1
    cout << endl << "Jak masz na imie ? " << endl;
    cin >> name;
    cout << "Dzien dobry " << name << endl << endl << "podaj dwie liczby calkowite," << endl << "pierwsza: ";

// 2
    cin >> first;
    cout << endl << "teraz druga: ";
    cin >> second;

// 3
    if ( first * first < 100 ) singleDigit++;
    if ( second * second < 100 ) singleDigit++;

    cout << endl <<  name << ", liczb jednocyfrowych wpisales " << singleDigit << endl;

// 4
    if ( first - second == 0 ) {
            cout << "Podales takie same liczby; " ;  return 1;
    }

    if ( first - second < 0 ) {
        test = "Pierwsza";
        smaller = first; bigger = second;
    } else {
        test = "Druga";
        smaller = second; bigger = first;
    }

    cout << test << " liczba jest mniejsza i jej wartosc to : " << smaller << endl << endl;

    if ( smaller==0 ) {
        cout << " liczba mniejsza wynosi zero, dzielenie przez zero jest niedopuszczalne. ";
        return 1;
    }

    if ( smaller > 0 ) test = "dodatnia"; else test = "ujemna";

    cout << "Mniejsza z liczb jest " << test << endl;

    smaller *=  3;

    cout << endl << endl << "obliczenie W/(3M): " <<  (double) bigger/smaller << endl << endl;
    system("pause");
    return 0;

}


