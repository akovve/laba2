#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include "zad6.h"

void zadanie6() {
    std::list<int> L;
    int K;
    
    std::cout << "Введите K (0 < K < 5): ";
    std::cin >> K;
    
    if (K <= 0 || K >= 5) {
        std::cout << "Ошибка: K должно быть в диапазоне (0, 5)!" << std::endl;
        return;
    }
    
    std::cout << "Введите целые числа для списка (≥10 элементов, завершите нечисловым символом):" << std::endl;
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end;
    
    std::copy(input_iter, end, std::back_inserter(L));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    if (L.size() < 10) {
        std::cout << "Ошибка: количество элементов должно быть ≥10!" << std::endl;
        return;
    }
    
    auto first5_begin = L.begin();
    auto first5_end = L.begin();
    std::advance(first5_end, 5);
    
    std::vector<int> temp1(5);
    std::copy(first5_begin, first5_end, temp1.begin());
    std::rotate(temp1.begin(), temp1.end() - K, temp1.end());
    L.insert(L.end(), temp1.begin(), temp1.end());
    
    auto last5_begin = L.begin();
    std::advance(last5_begin, L.size() - 10);
    auto last5_end = L.begin();
    std::advance(last5_end, L.size() - 5);
    
    std::vector<int> temp2(5);
    std::copy(last5_begin, last5_end, temp2.begin());
    std::rotate(temp2.begin(), temp2.begin() + K, temp2.end());
    L.insert(L.begin(), temp2.begin(), temp2.end());
    
    std::cout << "Результат: ";
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(L.begin(), L.end(), output_iter);
    std::cout << std::endl;
}