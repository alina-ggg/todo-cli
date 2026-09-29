#include "Task.hpp"
#include <iostream>

Task::Task(int id, const std::string& title)
    : id(id), title(title), isCompleted(false) {}

int Task::getId() const {
    return id;
}

std::string Task::getTitle() const {
    return title;
}

bool Task::getIsCompleted() const {
    return isCompleted;
}

void Task::markCompleted() {
    isCompleted = true;
}

void Task::print() const {
    std::cout << "[" << (isCompleted ? "X" : " ") << "] "
              << id << ". " << title << std::endl;
}