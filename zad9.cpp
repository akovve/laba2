#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include "zad9.h"

void zadanie9() {
    std::vector<int> V0;
    std::vector<std::vector<int>> vectors;
    int N;
    
    std::cout << "Введите элементы вектора V0 (завершите ввод любым нечисловым символом):" << std::endl;
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end;
    
    std::copy(input_iter, end, std::back_inserter(V0));
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    if (V0.empty()) {
        std::cout << "Ошибка: вектор V0 не может быть пустым!" << std::endl;
        return;
    }
    
    std::cout << "Введите количество векторов N (> 0): ";
    std::cin >> N;
    
    if (N <= 0) {
        std::cout << "Ошибка: N должно быть > 0!" << std::endl;
        return;
    }
    
    for (int i = 0; i < N; i++) {
        std::vector<int> current;
        std::cout << "Введите элементы вектора V" << (i + 1) << " (завершите ввод любым нечисловым символом):" << std::endl;
        
        std::cin.clear();
        input_iter = std::istream_iterator<int>(std::cin);
        std::copy(input_iter, end, std::back_inserter(current));
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        vectors.push_back(current);
    }
    
    std::multiset<int> V0_set(V0.begin(), V0.end());
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        std::multiset<int> current_set(vectors[i].begin(), vectors[i].end());
        if (std::includes(current_set.begin(), current_set.end(), V0_set.begin(), V0_set.end())) {
            count++;
        }
    }
    
    std::cout << "Количество векторов, содержащих все элементы V0: " << count << std::endl;
}