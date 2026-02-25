#include <iostream>
#include <string>
using namespace std;

// Проверка: только цифры 0,1,2 для троичного числа
bool eto_troichnoe(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0' && s[i] != '1' && s[i] != '2') {
            return false;
        }
    }
    return true;
}

// Проверка: только цифры для десятичного числа
bool eto_desyatichnoe(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

// Перевод из троичной в десятичную
int troich_v_desyat(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 3 + (s[i] - '0');
    }
    return res;
}

// Перевод из десятичной в троичную
string desyat_v_troich(int n) {
    if (n == 0) return "0";
    
    string res = "";
    while (n > 0) {
        res = to_string(n % 3) + res;
        n = n / 3;
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "Программа перевода чисел\n";
    cout << "1 - троичная -> десятичная\n";
    cout << "2 - десятичная -> троичная\n";
    cout << "Ваш выбор: ";
    
    int vibor;
    cin >> vibor;
    
    if (vibor == 1) {
        string chislo;
        cout << "Введите троичное число: ";
        cin >> chislo;
        
        if (!eto_troichnoe(chislo)) {
            cout << "Ошибка! В троичном числе могут быть только цифры 0, 1, 2.\n";
        }
        else {
            cout << chislo << " (3) = " << troich_v_desyat(chislo) << " (10)\n";
        }
    }
    else if (vibor == 2) {
        string chislo;
        cout << "Введите десятичное число: ";
        cin >> chislo;
        
        if (!eto_desyatichnoe(chislo)) {
            cout << "Ошибка! В десятичном числе могут быть только цифры.\n";
        }
        else {
            // Преобразуем строку в число
            int n = 0;
            for (int i = 0; i < chislo.length(); i++) {
                n = n * 10 + (chislo[i] - '0');
            }
            cout << chislo << " (10) = " << desyat_v_troich(n) << " (3)\n";
        }
    }
    else {
        cout << "Ошибка! Нужно выбрать 1 или 2.\n";
    }
    
    return 0;
}