#include <iostream>
#include <fstream>

using namespace std;

bool pierwsza(unsigned long long int a) {
    for (unsigned long long int i = 2; i*i <= a; i++)
        if (!(a%i))
            return false;
    return true;
}

int main() {
    fstream plik("out.txt", ios::out);
    unsigned long long int w, cnt = 0, n;
    cout << "n^2 - n + 41 = ..." << endl << endl;
    cout << "Podaj n: ";
    cin >> n;
    for (unsigned long long int i = 1; i <= n; i++) {
        w = i*(i-1)+41;
        if (pierwsza(w)) {
            cnt++;
            plik << i << "," << w << "," << cnt << endl;
        } else {
            plik << i << "," << w << "," << cnt << endl;
        }
        if (!(i%1000)) cout << i << endl;
    }
    cout << "Dla n od 1 do " << n << " mamy " << cnt << " liczb pierwszych." << endl;
    plik.close();

    cout << endl << "Wypisac (t/n)? ";
    char menu;
    cin >> menu;
    cout << endl;
    if (menu == 't') {
        int p,k;
        cout << "Wypisz od: ";
        cin >> p;
        cout << "do: ";
        cin >> k;
        for (int i = p; i < k; i++) {
            w = i*(i-1)+41;
            cout << "n = " << i << " -> " << w << " P? -> " << (pierwsza(w)?"Tak":"Nie") << endl;
        }
    }
    return 0;
}
