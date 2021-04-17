#include <iostream>  
using namespace std;
int** CreateArray(int pRow, int pColumn);
void FillArray(int** pArray, int pRow, int pColumn);
void ProductPositive(int** pArray, int pRow, int pColumn);

int main()
{
    int row, column;
    cout << "Enter size of array.\n\n";
    cout << "rows: "; cin >> row;
    cout << "columns: "; cin >> column;
    cout << endl;
    int** dynamicArray = CreateArray(row, column);
    FillArray(dynamicArray, row, column);
    ProductPositive(dynamicArray, row, column);

    for (int i = 0; i < row; i++)
    {
        delete[] dynamicArray[i];
    }

    delete[] dynamicArray;
    return 0;
}

int** CreateArray(int pRow, int pColumn)
{
    int** dynamicArray = new int* [pRow];
    for (int i = 0; i < pRow; i++) {
        dynamicArray[i] = new int[pColumn];
    }
    return dynamicArray;
}

void FillArray(int** pArray, int pRow, int pColumn)
{
    for (int i = 0; i < pRow; i++)
    {
        for (int j = 0; j < pColumn; j++)
        {
            cout << "dynamicArray[" << i << "][" << j << "]: "; cin >> pArray[i][j];
        }
    }
}

void ProductPositive(int** pArray, int pRow, int pColumn)
{
    int result = 1;
    for (int i = 0; i < pRow; i++)
    {
        for (int j = 0; j < pColumn; j++)
        {
            if (pArray[i][j] > 0)
            {
                result *= pArray[i][j];
            }
        }
    }
    cout << endl;
    cout << "Product of positive elements is " << result << endl;
}