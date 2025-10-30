#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "zad4.h"

void zadanie4() {
    double A, D;
    int N;
    
    std::cout << "Введите первый элемент прогрессии A: ";
    std::cin >> A;
    std::cout << "Введите разность прогрессии D: ";
    std::cin >> D;
    std::cout << "Введите количество членов прогрессии N: ";
    std::cin >> N;
    
    if (N <= 0) {
        std::cout << "Ошибка: N должно быть положительным!" << std::endl;
        return;
    }
    
    std::vector<double> progression(N);
    double current = A;
    
    std::generate_n(progression.begin(), N, [&current, D]() {
        double result = current;
        current += D;
        return result;
    });
    
    std::cout << "Арифметическая прогрессия: ";
    std::ostream_iterator<double> output_iter(std::cout, " ");
    std::copy(progression.begin(), progression.end(), output_iter);
    std::cout << std::endl;
}