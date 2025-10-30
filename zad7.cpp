#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "zad7.h"

void zadanie7() {
    std::vector<int> V;
    
    std::cout << "Введите четное количество целых чисел для вектора:" << std::endl;
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end;
    
    std::copy(input_iter, end, std::back_inserter(V));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    if (V.size() % 2 != 0) {
        std::cout << "Ошибка: количество элементов должно быть четным!" << std::endl;
        return;
    }
    
    std::vector<int> sorted_first_half(V.size()/2);
    std::partial_sort_copy(V.begin(), V.end(), sorted_first_half.begin(), sorted_first_half.end());
    V.insert(V.end(), sorted_first_half.begin(), sorted_first_half.end());
    
    std::cout << "Результат: ";
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(V.begin(), V.end(), output_iter);
    std::cout << std::endl;
}