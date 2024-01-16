#include <iostream>
using namespace std;

class Node {
    public:
        string message;
        Node *next;
    public:
        Node();
        Node(string meg);
};

class Stack {
    public:
        Node *head;
        int count;
    public:
        Stack();
        bool isEmpty();
        void Stack_Push(string meg);
        string Stack_Pop();
};

typedef Stack *Link;
template <class T>
void towerOfHanoi(int numDisks, T, T, T, Link);
template <class T>
void towerOfHanoi_verify(int numDisks, T source, T auxiliary, T destination, Link);

void verify_and_show(Link link_a, Link link_b);

int main(void) {
    
    Link link_a = new Stack();
    Link link_b = new Stack();
        
    cout << "Please enter plates: ";
    int num;
    cin >> num;
    
    towerOfHanoi(num, "A", "B", "C", link_a);
    cout << endl;

    towerOfHanoi_verify(num, "A", "B", "C", link_b);
    cout << endl;

    verify_and_show(link_a, link_b);
    return 0;
}

string disk_last_move_meg(string source, string destination);
string disk_run_move_meg(int numDisks, string source, string destination);

template <class T>
void towerOfHanoi(int numDisks, T source, T auxiliary, T destination, Link link) {

    if (numDisks == 1)
    {
        /* code */
        //cout << "Move plate 1 from " << source << " to " << destination << endl;
        string s = disk_last_move_meg(source, destination);

        link->Stack_Push(s);
        return;
    }
    
    towerOfHanoi(numDisks - 1, source, destination, auxiliary, link);

    //cout << "Move plate " << numDisks << " from " << source << " to " << destination << endl;
    string s = disk_run_move_meg(numDisks, source, destination);
   
    link->Stack_Push(s);

    towerOfHanoi(numDisks - 1, auxiliary, source, destination, link);
}

// Tower of Hanoi function
template <class T>
void towerOfHanoi_verify(int numDisks, T source, T auxiliary, T destination, Link link) {
    // Base case: If there is only one disk, move it from source to destination
    if (numDisks == 1) {
        //std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        string s = disk_last_move_meg(source, destination);

        link->Stack_Push(s);
        return;
    }

    // Recursive case:
    // Move (n-1) disks from source to auxiliary peg
    towerOfHanoi_verify(numDisks - 1, source, destination, auxiliary, link);

    // Move the nth disk from source to destination peg
    //cout << "Move disk " << numDisks << " from " << source << " to " << destination << endl;
    string s = disk_run_move_meg(numDisks, source, destination);
   
    link->Stack_Push(s);

    // Move (n-1) disks from auxiliary to destination peg
    towerOfHanoi_verify(numDisks - 1, auxiliary, source, destination, link);
}

Stack::Stack() {
    head = NULL;
    count = 0;
}

void Stack::Stack_Push(string meg) {

    Node *newNode = new Node(meg);

    if (!isEmpty())
    {
        /* code */
        count++;
        Node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = newNode;
        return;
    }
    count = 1;
    head = newNode;
}

string Stack::Stack_Pop() {

    if (!isEmpty()) {
        --count;
        Node *d = head;
        head = head->next;
        string meg = d->message;
        delete d;
        return meg;
    }
    return "";
}

bool Stack::isEmpty() {
    if (count == 0)
    {
        /* code */
        return true;
    }
    return false;
}


Node::Node() {
    message = "";
    next = NULL;
}
Node::Node(string meg) {
    message = meg;
    next = NULL;
}

string disk_last_move_meg(string source, string destination) {
    string s = "";
    s = string("Move disk 1 from ");
    s += source;
    s += string(" to ");
    s += destination;
    return s;
}
string disk_run_move_meg(int numDisks, string source, string destination) {
    string s = "";
    s = string("Move disk ");
    s += to_string(numDisks);
    s += string(" from ");
    s += source;
    s += string(" to ");
    s += destination;
    return s;
}

void verify_and_show(Link link_a, Link link_b) {
    while (!link_b->isEmpty())
    {
        /* code */
        string source = link_a->Stack_Pop();
        string destination = link_b->Stack_Pop();

        if (source == destination)
        {
            /* code */
            cout << source << endl;
        }
        else
        {
            cout << "verify fail: " << source << " != " << destination << endl;
        }
        
    }
    
}