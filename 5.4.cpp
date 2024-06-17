//Даны два вектора (одномерных массива), содержащих n вещественных элементов. Если векторы различны, то получить вектор, являющийся суммой двух 
//векторов, иначе переписать в него элементы исходного вектора.


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Функция для сравнения двух векторов
bool areVectorsEqual(const vector<double>& v1, const vector<double>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for (size_t i = 0; i < v1.size(); ++i) {
        if (abs(v1[i] - v2[i]) > 1e-9) { // Учитываем погрешность для вещественных чисел
            return false;
        }
    }

    return true;
}

// Функция для сложения двух векторов
vector<double> sumVectors(const vector<double>& v1, const vector<double>& v2) {
    vector<double> result(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

int main() {
    // Пример входных данных
    vector<double> vector1 = { 1.0, 2.0, 3.0 };
    vector<double> vector2 = { 1.0, 3.0, 5.0 };

    vector<double> result;

    if (areVectorsEqual(vector1, vector2)) {
        result = vector1; 
    }
    else {
        result = sumVectors(vector1, vector2); 
    }

    // Вывод результата
    cout << "Result vector: ";
    for (double value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}