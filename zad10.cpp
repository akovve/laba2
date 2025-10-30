#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include "zad10.h"

void zadanie10() {
    std::vector<int> V;
    
    std::cout << "Введите целые числа для вектора (завершите ввод любым нечисловым символом):" << std::endl;
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end;
    
    std::copy(input_iter, end, std::back_inserter(V));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    std::multimap<int, int> M;
    
    for (int num : V) {
        int last_digit = abs(num) % 10;
        M.insert(std::make_pair(last_digit, num));
    }
    
    std::cout << "Результат группировки:" << std::endl;
    for (const auto& pair : M) {
        std::cout << "Ключ: " << pair.first << ", Элемент: " << pair.second << std::endl;
    }
}