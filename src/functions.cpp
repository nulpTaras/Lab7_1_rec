//
// Created by Taras Neridnyi on 11.11.2024.
//

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int i=0 , int j=0);
void Print (int** a, const int rowCount, const int colCount ,
    int i=0, int j=0);
void Sort  (int** a, const int rowCount, const int colCount,
    int i0=0, int i1=0);
void Change(int** a, const int row1, const int row2,
    const int colCount, int j=0);


void Create(int** a, const int rowCount, const int colCount,
const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High-Low+1);
    if (j<colCount-1)
        Create(a, rowCount, colCount, Low, High, i, j+1);
    else
        if (i<rowCount-1)
            Create(a, rowCount, colCount, Low, High, i+1, 0);
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j<colCount-1)
        Print(a, rowCount, colCount, i, j+1);
    else
        if (i<rowCount-1)
        {
            cout << endl;
            Print(a, rowCount, colCount, i+1, 0);
        }
        else
            cout << endl << endl;
}
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 >= rowCount - 1) // Базовий випадок
        return;

    if (i1 < rowCount - i0 - 1) { // Внутр цикл порівнянн
        if ((a[i1][0] > a[i1 + 1][0]) ||
            (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
            (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][3] < a[i1 + 1][3])) {
            Change(a, i1, i1 + 1, colCount);
            }
        Sort(a, rowCount, colCount, i0, i1 + 1); //внутр
    } else {
        Sort(a, rowCount, colCount, i0 + 1, 0); // далі (зовн цикл)
    }
}

void Change(int** a, const int row1, const int row2, const int colCount, int j) {
    if (j >= colCount) // Базовий випадок
        return;

    // Обмін елементів у рядках
    int tmp = a[row1][j];
    a[row1][j] = a[row2][j];
    a[row2][j] = tmp;

    Change(a, row1, row2, colCount, j + 1); // Рекурсія для переходу до наступного елемента
}



// void Change(int** a, const int row1, const int row2, const int colCount) {
//     for (int j = 0; j < colCount; j++) {
//         int tmp = a[row1][j];
//         a[row1][j] = a[row2][j];
//         a[row2][j] = tmp;
//     }
// }



// void Sort(int** a, const int rowCount, const int colCount) {
//     for (int i0 = 0; i0 < rowCount - 1; i0++) {
//         for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
//             if ((a[i1][0] < a[i1 + 1][0]) ||
//                 (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
//                 (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][3] > a[i1 + 1][3])) {
//                 Change(a, i1, i1 + 1, colCount);
//                 }
//         }
//     }
// }



