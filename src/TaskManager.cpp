#include "TaskManager.hpp"
#include <iostream>

TaskManager::TaskManager() : nextId(1) {}

void TaskManager::addTask(const std::string& title) {
    tasks.push_back(Task(nextId++, title));
    std::cout << "Задача успешно добавлена!" << std::endl;
}

void TaskManager::printAllTasks() const {
    if (tasks.empty()) {
        std::cout << "Список задач пуст." << std::endl;
        return;
    }

    std::cout << "\n=== Список задач ===" << std::endl;
    for (const auto& task : tasks) {
        task.print();
    }
    std::cout << "====================\n" << std::endl;
}

void TaskManager::markTaskCompleted(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            std::cout << "Задача №" << id << " отмечена как выполненная!" << std::endl;
            return;
        }
    }
    std::cout << "Ошибка: Задача с ID " << id << " не найдена." << std::endl;
}