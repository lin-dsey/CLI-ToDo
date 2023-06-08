#include <iostream>
#include <vector>
#include <limits>

struct Task {
    std::string description;
    bool completed;
};

// Create a new "task" object
void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter new task description: ";
    std::getline(std::cin >> std::ws, description);
    
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    
    tasks.push_back(newTask); // Add new task to the vector
    std::cout << "Task added successfully!\n";
}

// Deletes task by index number, starting with "1"
void deleteTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }
    
    std::cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description << std::endl; // Display the index and description of each task
    }
    
    size_t index;
    std::cout << "Enter the task index number to delete: ";
    std::cin >> index; // Read the index of the task to be deleted
    
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1); // Delete the task at the specified index
        std::cout << "Task deleted successfully!\n";
    } else {
        std::cout << "Invalid task index number.\n";
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
}

// Iterate over the task vector and print the index number and description of each task object
void listTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }
    
    std::cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[x] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl; // Display the index and description of each task
    }
}

int main() {
    std::vector<Task> tasks; // Dynamic vector to store tasks
    int choice;
    
    while (true) {
        std::cout << "\n:.:.:.:.:.: To-Do List :.:.:.:.:.:\n";
        std::cout << "1. Add a new task\n";
        std::cout << "2. Delete a task\n";
        std::cout << "3. List all tasks\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer for next input operation
        
        switch (choice) {
            case 0:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;
            case 1:
                addTask(tasks);
                break;
            case 2:
                deleteTask(tasks);
                break;
            case 3:
                listTasks(tasks);
                break;
            default:
                std::cout << "Invalid. Please try again.\n";
        }
    }
}
