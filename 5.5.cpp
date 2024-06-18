//Определить, является ли заданная матрица ортонормированной, т.е.такой, в
//которой скалярное произведение каждой пары различных строк равно 0, а скалярное произведение каждой строки на себя равно 1.

#include <iostream>
#include <vector>

using namespace std;

double ScalarProduct(vector<double>& vec1,vector<double>& vec2);
bool isOrthonormal(vector<vector<double>>& matrix);

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите количество элементов матрицы: ";
    cin >> n;
    vector<vector<double>> matrix(n,vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    if (isOrthonormal(matrix))
        cout << "Матрица является ортонормированной." <<endl;
    else
       cout << "Матрица не является ортонормированной." <<endl;
    return 0;
}

double ScalarProduct(vector<double>& vec1, vector<double>& vec2) {
    double result = 0.0;
    for (auto it1 = vec1.begin(), it2 = vec2.begin(); it1 != vec1.end() && it2 != vec2.end(); ++it1, ++it2) {
        result += (*it1) * (*it2);
    }
    return result;
}


bool isOrthonormal(vector<vector<double>>& matrix) {
    size_t n = matrix.size();
    for (size_t i = 0; i < n; ++i) {
        if (abs(ScalarProduct(matrix[i], matrix[i]) - 1.0) > 1e-9)
            return false;
        
        for (size_t j = i + 1; j < n; ++j) {
            if (abs(ScalarProduct(matrix[i], matrix[j])) > 1e-9) 
                return false;
        }
    }
    return true;
}
