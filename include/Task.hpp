#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
private:
    int id;
    std::string title;
    bool isCompleted;

public:
    Task(int id, const std::string& title);

    int getId() const;
    std::string getTitle() const;
    bool getIsCompleted() const;

    void markCompleted();
    void print() const;
};

#endif // TASK_HPP
