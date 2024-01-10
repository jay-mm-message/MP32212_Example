#include <iostream>
using namespace std;

class list {
    public:
        int data;
        char letters[3];
    class list *next;
};

void prepareList(class list** dataList, int size) {

    class list **head = dataList;
    class list *ptr = NULL;

    int i = 0;
    while(i < size) {
        class list *newNode = new list;
        newNode->next = NULL;

        if (*head == NULL)
        {
            /* code */
            *head = newNode;
            ptr = *head;
        }
        else
        {
            /* code */
            ptr->next= newNode;
            ptr = ptr->next;
        }

        ptr->data = i + 1;
        ptr->letters[0] = 'A' + i;
        ptr->letters[1] = '\0';
        i++;
    }
}

void showList(class list** dataList) {

    if (*dataList == NULL)
    {
        /* code */
        cout << "List is empty" << endl;
        return;
    }
    
    class list* ptr = *dataList;

    while( ptr != NULL) {
        cout << ptr->data << ":" << ptr->letters << ", ";
        ptr = ptr->next;
    }
    cout << endl;
}

void insertHead(class list **dataList, int element, char letters[3]) {
    class list *newNode = new list;
    newNode->data = element;

    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        if (letters[i] != '\0')
        {
            /* code */
            newNode->letters[i] = letters[i];
        }
        
    }
    
    newNode->next = *dataList;
    *dataList = newNode;
}

void insertTail(class list **dataList, int element, char letters[3]) {
    class list *newNode = new list;
    newNode->data = element;

    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        if (letters[i] != '\0')
        {
            /* code */
            newNode->letters[i] = letters[i];
        }
        
    }

    class list *ptr = *dataList;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void insertSelIndex(class list **dataList, int index, int element, char letters[3]) {
    class list *newNode = new list;
    newNode->data = element;

    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        if (letters[i] != '\0')
        {
            /* code */
            newNode->letters[i] = letters[i];
        }
    }

    class list *ptr = *dataList;
    for (size_t i = 0; i < index - 1; i++)
    {
        /* code */
        ptr = ptr->next;
    }

    newNode->next = ptr->next->next;
    ptr->next = newNode;
}

void delListInFront(class list **dataList) {
    class list *ptr = *dataList;

    class list *currentPtr = NULL;
    while (ptr->next != NULL)
    {
        /* code */
        currentPtr = ptr->next;
        delete ptr;
        ptr = currentPtr;
    }
    delete ptr;
    *dataList = NULL;
}

int main() {

    class list *head = NULL;
    prepareList(&head, 26);
    showList(&head);
    cout << endl;
    char data1[] = {'c', '1', '\0'};
    insertHead(&head, 100, data1);
    showList(&head);
    char data2[] = {'c', '2', '\0'};
    insertTail(&head, 200, data2);
    showList(&head);
    char data3[] = {'c', '3', '\0'};
    insertSelIndex(&head, 5, 300, data3);
    showList(&head);
    delListInFront(&head);
    showList(&head);

    return 0;
}