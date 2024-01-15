#include <iostream>
using namespace std;

class node {
    public:
        int num;
        char letters[2];
    class node *next;
};

typedef node *link;

link init_cycle_link(link head, int count) {
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
    } // for 
    p->next = head;
    return head;
}

void show_cycle(link head) {
    link p = head;

    cout << p->num << ":" << p->letters << ' ';
    p = p->next;
    while (p != head)
    {
        /* code */
        cout << p->num << ":" << p->letters << ' ';
        p = p->next;
    }
    cout << endl;
}

link insert_node(link head, int num, link data) {
    
    link p = head;
    link newNode = new node;
    newNode->num = data->num;
    strcpy(newNode->letters, data->letters);

    if (num == 0)
    {
        /* code */
        link tail = head;
        while (tail->next != head)
        {
            /* code */
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
        return newNode;
    }
    p = p->next;

    while(p != head) {
        if (p->num == num)
        {
            /* code */
            newNode->next = p->next;
            p->next = newNode;   
            return head; 
        }
        p = p->next;
    }

    newNode->next = p->next;
    p->next = newNode;

    return head;
}

link findNode(link head, const char *letters) {
    link p = head;

    if (strcmp(p->letters, letters) == 0)
    {
        /* code */
        return head;        
    }
    p = p->next;
    while(p != head) {
        if (strcmp(p->letters, letters) == 0)
        {
            /* code */
            return p;
        }
        
        p = p->next;
    }
    return NULL;
}

int main(void) {

    link head = NULL;
    // init_cycle_link
    head = init_cycle_link(head, 5);
    // show_cycle
    show_cycle(head);

    link newNode = new node;
    newNode->num = 100;
    strcpy(newNode->letters, "Z");
    head = insert_node(head, 0, newNode);
    show_cycle(head);
    newNode->num = 200;
    strcpy(newNode->letters, "Y");
    head = insert_node(head, 1, newNode);
    show_cycle(head);
    newNode->num = 300;
    strcpy(newNode->letters, "X");
    head = insert_node(head, 5, newNode);
    show_cycle(head);

    const char *findWord = "X";
    link pFind = findNode(head, findWord);
    if (pFind == NULL)
    {
        /* code */
        cout << "Not found: " << findWord << endl;
    }
    else
    {
        cout << pFind->num << ":" << pFind->letters << ' ';
    }
    cout << endl;
    
    return 0;
}