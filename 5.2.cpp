#include <iostream>
#include <string>
#include <bitset>
using namespace std;

// Функция для проверки, является ли строка палиндромом
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

string decToBin(unsigned long long num) {
    if (num == 0) return "0";
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    return binary;
}

int main() {
    setlocale(LC_ALL, "RU");
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;

    cout << "Числа, двоичная запись которых симметрична:" << endl;

    for (int i = 1; i <= N; ++i) {
        string binary = decToBin(i);
        if (isPalindrome(binary)) {
            cout << "Десятичное: " << i << ", Двоичное: " << binary << endl;
        }
    }

    return 0;
}
