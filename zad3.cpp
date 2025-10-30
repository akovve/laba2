#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "zad3.h"

void zadanie3() {
    std::vector<int> V;
    
    std::cout << "Введите нечетное количество целых чисел N (≥5) для вектора:" << std::endl;
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end;
    
    std::copy(input_iter, end, std::back_inserter(V));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    if (V.size() < 5 || V.size() % 2 == 0) {
        std::cout << "Ошибка: N должно быть нечетным числом ≥5!" << std::endl;
        return;
    }
    
    int middle = V.size() / 2;
    V.erase(V.begin() + middle - 1, V.begin() + middle + 2);
    
    std::cout << "Результат после удаления трех средних элементов: ";
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(V.begin(), V.end(), output_iter);
    std::cout << std::endl;
}