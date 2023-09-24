#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
1) в C++ strlen - в С size()
пкоазывает длинну строки
2) в С++ strcpy() - в С assing()
копирует символы из одной строки в другую
3) в С++ strcmp() - в С compare()
сравнивает две строки
4) в С++ strcat() - в С append()
добавляет символы одной строки в конец другой
5) в С++ someString[index]() = в C at(index)
выводит в консоль выбранный символ строки
6) в С++ push_back() есть, в С нет
можем добавить ячейку в конец вектора
7) в С++ pop_back() есть, в С нет
можем добавить ячейку в начало вектора
*/
int main() {
    std::string str;
    char temp;
    std::cout << "Enter the string to be sorted:";
	std::getline(std::cin, str);
    int len = str.length();

    for (int i = 0; i < len; i++) {

        for (int j = 0; j < len - 1; j++) {
            if (str[j] > str[j + 1]) {
            temp = str[j];
            str[j] = str[j + 1];
            str[j + 1] = temp;
            }
        }
    }

    str.erase(std::remove_if(str.begin(), str.end(), [](char c){
        return std::isspace(c) || std::ispunct(c) || std::isdigit(c);
    }), str.end());
    cout << "\n String after sorting: " << str << " \n";
    return 0;
}
