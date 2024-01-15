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

    if (head == NULL)
    {
        /* code */
        cout << "Link is empty" << endl;
        return;
    }
    
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

link delNode(link head, const char *letters) {
    // findNode and remove
    link dnode = findNode(head, letters);

    link p = head;

    if (dnode == p)
    {
        /* code */
        while (p->next != head)
        {
            /* code */
            p = p->next;
        }
        p->next = head->next;
        head = head->next;
        dnode->next = NULL;
        cout << "remove dnode: " << dnode->num << ":" << dnode->letters << endl;
        delete dnode;
    }
    
    while (p->next != head)
    {
        /* code */
        if (p->next == dnode)
        {
            /* code */
            p->next = p->next->next;
            dnode->next = NULL;
            cout << "remove dnode: " << dnode->num << ":" << dnode->letters << endl;
            delete dnode;
        }
        
        p = p->next;
    }

    return head;
}

link concatenation(link head1, link head2) {
    if (head1 == NULL and head2 != NULL)
    {
        /* code */
        return head2;
    }
    else if (head1 != NULL and head2 == NULL)
    {
        return head1;
    }
    else
    {
        link ph1Tail = head1;
        while (ph1Tail->next != head1)
        {
            /* code */
            ph1Tail = ph1Tail->next;
        }
        link ph2Tail = head2;
        while (ph2Tail->next != head2)
        {
            /* code */
            ph2Tail = ph2Tail->next;
        }
        ph1Tail->next = head2;
        ph2Tail->next = head1;

    }
    return head1;
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

    // cout << "remove head" << endl;
    // head = delNode(head, "Z");
    // show_cycle(head);
    // cout << "remove middle" << endl;
    // head = delNode(head, "Y");
    // show_cycle(head);
    // cout << "remove tail" << endl;
    // head = delNode(head, "X");
    // show_cycle(head);

    link head1 = NULL;
    head1 = init_cycle_link(head1, 5);
    link head2 = NULL;
    head2 = init_cycle_link(head2, 10);

    show_cycle(head1);
    show_cycle(head2);

    head = concatenation(head1, head2);
    show_cycle(head);

    show_cycle(head1);
    show_cycle(head2);

    return 0;
}