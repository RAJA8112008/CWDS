#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

    Node* front;
    Node* rear;

public:
    myQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if(isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if(isEmpty()) return;

        Node* temp = front;
        front = front->next;

        if(front == nullptr)
            rear = nullptr;

        delete temp;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return front->data;
    }

    int size() {
        int count = 0;
        Node* temp = front;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    myQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Size: " << q.size() << endl;

    q.dequeue();

    cout << "Front after dequeue: " << q.getFront() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}
