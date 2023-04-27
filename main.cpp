#include <iostream>

using namespace std;

char **writeMatrix(int rowCount, int columnCount) {
    char **m = new char *[rowCount];
    for (int i = 0; i < rowCount; ++i) {
        m[i] = new char[columnCount];
        for(int j = 0; j < columnCount; j++) {
            cin >> *(m[i] + j);
        }
    }
    return m;
}

char **changeMatrix(char** originalMatrix, char** finalMatrix, int originalRowCount, int columnCount) {
    for(int i = 0; i < originalRowCount; ++i) {
        finalMatrix[i*2] = originalMatrix[i];
        finalMatrix[i*2 + 1] = originalMatrix[i];
    }

    return finalMatrix;
}

int main() {
    setlocale(LC_ALL, "Russian");

    //Определим размеры матрицы
    int rowCount, columnCount;
    cout << "How much rows and columns do you want to write?" << endl;
    cin >> rowCount >> columnCount;

    //Введём матрицу
    cout << "Please write a rows one by one:" << endl;
    char **inputMatrix = writeMatrix(rowCount, columnCount);

    //Создадим итоговую матрицу
    char **finalMatrix = new char * [rowCount * 2];

    changeMatrix(inputMatrix, finalMatrix, rowCount, columnCount);

    cout << "Your answer:" << endl;

    for(int i = 0; i < rowCount * 2; ++i) {
        cout << i << ") " << finalMatrix[i] << endl;
    }

    return 0;
}
