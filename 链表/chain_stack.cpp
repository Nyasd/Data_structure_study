#include <iostream>
using namespace std;

typedef int elementType;

struct Node {
    elementType data;
    Node *next; 
};

class Stack {
private:
    Node *top;
public:
    Stack();
    ~Stack();
    bool isEmpty()const;
    elementType topElement()const;
    void push(elementType value);
    void pop();
};

Stack::Stack() {
    top=nullptr;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const {
    return top==nullptr;
}

elementType Stack::topElement() const {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    return top->data;
}

void Stack::push(elementType value) {
    Node *s=new Node;
    s->data=value;
    s->next=top;
    top=s;
}

void Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("underflow");
    }
    Node *temp=top;
    top=top->next;
    delete temp;
}

int main()
{
    cout<<"asdfghjkl"<<endl;
    return 0;
}