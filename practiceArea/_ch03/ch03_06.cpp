#include <iostream>
using namespace std;

class node {
    public:
        int num;
        char letters[2];
    class node *next;
};

typedef node *link;

link init(link head, int count) {
    link p = NULL;

    for (size_t i = 0; i < count; i++)
    {
        /* code */
        link newNode = new node;
        newNode->num = i + 1;
        newNode->letters[0] = 'A' + i;
        newNode->letters[1] = '\0';
        newNode->next = NULL;

        if (head == NULL)
        {
            /* code */
            head = newNode;
            p = head;
        }
        else
        {
            p->next = newNode;
            p = p->next;
        }
        
    }
    return head;
}

void show(link head) {
    link p = head;

    while (p != NULL)
    {
        /* code */
        cout << p->num << ":" << p->letters << ' ';
        p = p->next;
    }
    cout << endl;    
}

link invert(link head) {
    link p = head;
    
    link r = NULL;
    link q = NULL;
    while (p != NULL)
    {
        /* code */
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

int main(void) {

    link head = NULL;
    // init
    head = init(head, 5);
    // show
    show(head);
    // invert
    head = invert(head);
    // show
    show(head);

    return 0;
}