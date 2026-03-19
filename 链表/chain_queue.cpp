#include <iostream>
using namespace std;

typedef int elementType;

struct Node {
    elementType data;
    Node *next;
};

class Queue {
private:
    Node *front;
    Node *rear;
public:
    Queue();
    ~Queue();
    bool isEmpty()const;
    elementType topElement()const;
    void push(elementType value);
    void pop();
};

Queue::Queue() {
    front=new Node;
    rear=front;
    front->next=nullptr;
}

Queue::~Queue() {
    while (!isEmpty()) {
        pop();
    }
}

bool Queue::isEmpty() const {
    return front==rear;
}

elementType Queue::topElement() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    return front->next->data;
}

void Queue::push(elementType value) {
    Node *s=new Node;
    s->data=value;
    s->next=nullptr;
    rear->next=s;
    rear=s;
}

void Queue::pop() {
    if (isEmpty()) {
        throw runtime_error("underflow");
    }
    Node *temp=front->next;
    front->next=temp->next;
    if (front->next==nullptr) {
        rear=front;
    }
    delete temp;
}

int main()
{
    cout<<"asdfghjkl"<<endl;
    return 0;
}