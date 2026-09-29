#include <iostream>
#include "Task.hpp"

int main() {
    Task task1(1, "Купить продукты");
    Task task2(2, "Сделать коммит в Git");

    task2.markCompleted();

    std::cout << "--- Список задач ---" << std::endl;
    task1.print();
    task2.print();
    return 0;
}
