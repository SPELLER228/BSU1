//удалить все символы, непосредственно за которыми идет '*'. Вывести в алфавитном порядке все согласные латинские буквы, не входящие в строку.

#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    string s1;
    cout << "Введите строку: ";
    cin >> s1;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '*') {
            s1.erase(i, s1.size() - i);
            i--;
        }
    }
    cout << s1 << endl;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] = s1[i] - 'A' + 'a';
        }
    }
    string consonants = "bcdfghjklmnpqrstvwxyz";
    cout << "Согласные буквы, не входящие в строку: ";
    for (int i = 0; i < consonants.size(); i++) {
        bool found = false;
        for (int j = 0; j < s1.size(); j++) {
            if (consonants[i] == s1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << consonants[i] << " ";
        }
    }
    return 0;
}

