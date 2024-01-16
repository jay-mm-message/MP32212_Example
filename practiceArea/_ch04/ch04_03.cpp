#include <iostream>
using namespace std;

class Node {
    public:
        int num;
        class Node *next;
    public: // constructor
        Node(int n) {
            num = n;
            next = NULL;
        }
        Node() {
            num = -1;
            next = NULL;
        }
};

class Linked_Stack {
    private:
        class Node *head;
    public: // constructor
        Linked_Stack();
        Linked_Stack(int data);
    public: // member function
        bool isEmpty();
        void push_stack(int data);
        int pop_stack();
};

int main() {

    Linked_Stack linkedStack;

    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        cout << "push (" << i << ") into linked stack" << endl;
        linkedStack.push_stack(i);
    }
    
    cout << endl;
    while (!linkedStack.isEmpty())
    {
        /* code */
         cout << "pop (" << linkedStack.pop_stack() << ") from linked stack" << endl;
    }
    
    cout << endl;
    return 0;
}

bool Linked_Stack::isEmpty()  {
    if (head == NULL)
    {
        /* code */
        return true;
    }
    return false;
}

void Linked_Stack::push_stack(int data)  {

    class Node *newNode = new Node(data);

    if (!isEmpty())
    {
        /* code */
        class Node *p = head;
        newNode->next = p;
        head = newNode;

        return;
    }
    
    head = newNode;
    return;
}

int Linked_Stack::pop_stack() {

    if (!isEmpty())
    {
        /* code */
        class Node *d = head;
        head = head->next;

        int data = d->num;
        delete d;
        
        return data;
    }
    
    cout << "Stack is empty" << endl;
    return -1;
}

Linked_Stack::Linked_Stack(int data)  {

    class Node *newNode = new Node(data);
    head = newNode;
}

Linked_Stack::Linked_Stack() { head = NULL; }