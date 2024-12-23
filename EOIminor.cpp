#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100; // Max number of tasks

string tasks[MAX_TASKS]; // Array to store tasks
int taskCount = 0;       // Current number of tasks

void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "List is full.\n";
        return;
    }
    cout << "Enter task: ";
    cin.ignore(); // Clear input buffer
    getline(cin, tasks[taskCount]);
    taskCount++;
    cout << "Task added.\n";
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "List is empty.\n";
        return;
    }
    cout << "\n--- To-Do List ---\n";
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << tasks[i] << '\n';
    }
}

void deleteTask() {
    if (taskCount == 0) {
        cout << "List is empty.\n";
        return;
    }
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid number.\n";
        return;
    }
    for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "Task deleted.\n";
}

void displayMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Add task\n";
    cout << "2. View tasks\n";
    cout << "3. Delete task\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
