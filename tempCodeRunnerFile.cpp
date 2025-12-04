#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Task {
    string name;
    string status;
};

void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int ch;

    do {
        // Display menu
        cout << "\n--- To-Do List for Manager ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting........ Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (ch!= 5);

    return 0;
}

void addTask(vector<Task>& tasks) {
    string ts_nm;
    cout << "Enter task description to add: ";
    getline(cin,ts_nm);
    Task newTask = {ts_nm,"pending"};
    tasks.push_back(newTask);
    cout << "Task added successfully to list.\n";
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in your list.\n";
        return;
    }

    cout << "\nYour Tasks are listed as follows:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].status == "completed" ? "Completed" : "Pending") << "] " 
     << tasks[i].name << endl;

    }
}

void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int tasknm;
    viewTasks(tasks);
    cout << "Enter task number to mark as completed: ";
    cin >> tasknm;

    if (tasknm < 1 || tasknm > tasks.size()) {
        cout << "Invalid task number,please try again letter !\n";
    } else {
        tasks[tasknm - 1].status="completed";
        cout << "Task marked as completed.\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int tasknm;
    viewTasks(tasks);
    cout << "Enter task number to remove: ";
    cin >> tasknm;

    if (tasknm < 1 || tasknm > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + tasknm - 1);
        cout << "Task removed successfully from list.\n";
    }
}
