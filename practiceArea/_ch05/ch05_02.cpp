#include <iostream>
using namespace std;

class Node {
    public:
        char letter;
        class Node *next;
    public:
        Node() : letter('\0'), next(nullptr) {}
        Node(char l) : letter(l), next(nullptr) {}
};

typedef Node *Link;
class Queue_LinkList {
    public:
        Link front;
        Link rear;
    public:
        Queue_LinkList() : front(nullptr), rear(nullptr) {}
        bool isEmpty();
        bool enqueue(char l);
        bool dequeue(char &l);
};

int main() {

    Queue_LinkList qLink;

    cout << "PUSH: ";
    char letter;
    int count = 3;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        letter = 'A' + i;
        if (qLink.enqueue(letter))
        {
            /* code */
            cout << letter << ' ';
        }
    }
    cout << endl;

    cout << "POP: ";
    char letter_get;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        if (qLink.dequeue(letter_get))
        {
            /* code */
            cout << letter_get << ' ';
        }
    }
    cout << endl;
    
    return 0;
}

bool Queue_LinkList::dequeue(char &l) {
    
    if (isEmpty())
    {
        /* code */
        cout << "Err dequeue fail" << endl;
        return false;
    }

    if (front == rear)
    {
        /* code */
        Link d = front;
        front = rear = nullptr;
        l = d->letter;
        delete d;
    }
    else
    {
        Link d = front;
        front = front->next;
        l = d->letter;
        delete d;
    }
    
    return true;
}

bool Queue_LinkList::enqueue(char l) {

    Link newNode = new Node(l);
    if (nullptr == newNode)
    {
        /* code */
        cout << "Err enqueue fail" << endl;
        return false;
    }

    if (nullptr == front)
    {
        /* code */
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    
    return true;
}

bool Queue_LinkList::isEmpty() {
    if (nullptr == rear)
    {
        /* code */
        cout << "Queue is empty" << endl;
        return true;
    }
    
    return false;
}