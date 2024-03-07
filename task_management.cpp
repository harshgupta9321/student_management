#include <iostream>
#include <vector>
#include <iomanip>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added successfully.\n";
    }

    void markTaskComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as complete.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void displayTasks() const {
        std::cout << "Task List:\n";
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << std::setw(3) << i + 1 << ". ";
                std::cout << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << "\n";
            }
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        std::cout << "\nTask Management System\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Complete\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    std::string description;
                    std::cout << "Enter task description: ";
                    std::cin.ignore();
                    std::getline(std::cin, description);
                    taskManager.addTask(description);
                    break;
                }
            case 2:
                {
                    int index;
                    std::cout << "Enter the task index to mark as complete: ";
                    std::cin >> index;
                    taskManager.markTaskComplete(index - 1);
                    break;
                }
            case 3:
                taskManager.displayTasks();
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
