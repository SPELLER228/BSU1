#define _CRT_SECURE_NO_WARNINGS 

#include "Word.h" 
#include <iomanip> 
#include <iostream> 
#include <cstring> 

using namespace std; 


int main() {
    setlocale(LC_ALL, "RU");
    Word myWord1, myWord2;
    cout << "Введите первое слово:" << endl;
    myWord1.fillWord();
    cout << "Введите второе слово:" << endl;
    myWord2.fillWord();

    Word myWord3(myWord1, myWord2);

    cout << "Самое большое значения слова: ";
    myWord3.outputWord();

    
    Word myWord4("Привет");
    cout << "Слово, созданное с помощью C-строки: ";
    myWord4.outputWord();

    Word myWord5('*', 5);
    cout << "Слово, созданное с помощью символа и количества повторений: ";
    myWord5.outputWord();

    Word myWord6("Привет", 3, 1);
    cout << "Слово, созданное с помощью C-строки, длины и выбора: ";
    myWord6.outputWord();

    Word myWord7(myWord1, myWord2);
    cout << "Слово, созданное с помощью двух объектов Word: ";
    myWord7.outputWord();

    Word myWord9("Привет!!!"); 
    cout << "Исходное слово: "; myWord9.outputWord();
    Word copiedWord(myWord9);
    cout << "Скопированное слово: "; copiedWord.outputWord();

    Word myWord8(move(myWord1));
    
    myWord8.outputWord();
    cout << "myWord1 после перемещения: ";
    
  
    return 0;
}

