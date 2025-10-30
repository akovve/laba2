#include <iostream>
#include <windows.h>
#include "zad1.h"
#include "zad2.h"
#include "zad3.h"
#include "zad4.h"
#include "zad5.h"
#include "zad6.h"
#include "zad7.h"
#include "zad8.h"
#include "zad9.h"
#include "zad10.h"
#include "menu.h"

void setupConsole() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
}

int main() {
    setupConsole();
    int choice = 0;
    
    do {
        showFullMenu();
        std::cin >> choice;
        
        switch(choice) {
            case 1: zadanie1(); break;
            case 2: zadanie2(); break;
            case 3: zadanie3(); break;
            case 4: zadanie4(); break;
            case 5: zadanie5(); break;
            case 6: zadanie6(); break;
            case 7: zadanie7(); break;
            case 8: zadanie8(); break;
            case 9: zadanie9(); break;
            case 10: zadanie10(); break;
            case 0:
                std::cout << "Выход из программы..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
        }
        
        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.ignore();
            std::cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}