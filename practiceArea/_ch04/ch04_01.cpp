#include <iostream>
using namespace std;

class Box {
    private:
        int size;
        int top;
        int *dynamic_stack;
    public:
        Box(int s);
        bool isEmpty();
        bool isFull();
        void push_stack(int data);
        int pop_stack();
};

typedef Box *stack;


int main() {

    stack ss = new Box(10);
    int i = 0;

    while(!ss->isFull()) {
        cout << "push (" << i << ") into stack" << endl;
        ss->push_stack(i);
        ++i;
    }

    cout << endl;
    while(!ss->isEmpty()) {
        cout << "pop (" << ss->pop_stack() << ") from stack" << endl;
    }
    cout << endl;
    return 0;
}

Box::Box(int s)  {
    size = s;
    top = -1;
    dynamic_stack = new int[size];
}
bool Box::isEmpty()  {
    if (top == -1)
    {
        /* code */
        return true;
    }
    return false;
}
bool Box::isFull() {
    if (top == size)
    {
        /* code */
        return true;
    }
    return false;
}
void Box::push_stack(int data) {
    if (isFull())
    {
        /* code */
        cout << "Stack is full" << endl;
        return;
    }
    dynamic_stack[++top] = data;
}
int Box::pop_stack() {
    if (isEmpty())
    {
        /* code */
        cout << "Stack is empty" << endl;
        return -1;
    }
    int value = dynamic_stack[top];
    --top;
    return value;
}