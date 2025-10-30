#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "zad1.h"

void zadanie1() {
    std::list<int> L;
    
    std::cout << "Введите целые числа (для завершения введите любой нечисловой символ):" << std::endl;
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end;
    
    std::copy(input_iter, end, std::back_inserter(L));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    std::cout << "Исходный порядок: ";
    std::ostream_iterator<int> output_iter(std::cout, " ");
    std::copy(L.begin(), L.end(), output_iter);
    std::cout << std::endl;
    
    std::cout << "Обратный порядок: ";
    std::copy(L.rbegin(), L.rend(), output_iter);
    std::cout << std::endl;
}