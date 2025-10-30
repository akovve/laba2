#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include "zad2.h"

void zadanie2() {
    std::vector<int> V;
    std::deque<int> D;
    
    std::cout << "Введите четное количество целых чисел для вектора V:" << std::endl;
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end;
    
    std::copy(input_iter, end, std::back_inserter(V));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    if (V.size() % 2 != 0) {
        std::cout << "Ошибка: количество элементов вектора должно быть четным!" << std::endl;
        return;
    }
    
    std::cout << "Введите четное количество целых чисел для дека D:" << std::endl;
    input_iter = std::istream_iterator<int>(std::cin);
    
    std::copy(input_iter, end, std::back_inserter(D));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    if (D.size() % 2 != 0) {
        std::cout << "Ошибка: количество элементов дека должно быть четным!" << std::endl;
        return;
    }
    
    V.insert(V.end(), D.begin(), D.begin() + D.size()/2);
    D.insert(D.begin(), V.rbegin() + V.size()/2, V.rend());
    
    std::cout << "Результат - вектор V: ";
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(V.begin(), V.end(), output_iter);
    std::cout << std::endl;
    
    std::cout << "Результат - дек D: ";
    std::copy(D.begin(), D.end(), output_iter);
    std::cout << std::endl;
}