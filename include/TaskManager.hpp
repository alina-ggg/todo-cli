#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <vector>
#include <string>
#include "Task.hpp"

class TaskManager {
    private:
        std::vector<Task> tasks;
        int nextId;
        std::string filename;

    public:
        TaskManager(const std::string& file = "tasks.txt");

        void addTask(const std::string& title);
        void printAllTasks() const;
        void markTaskCompleted(int id);

        void saveToFile() const;
        void loadFromFile();
};

#endif // TASK_MANAGER_HPP