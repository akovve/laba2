#include <iostream>
#include "menu.h"

void showFullMenu() {
    std::cout << "\n=== ПОЛНОЕ МЕНЮ ===" << std::endl;
    std::cout << "1 - задача 1 (Список в прямом и обратном порядке)" << std::endl;
    std::cout << "2 - задача 2 (Вектор и дек)" << std::endl;
    std::cout << "3 - задача 3 (Удаление средних элементов)" << std::endl;
    std::cout << "4 - задача 4 (Арифметическая прогрессия)" << std::endl;
    std::cout << "5 - задача 5 (Поиск и вставка нуля)" << std::endl;
    std::cout << "6 - задача 6 (Циклические сдвиги)" << std::endl;
    std::cout << "7 - задача 7 (Сортировка и вставка)" << std::endl;
    std::cout << "8 - задача 8 (Обработка строк)" << std::endl;
    std::cout << "9 - задача 9 (Поиск включений)" << std::endl;
    std::cout << "10 - задача 10 (Группировка по последней цифре)" << std::endl;
    std::cout << "0 - Выход" << std::endl;
    std::cout << "Выберите задачу: ";
}