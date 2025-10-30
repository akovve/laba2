#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "zad5.h"

void zadanie5() {
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
    
    int half = V.size() / 2;
    bool found = false;
    
    for (int i = 0; i < half && !found; i++) {
        auto it = std::find(V.begin() + half, V.end(), V[i]);
        if (it != V.end()) {
            V.insert(V.begin() + i, 0);
            found = true;
        }
    }
    
    std::cout << "Результат: ";
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(V.begin(), V.end(), output_iter);
    std::cout << std::endl;
}