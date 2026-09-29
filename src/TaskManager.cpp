#include "TaskManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

TaskManager::TaskManager(const std::string& file) : nextId(1), filename(file) {
    loadFromFile();
}

void TaskManager::addTask(const std::string& title) {
    tasks.push_back(Task(nextId++, title));
    std::cout << "Задача успешно добавлена!" << std::endl;
    saveToFile();
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
            saveToFile();
            return;
        }
    }
    std::cout << "Ошибка: Задача с ID " << id << " не найдена." << std::endl;
}

void TaskManager::saveToFile() const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл для сохранения!" << std::endl;
        return;
    }

    for (const auto& task : tasks) {
        outFile << task.getId() << "|"
                << task.getIsCompleted() << "|"
                << task.getTitle() << "\n";
    }
}

void TaskManager::loadFromFile() {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        return;
    }

    tasks.clear();
    std::string line;
    int maxId = 0;

    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string idStr, completedStr, title;

        if (std::getline(ss, idStr, '|') &&
            std::getline(ss, completedStr, '|') &&
            std::getline(ss, title)) {
            
            int id = std::stoi(idStr);
            bool isCompleted = (completedStr == "1");

            Task task(id, title);
            if (isCompleted) {
                task.markCompleted();
            }

            tasks.push_back(task);
            if (id > maxId) {
                maxId = id;
            }
        }
    }

    nextId = maxId + 1;
}