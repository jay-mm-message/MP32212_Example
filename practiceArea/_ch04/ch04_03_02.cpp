#include <iostream>
using namespace std;

template <class T>
class Node {
    public:
        T num;
        class Node<T> *next;
    public: // constructor
        Node(T n) {
            num = n;
            next = NULL;
        }
        Node() {
            num = -1;
            next = NULL;
        }
};

template <class T>
class Linked_Stack {
    private:
        class Node<T> *head;
    public: // constructor
        Linked_Stack();
        Linked_Stack(T data);
    public: // member function
        bool isEmpty();
        void push_stack(T data);
        T pop_stack();
};

int main() {

    Linked_Stack<int> linkedStack_a;

    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        linkedStack_a.push_stack(i);
        cout << "push (" << i << ") into linked stack" << endl;
    }
    
    cout << endl;
    while (!linkedStack_a.isEmpty())
    {
        /* code */
         cout << "pop (" << linkedStack_a.pop_stack() << ") from linked stack" << endl;
    }
    
    cout << endl;

    Linked_Stack<char> linkedStack_b;

    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        char letter = 'A' + i;
        linkedStack_b.push_stack(letter);
        cout << "push (" << letter << ") into linked stack" << endl;
    }
    
    cout << endl;
    while (!linkedStack_b.isEmpty())
    {
        /* code */
         cout << "pop (" << linkedStack_b.pop_stack() << ") from linked stack" << endl;
    }
    
    cout << endl;

    return 0;
}

template <class T>
bool Linked_Stack<T>::isEmpty()  {
    if (head == NULL)
    {
        /* code */
        return true;
    }
    return false;
}

template <class T>
void Linked_Stack<T>::push_stack(T data)  {

    class Node<T> *newNode = new Node<T>(data);

    if (!isEmpty())
    {
        /* code */
        class Node<T> *p = head;
        newNode->next = p;
        head = newNode;

        return;
    }
    
    head = newNode;
    return;
}

template <class T>
T Linked_Stack<T>::pop_stack() {

    if (!isEmpty())
    {
        /* code */
        class Node<T> *d = head;
        head = head->next;

        T data = d->num;
        delete d;
        
        return data;
    }
    
    cout << "Stack is empty" << endl;
    return -1;
}

template <class T>
Linked_Stack<T>::Linked_Stack(T data)  {

    class Node<T> *newNode = new Node<T>(data);
    head = newNode;
}

template <class T>
Linked_Stack<T>::Linked_Stack() { head = NULL; }