#include <iostream>
using namespace std;

class Node {
    public:
        char letter;
        class Node *next;
        Node();
        Node(char);
};

typedef Node *Link;
class Stack {
    public:
        Link head;
    // constructor
        Stack();
    // push
        bool push_stack(char l);
    // pop
        char pop_stack();
        // isEmpty
        bool isEmpty();

};

const int PUSH_MODE = 1;
const int POP_MODE = 2;
void show_stack(Stack *sk, int mode, int count, char ch);

int main() {

    Stack sk;
    int count = 3;
    show_stack(&sk, PUSH_MODE, count, 'A');
    show_stack(&sk, POP_MODE, count, '\0');

    
    return 0;
}

void show_stack(Stack *sk, int mode, int count, char ch) {
    switch (mode)
    {
    case PUSH_MODE:
        /* code */
        char letter_push;
        cout << "Push: " << ' ';
        for (size_t i = 0; i < count; i++)
        {
            /* code */
            letter_push = ch + i;
            if (sk->push_stack(letter_push))
            {
                /* code */
                cout << letter_push << ' ';
            }
        }
        cout << endl;
        
        break;
    case POP_MODE:
        /* code */
        char letter_pop = '\0';
        cout << "Pop: " << ' ';
        for (size_t i = 0; i < count; i++)
        {
            /* code */
            if ((letter_pop = sk->pop_stack()) != '\0')
            {
                /* code */
                cout << letter_pop << ' ';
            }
        }
        cout << endl;
        break;
    
    // default:
    //     break;
    }
}



Stack::Stack() {
            head = NULL;
        }
bool Stack::isEmpty() {
            if (NULL == head)
            {
                /* code */
                cout << "Err: Stack is empty" << endl;
                return true;
            }
            
            return false;
        }
char Stack::pop_stack() {
    if (isEmpty())
    {
        /* code */
        return '\0';
    }
    Link p = head;
    head = head->next;
    char l = p->letter;
    delete p;

    return l;
}

bool Stack::push_stack(char l) {
    Link newNode = new Node(l);
    if (NULL == newNode)
    {
        /* code */
        cout << "Err: push_stack: " << l << endl;
        return false;
    }

    if (NULL == head)
    {
        /* code */
        head = newNode;
        return true;
    }

    newNode->next = head;
    head = newNode;
    
    return true;
}

Node::Node() {
            letter = '\0';
            next = NULL;
        }
Node::Node(char l) {
            letter = l;
            next = NULL;
        }