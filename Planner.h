#include <string>

using namespace std;

// A planner represented by a linked list

class Planner {
    private:
        class Task {
            public:
                string name;
                string desc;
                string deadline;
                Task *next;
        };
        Task *head;
        bool dateIsOlderThan(string d1, string d2);

    public:
        Planner();
        ~Planner();
        bool isEmpty();
        bool contains(string name);
        void add(string name, string desc, string deadline);
        bool remove(string name);
        void display();
};