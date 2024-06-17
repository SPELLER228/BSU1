#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void printFileContent(char* filename);
void createSourceFile(char* filename);
void createNewFile(char* sourceFilename, char* newFilename);

int main() {
    setlocale(LC_ALL, "RU");
    char sourceFilename[] = "source.bin"; // Исходный файл
    char newFilename[] = "new.bin"; // Новый файл
    createSourceFile(sourceFilename);
    createNewFile(sourceFilename, newFilename);
    cout << "Содержимое исходного файла: " << endl;
    printFileContent(sourceFilename);
    cout << "Содержимое нового файла: " << endl;
    printFileContent(newFilename);
    return 0;
}

void printFileContent(char* filename) {
    ifstream infile(filename, ios::binary);
    if (!infile) {
        cout << "Ошибка при открытии файла." << endl;
        return;
    }
    int number;
    while (infile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        cout << number << " ";
    }
    cout << endl;
    infile.close();
}

void createSourceFile(char* filename) {
    ofstream outfile(filename, ios::binary);
    if (!outfile) {
        cout << "Ошибка при создании исходного файла." << endl;
        return;
    }

    for (int i = 1; i <= 10; ++i) {
        outfile.write(reinterpret_cast<char*>(&i), sizeof(int));
    }

    for (int i = -1; i >= -10; --i) {
        outfile.write(reinterpret_cast<char*>(&i), sizeof(int));
    }
    for (int i = 11; i <= 20; ++i) {
        outfile.write(reinterpret_cast<char*>(&i), sizeof(int));
    }

    for (int i = -11; i >= -20; --i)
        outfile.write(reinterpret_cast<char*>(&i), sizeof(int));

    outfile.close();
    cout << "Исходный файл успешно создан." << endl;
}
void createNewFile(char* sourceFilename, char* newFilename) {
    ifstream infile(sourceFilename, ios::binary);
    if (!infile) {
        cout << "Ошибка при открытии исходного файла." << endl;
        return;
    }

    ofstream outfile(newFilename, ios::binary);
    if (!outfile) {
        cout << "Ошибка при создании нового файла." << endl;
        return;
    }
    queue<int> positiveQueue, negativeQueue;
    int number;
    int count = 0;
    bool isPositive = true;

    while (infile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        if (number > 0) {
            positiveQueue.push(number);
        }
        else if (number < 0) {
            negativeQueue.push(number);
        }

        if (count == 5) {
            isPositive = !isPositive;
            count = 0;
        }

        if (isPositive && !positiveQueue.empty()) {
            outfile.write(reinterpret_cast<char*>(&positiveQueue.front()), sizeof(int));
            positiveQueue.pop();
            count++;
        }
        else if (!isPositive && !negativeQueue.empty()) {
            outfile.write(reinterpret_cast<char*>(&negativeQueue.front()), sizeof(int));
            negativeQueue.pop();
            count++;
        }
    }

    // Обработка оставшихся чисел в очередях
    while (!positiveQueue.empty()) {
        outfile.write(reinterpret_cast<char*>(&positiveQueue.front()), sizeof(int));
        positiveQueue.pop();
    }

    while (!negativeQueue.empty()) {
        outfile.write(reinterpret_cast<char*>(&negativeQueue.front()), sizeof(int));
        negativeQueue.pop();
    }

    infile.close();
    outfile.close();
    cout << "Новый файл успешно создан." << endl;
}


