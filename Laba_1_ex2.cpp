#include <iostream>

/*
1) � C++ ��� ��������� ������������ ������ ������������ �������� new ������ ������� malloc. 
������� ������������� �������� ����� ��������� ���: int *ptr = new int;
2) ����������, � C++ �������� new ������������ ��� ��������� ��������. 
����� ��� ����� ����������: int *ptrarr = new int[n];
3) � C++ ��� ������������ ������������ ������ ������������ �������� delete. 
������� ��������������� �������� �����: delete ptr;
4) ��� ������������ ���������� ������������ ������ ������� � C++ ������������ �������� delete[]. 
����� �������, ������������� �������� ����� ��������� ���: delete[] ptrarr.

� C++ ����� ���������� ����������� ������������ ������, ����� ��������� ������ ������.

���������� ���� � �� �� ���������� ������ ������ ������, ��� ��� ��� �������� 
� ��������������� ��������� ��������� - ����� �������� �������� ������.

���������� ������������ ������ ���� ������, ��� ��� ��� ����� �������� 
� ��������������� ��������� ��������� ��� ������ ����������.
*/

void generateFibonacciTriangle(int** triangle, int rows) {
    for (int i = 0; i < rows; i++) {
        triangle[i] = new int[i + 1];

        if (i < 2) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] = 1;
            }
        }
        else {
            triangle[i][0] = 1;
            triangle[i][i] = 1;

            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }
}

void printFibonacciTriangle(int** triangle, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteFibonacciTriangle(int** triangle, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}

int main() {
    int rows;

    std::cout << "Enter the number of lines of the Fibonacci triangle: ";
    std::cin >> rows;

    int** triangle = new int* [rows];
    generateFibonacciTriangle(triangle, rows);
    printFibonacciTriangle(triangle, rows);
    deleteFibonacciTriangle(triangle, rows);

    return 0;
}