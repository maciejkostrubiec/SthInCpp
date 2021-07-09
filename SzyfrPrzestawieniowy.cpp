#include <iostream>
#include <fstream>

using namespace std;

//Szyfruj przestawieniowo - tablica charów
string sz_p_tab(string t, int k) {
    int numerator = 0;
    char tab[k][t.length()/k+1];
    for (int i = 0; i < t.length()/k+1; i++) {
        for (int j = 0; j < k; j++) {
            if (numerator < t.length())
                tab[j][i] = t[numerator++];
            else
                tab[j][i] = 'X';
        }
    }
    string output = "";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < t.length()/k+1; j++) {
            output += tab[i][j];
        }
    }
    return output;
}
//Odszyfruj przestawieniowo - tablica charów
string odsz_p_tab(string t, int k) {
    int numerator = 0;
    char tab[k][t.length()/k];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < t.length()/k; j++) {
            tab[i][j] = t[numerator++];
        }
    }
    string output = "";
    for (int i = 0; i < t.length()/k; i++) {
        for (int j = 0; j < k; j++) {
            output += tab[j][i];
        }
    }
    return output;
}

//Szyfruj przestawieniowo - pêtla w pêtli
string sz_p_pwp(string t, int k) {
    string output = "";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < t.length()/k+1; j++) {
            if(j*k + i < t.length())
                output += t[j*k + i];
            else
                output += "X";
        }
    }
    return output;
}

//Odszyfruj przestawieniowo - pêtla w pêtli
string odsz_p_pwp(string t, int k) {
    string output = "";
    for (int i = 0; i < t.length()/k; i++) {
        for (int j = 0; j < k; j++) {
            output += t[j*(t.length()/k) + i];
        }
    }
    return output;
}

//Szyfruj przestawieniowo - modulo
string sz_p_mod(string t, int k) {
    string output = "";
    for (int i = 0; i < (t.length()/k+1)*k; i++) {
        if (i/(t.length()/k+1) + (i%(t.length()/k+1))*k < t.length())
            output += t[i/(t.length()/k+1) + (i%(t.length()/k+1))*k];
        else
            output += "X";
    }
    return output;
}

//Odszyfruj przestawieniowo - modulo
string odsz_p_mod(string t, int k) {
    string output = "";
    for (int i = 0; i < t.length(); i++) {
        output += t[i/k + (i%k) * (t.length()/k)];
    }
    return output;
}



int main() {
    cout << sz_p_tab("ala ma kota i psa", 7) << endl;
    cout << sz_p_pwp("ala ma kota i psa", 7) << endl;
    cout << sz_p_mod("ala ma kota i psa", 7) << endl;
    cout << odsz_p_tab(sz_p_tab("ala ma kota i psa", 7), 7) << endl;
    cout << odsz_p_pwp(sz_p_pwp("ala ma kota i psa", 7), 7) << endl;
    cout << odsz_p_mod(sz_p_mod("ala ma kota i psa", 7), 7) << endl;
    return 0;
}
