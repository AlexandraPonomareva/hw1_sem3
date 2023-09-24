#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
1) � C++ strlen - � � size()
���������� ������ ������
2) � �++ strcpy() - � � assing()
�������� ������� �� ����� ������ � ������
3) � �++ strcmp() - � � compare()
���������� ��� ������
4) � �++ strcat() - � � append()
��������� ������� ����� ������ � ����� ������
5) � �++ someString[index]() = � C at(index)
������� � ������� ��������� ������ ������
6) � �++ push_back() ����, � � ���
����� �������� ������ � ����� �������
7) � �++ pop_back() ����, � � ���
����� �������� ������ � ������ �������
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
