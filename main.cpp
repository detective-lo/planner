#include <iostream>
#include "Planner.h"

using namespace std;

void printMenu() {
    cout << "Menu" << endl;
    cout << "1: Display menu" << endl;
    cout << "2: Add task" << endl;
    cout << "3: Remove task" << endl;
    cout << "4: Show all tasks" << endl;
    cout << "0: Quit" << endl;
}

int main() {
    Planner todo;
    int command; // input command
    string name; // input name
    string desc; // input description
    string deadline; // input deadline
    char confirm = 'n'; // confirmation

    cout << "Welcome to your planner!" << endl;
    printMenu();
    cout << endl;

    cout << "Please enter a command: ";
    cin >> command;

    // Menu
    // 1: Display menu
    // 2: Add a task
    // 3: Remove a task
    // 4: Show all tasks
    // 0: Quit

    while (command != 0) {
        switch (command)  {
            case 1:
                // Display menu
                printMenu();
                break;
        
            case 2:
                // Add task
                confirm = 'n';
                cout << "Name: ";
                cin >> ws;
                getline(cin, name);

                cout << "Description: ";
                cin >> ws;
                getline(cin, desc);

                cout << "Deadline (mm/dd/yyyy): ";
                cin >> ws;
                getline(cin, deadline);

                cout << endl;
                cout << name << ": " << deadline << endl;
                cout << desc << endl;

                cout << "Would you like to add this task? (y/n): ";
                cin >> confirm;

                if (toupper(confirm) == 'Y') {
                    todo.add(name, desc, deadline);
                    cout << "Successfully added " << name << "." << endl;
                }
                break;

            case 3:
                // Remove task
                if (todo.isEmpty()) {
                    cout << "There is nothing to remove." << endl;
                    break;
                }

                confirm = 'n';
                cout << "Name to remove: ";
                cin >> ws;
                getline(cin, name);
                cout << endl;

                if (!todo.contains(name)) {
                    cout << "Task could not be found." << endl;
                    break;
                }

                cout << name << endl;
                cout << "Would you like to remove this task? (y/n): ";
                cin >> confirm;

                if (toupper(confirm) == 'Y') {
                    if (todo.remove(name)) {
                        cout << name << " successfully removed." << endl;
                    } else {
                        cout << name << " not found." << endl;
                    }
                }

                break;

            case 4:
                // Show all tasks
                if (todo.isEmpty()) {
                    cout << "There is nothing to display." << endl;
                    break;
                }

                cout << "Planner" << endl;
                cout << "----------";
                todo.display();
                break;

            default:
                cout << "Command not recognized." << endl;
                cout << "Press 1 to see commands. " << endl;
        }

        cout << endl << "Please enter a command: ";
        cin >> command;
    }

    return 0;
}