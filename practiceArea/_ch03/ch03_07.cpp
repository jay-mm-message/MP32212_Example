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
    link p = head;

    for (size_t i = 0; i < count; i++)
    {
        link newNode = new node;
        newNode->num = i + 1;
        newNode->letters[0] = 'A' + i;
        newNode->letters[1] = '\0';
        newNode->next = NULL;
        /* code */
        if (p == NULL)
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
link concatenation(link a, link b) {
    link p = NULL;

    if (a == NULL and b != NULL)
    {
        /* code */
        p = b;
    }
    else if (a != NULL and b == NULL)
    {
        p = a;
    }
    else
    {
        p = a;
        while (p->next != NULL)
        {
            /* code */
            p = p->next;
        }
        p->next = b;
        p = a;
    }

    return p;    
}
int main(void) {
    // init
    link head_a = NULL, head_b = NULL;
    head_a = init(head_a, 5);
    head_b = init(head_b, 5);
    // show
    cout << "head_a: " << endl;
    show(head_a);
    cout << "head_b: " << endl;
    show(head_b);
    // concatenation
    link head_c = concatenation(head_a, head_b);
    // show
    show(head_c);
    return 0;
}