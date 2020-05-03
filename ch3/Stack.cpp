#include <iostream>
#include <string>

using namespace std;

class Stack {
    public:
        Stack() { top = -1; }
        ~Stack() { top = -1; }
        bool Push();
        bool Pop();
        void Show_DB();

    private:
     static const int MAX = 10;
     int top;
     string db_stack[MAX];

};

bool Stack::Push() {
    if ( top == MAX - 1 ) {
        cout << "Buff Overflow!!!!" << endl;
        return false;
    }
    cout << "Please entry data: ";
    ++top;
    cin >> db_stack[top];
    return true;
}

bool Stack::Pop() {
    if ( -1 == top ) {
        cout << "Sorry data is null!!!" << endl;
        return false;
    }

    cout << "[" << top << "]: " << db_stack[top] << endl;
    --top;
    return true;
}

void Stack::Show_DB() {
    cout << "Show_db is begin." << endl;
    while(Pop() == true) {
        ;;
    }
    cout << "Show_db is finish." << endl;
}

int main() {

    Stack db;

    while(db.Push() == true) {
        ;;
    }

    db.Show_DB();

    cout << endl;
    return 0;
}