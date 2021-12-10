#include <iostream>

using namespace std;

int getBigger( int first, int second ){
    if ( first > second ) return first;
    return second;
}



int main(){
    int first, second, bigger;
    cout << "Podaj dwie liczby: " << endl;
    cin >> first >> second ;

    cout << "First: " << first << endl;
    cout << "Second: " << second << endl;

    bigger = getBigger( first, second );

    cout << "Wiêksza liczba: " <<  bigger << endl;

    system("pause");
    return 0;
}





