#include <iostream>

/*
1) В C++ для выделения динамической памяти используется оператор new вместо функции malloc. 
Поэтому эквивалентная операция будет выглядеть так: int *ptr = new int;
2) Аналогично, в C++ оператор new используется для выделения массивов. 
Такой код будет правильным: int *ptrarr = new int[n];
3) В C++ для освобождения динамической памяти используется оператор delete. 
Поэтому соответствующая операция будет: delete ptr;
4) Для освобождения выделенной динамической памяти массива в C++ используется оператор delete[]. 
Таким образом, эквивалентная операция будет выглядеть так: delete[] ptrarr.

В C++ также необходимо освобождать динамическую память, иначе возникает утечка памяти.

Освободить одну и ту же выделенную память дважды нельзя, так как это приводит 
к неопределенному поведению программы - такая операция вызывает ошибку.

Освободить невыделенную память тоже нельзя, так как это может привести 
к неопределенному поведению программы или ошибке выполнения.
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