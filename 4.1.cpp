#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>


using namespace std;


class MyString {
private:
    char* str;
    size_t length;

public:
    // Конструктор без параметров
    MyString() : str(nullptr), length(0) {}

    // Конструктор инициализации словом
    MyString(const char* initializer) {
        length = strlen(initializer);
        str = new char[length + 1];
        strcpy(str, initializer);
    }

    // Конструктор инициализации количеством повторов символа
    MyString(char ch, size_t count) {
        length = count;
        str = new char[length + 1];
        fill_n(str, count, ch);
        str[length] = '\0';
    }

    // Конструктор инициализации частью слова (первые n символов)
    MyString(const char* initializer, size_t n, bool from_start = true) {
        length = min(n, strlen(initializer));
        str = new char[length + 1];
        if (from_start) {
            strncpy(str, initializer, length);
        }
        else {
            strncpy(str, initializer + strlen(initializer) - length, length);
        }
        str[length] = '\0';
    }

    // Конструктор копирования
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Конструктор перемещения
    MyString(MyString&& other) noexcept : str(other.str), length(other.length) {
        other.str = nullptr;
        other.length = 0;
    }

    // Деструктор
    ~MyString() {
        delete[] str;
    }

    // Метод для заполнения полей класса с клавиатуры
    void input() {
        delete[] str;
        char buffer[100];
        cout << "Enter a string: ";
        cin.getline(buffer, 100);
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy(str, buffer);
    }

    // Метод для вывода на экран
    void display() const {
        if (str) {
            cout << str << endl;
        }
        else {
            cout << "(empty string)" << endl;
        }
    }

    // Метод сравнения двух слов
    static MyString getLarger(const MyString& a, const MyString& b) {
        if (strcmp(a.str, b.str) > 0) {
            return a;
        }
        else {
            return b;
        }
    }

    // Перегрузка оператора присваивания копированием
    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        delete[] str;  
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        return *this;
    }

    // Перегрузка оператора присваивания перемещением
    MyString& operator=(MyString&& other) noexcept {
        if (this == &other) return *this;
        delete[] str;
        str = other.str;
        length = other.length;
        other.str = nullptr;
        other.length = 0;
        return *this;
    }
};

int main() {
    int a;
    cin >> a;
    switch (a)
    {
    case(1):
        {
            // Конструктор без параметров
            MyString s1;
            s1.display();
            break;
        }
        case(2):
        {
// Конструктор инициализации словом
    MyString s2("Hello");
    s2.display();
    break;
        }
        case(3):
        {// Конструктор инициализации количеством повторов символа
            MyString s3('A', 5);
            s3.display();
            break;
        }
        case(4):
        {
 // Конструктор инициализации частью слова (первые n символов)
    MyString s4("qwertyuiop", 5);
    s4.display();
    break;
        }
        case(5):
        {
// Конструктор инициализации частью слова (последние n символов)
    MyString s5("qwertyuiop", 6, false);
    s5.display();
            break;
        }
        case(6):
        {
// Конструктор копирования
            MyString s = "qweryuiop";
    MyString s6(s);
    s6.display();
            break;
        }
        case(7):
        {
  // Конструктор перемещения
            MyString s = "qwertyuiop";
    MyString s7(move(s));
    s7.display();
    s.display();
            break;
        }
        case(8):
        {
// Заполнение полей класса с клавиатуры и вывод на экран
            MyString s8;
    s8.input();
    s8.display();
            break;
        }
        case(9):
        {
// Сравнение двух слов и вывод наибольшего
            MyString s1, s2;
            s1.input();
            s2.input();
    MyString larger = MyString::getLarger(s1, s2);
    larger.display();
            break;
        }
        break;
    }
    

    return 0;
}
