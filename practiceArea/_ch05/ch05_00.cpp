#include <iostream>
using namespace std;

class Queue {
    private:
        int front;
        int rear;
        static const int SIZE = 10;
        char data[SIZE];
    public:
        // constructor
        Queue() {
            front = -1;
            rear = -1;
        }
        // push
        bool push_queue(char letter);
            // isFull
        bool isFull();
        // pop
        bool pop_queue(char &letter);
            // isEmpty
        bool isEmpty();
};

int main() {
    Queue qe;
    char letter;
    int count = 5;

    // cout << "Please enter count for push and pop: ";
    // cin >> count;
    cout << "PUSH: ";
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        letter = 'A' + i;
        if (qe.push_queue(letter))
        {
            /* code */
            cout << letter << ' ';
        }
    }
    cout << endl;

    cout << "POP: ";
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        char get_letter;
        if (qe.pop_queue(get_letter))
        {
            /* code */
            cout << get_letter << ' ';
        }
    }
    cout << endl;
    
    return 0;
}


bool Queue::push_queue(char letter) {
        if (isFull())
        {
            /* code */
            cout << "Err: push fail" << endl;
            return false;
        }
        data[++rear] = letter;
        // cout << "PUSH: " << letter << endl;
        return true;
    }

bool Queue::isEmpty() {
        if (front == rear)
        {
            /* code */
            cout << "Queue buff is empty" << endl;
            return true;
        }
        
        return false;
    }

bool Queue::pop_queue(char &letter) {
        if (isEmpty())
        {
            /* code */
            cout << "Err: pop" << endl;
            return false;
        }
        letter = data[++front];
        //cout << "POP: " << letter << endl;
        return true;
    }

bool Queue::isFull() {
        if (SIZE == rear)
        {
            /* code */
            cout << "Queue buff is full" << endl;
            return true;
        }
        
        return false;
    }