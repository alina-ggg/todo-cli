#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <vector>
#include "Task.hpp"

class TaskManager {
    private:
        std::vector<Task> tasks;
        int nextId;

    public:
        TaskManager();

        void addTask(const std::string& title);
        void printAllTasks() const;
        void markTaskCompleted(int id);
};

#endif // TASK_MANAGER_HPP