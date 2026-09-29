#include <iostream>
#include <string>
#include "TaskManager.hpp"

void printMenu() {
    std::cout << "\n=== MЕНЮ УПРАВЛЕНИЯ ===" << std::endl;
    std::cout << "1. Показать все задачи" << std::endl;
    std::cout << "2. Добавить новую задачу" << std::endl;
    std::cout << "3. Отметить задачу выполненной" << std::endl;
    std::cout << "0. Выйти из программы" << std::endl;
    std::cout << "Выберите действие: ";
}

int main() {
    TaskManager manager;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                manager.printAllTasks();
                break;
            }
            case 2: {
                std::cout << "Введите название задачи: ";
                std::string title;
                std::cin.ignore(); // Очищаем буфер от '\n'
                std::getline(std::cin, title);
                if (!title.empty()) {
                    manager.addTask(title);
                } else {
                    std::cout << "Название задачи не может быть пустым." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Введите ID задачи для отметки: ";
                int id;
                if (std::cin >> id) {
                    manager.markTaskCompleted(id);
                } else {
                    std::cout << "Некорректный ID." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 0:
                std::cout << "Выход из программы. До свидания!" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                break;

        }
    }

    return 0;
}
