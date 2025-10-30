#include <iostream>
#include <list>
#include <deque>
#include <sstream>
#include <string>
#include "zad8.h"

void zadanie8() {
    std::list<std::string> L;
    std::deque<std::string> D;
    
    std::cin.ignore(1000, '\n');
    
    std::cout << "Введите английские слова через пробел (минимум 2 слова):" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    std::string word;
    while (iss >> word) {
        L.push_back(word);
    }
    
    if (L.size() < 2) {
        std::cout << "Ошибка: нужно как минимум 2 слова!" << std::endl;
        return;
    }
    
    auto it = L.begin();
    auto next_it = std::next(it);
    
    while (next_it != L.end()) {
        std::string new_word = std::string(1, (*it)[0]) + std::string(1, (*next_it).back());
        D.push_back(new_word);
        ++it;
        ++next_it;
    }
    
    std::cout << "Результат - дек D: ";
    for (const auto& w : D) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
}