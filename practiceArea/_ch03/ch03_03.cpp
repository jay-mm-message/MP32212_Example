#include <iostream>
using namespace std;

class list {
    public:
        int num;
        char name[10];
        int score;
    
        class list *next;
};

int main() {

    int num;
    cout << "Please provide the number of stdents: ";
    cin >> num;

    class list *head = NULL;
    class list *ptr = NULL;
    for (size_t i = 0; i < num; i++)
    {
        /* code */
        if (head == NULL)
        {
            /* code */
            head = new list;
            ptr = head;

        }
        else
        {
            ptr->next = new list;
            ptr = ptr->next;
        }
        cout << "Please provide the number of " << ptr->name << ": ";
        cin >> ptr->num;
        cout << "Please provide the name of student: ";
        cin >> ptr->name;
        cout << "Please provide the score of " << ptr->name << ": ";
        cin >> ptr->score;
        ptr->next = NULL;
    }

    ptr = head;

    cout << endl;
    cout << "ID, name and score " << endl;
    while (ptr != NULL)
    {
        /* code */
        cout << ptr->num << ' ' << ptr->name << ' ' << ptr->score << endl;
        list *delptr = ptr;
        ptr = ptr->next;
        delete delptr;
    }
    
    
    return 0;
}