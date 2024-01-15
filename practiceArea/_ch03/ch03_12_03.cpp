#include <iostream>
using namespace std;

class node {
    public:
        int num;
        char letters[2];
    class node *rlink;
    class node *llink;
};

typedef node *link;

link init_cycle_link(link head, int count) {

    link p = head;

    for (size_t i = 0; i < count; i++)
    {
        /* code */
        link newNode = new node;
        newNode->num = i + 1;
        newNode->letters[0] = 'A' + i;
        newNode->letters[1] = '\0';
        newNode->rlink = NULL;
        newNode->llink = NULL;

        if (p == NULL)
        {
            /* code */
            head = newNode;
            p = head;
        }
        else
        {
            p->rlink = newNode;
            newNode->llink = p;
            p = newNode;
        }
    }

    return head;
}

void show_cycle_left_to_right(link head) {

    cout << __FUNCTION__ << endl;
    if (head == NULL)
    {
        /* code */
        cout << "Link is empty" << endl;
        return;
    }
    
    link p = head;

    while (p != NULL)
    {
        /* code */
        cout << p->num << ":" << p->letters << ' ';
        p = p->rlink;
    }
    cout << endl;
}

void show_cycle_right_to_left(link head) {

    cout << __FUNCTION__ << endl;
    if (head == NULL)
    {
        /* code */
        cout << "Link is empty" << endl;
        return;
    }

    link pTail = head;
    while (pTail->rlink != NULL)
    {
        /* code */
        pTail = pTail->rlink;
    }

    link p = pTail;
    while (p!= NULL)
    {
        /* code */
        cout << p->num << ":" << p->letters << ' ';
        p = p->llink;
    }
    
    
    cout << endl;
}

link find_node(link head, int num) {

    if (head == NULL)
    {
        /* code */
        return NULL;
    }

    link p = head;
    
    while (p != NULL)
    {
        /* code */
        if (p->num == num)
        {
            /* code */
            return p;
        }
        
        p = p->rlink;
    }
    
    return NULL;
}

link insert_node(link head, int num, link data) {
    
    link p = find_node(head, num);

    if (p == NULL)
    {
        /* code */
        return NULL;
    }
    
    link newNode = new node;
    newNode->num = data->num;
    strcpy(newNode->letters, data->letters);
    newNode->rlink = NULL;
    newNode->llink = NULL;

    if (p->rlink == NULL)
    {
        cout << "insert tail: " << p->num << endl;
        /* code */
        p->rlink = newNode;
        newNode->llink = p;
    }
    else if (p->llink == NULL)
    {
        cout << "insert head: " << p->num << endl;
        /* code */
        newNode->rlink = p;
        p->llink = newNode;
        head = newNode;
    }
    else
    {
        cout << "insert middle: " << p->num << endl;
        //newNode
        newNode->rlink = p->rlink;
        p->rlink->llink = newNode;
        //P
        newNode->llink = p;
        p->rlink = newNode;
    }

    return head;
}

link delete_node(link head, int num) {
    link p = find_node(head, num);
    // tail
    if (p->rlink == NULL)
    {
        cout << "delete tail: " << p->num << endl;
        /* code */
        link d = p;
        p->llink->rlink = NULL;
        delete d;
    }
    // head
    else if (p->llink == NULL)
    {
        cout << "delete head: " << p->num << endl;
        /* code */
        link d = p;
        head = p->rlink;
        p->rlink->llink = NULL;
        delete d;
        return head;
    }
    // middle
    else
    {
        cout << "delete middle: " << p->num << endl;
        /* code */
        link d = p;

        p->llink->rlink = p->rlink;
        p->rlink->llink = p->llink;
        delete d;
    }
    return head;
}

int main(void) {

    link head = NULL;
    // init_cycle_link
    head = init_cycle_link(head, 5);
    // show_cycle
    show_cycle_left_to_right(head);
    show_cycle_right_to_left(head);

    link newNode = new node;
    newNode->num = 100;
    strcpy(newNode->letters, "Z");
    newNode->rlink = NULL;
    newNode->llink = NULL;

    newNode->num = 101;
    head = insert_node(head, 1, newNode);
    show_cycle_left_to_right(head);
    show_cycle_right_to_left(head);

    newNode->num = 103;
    head = insert_node(head, 3, newNode);
    show_cycle_left_to_right(head);
    show_cycle_right_to_left(head);

    newNode->num = 105;
    head = insert_node(head, 5, newNode);
    show_cycle_left_to_right(head);
    show_cycle_right_to_left(head);


    // head = delete_node(head, 1);
    // show_cycle_left_to_right(head);
    // show_cycle_right_to_left(head);

    // head = delete_node(head, 3);
    // show_cycle_left_to_right(head);
    // show_cycle_right_to_left(head);

    head = delete_node(head, 101);
    show_cycle_left_to_right(head);
    show_cycle_right_to_left(head);

    head = delete_node(head, 103);
    show_cycle_left_to_right(head);
    show_cycle_right_to_left(head);

    head = delete_node(head, 105);
    show_cycle_left_to_right(head);
    show_cycle_right_to_left(head);
    return 0;
}