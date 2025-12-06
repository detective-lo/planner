#include <iostream>
#include <string>
#include "Planner.h"

using namespace std;

// Function definitions for Planner class

Planner::Planner() {
    head = nullptr;
}

Planner::~Planner() {
    Task *p = head;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
    head = nullptr;
}

bool Planner::isEmpty() {
    return (head == nullptr);
}

bool Planner::contains(string name) {
    Task *p = head;

    while (p && p->name != name) {
        p = p->next;
    }

    return (p != nullptr);
}

bool Planner::dateIsOlderThan(string d1, string d2) {
    // For dates provided in mm/dd/yyyy format
    int month1 = stoi(d1.substr(0, 2));
    int month2 = stoi(d2.substr(0,2));

    int day1 = stoi(d1.substr(3, 2));
    int day2 = stoi(d2.substr(3, 2));
    
    int year1 = stoi(d1.substr(6));
    int year2 = stoi(d2.substr(6));

    if (year1 < year2) {
        return true;
    } else if (year1 > year2) {
        return false;
    }
    
    if (month1 < month2) {
        return true;
    } else if (month1 > month2) {
        return false;
    }
    
    return (day1 < day2);
}

void Planner::add(string name, string desc, string deadline) {
    Task *newTask = new Task;
    newTask->name = name;
    newTask->desc = desc;
    newTask->deadline = deadline;
    newTask->next = nullptr;

    // Non-empty list
    Task *p = head;
    Task *n = nullptr;

    while (p && !dateIsOlderThan(newTask->deadline, p->deadline)) {
        n = p;
        p = p->next;
    }

    if (n) {
        n->next = newTask;
    } else {
        // Is first task
        head = newTask;
    }
    newTask->next = p;

    return;
}

bool Planner::remove(string name) {
    Task *p = head;
    Task *n = nullptr;

    while (p && p->name != name) {
        n = p;
        p = p->next;
    }

    if (p) {
        if (n) {
            n->next = p->next;
        } else {
            // Is first task
            head = head->next;
        }
        delete p;
        return true;
    } else {
        // Not in list
        return false;
    }
}

void Planner::display() {
    Task *p = head;
    while (p) {
        cout << endl;
        cout << p->name << " (" << p->deadline << ")" << endl;
        cout << p->desc << endl;
        p = p->next;
    }
}