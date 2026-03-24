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
    void bottomPush(elementType value);
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

void Stack::bottomPush(elementType value)
{
    Node *newNode=new Node;
    newNode->data=value;
    newNode->next=nullptr;
    
    if (isEmpty()) {
        top=newNode;
    } else {
        Node *current=top;
        while (current->next!=nullptr) {
            current=current->next;
        }
        current->next=newNode;
    }
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
    Stack s;
    s.push(10);
    s.push(20);
    s.bottomPush(5);
    cout << "Top element: " << s.topElement() << endl; // Should print 20
    s.pop();
    cout << "Top element：" << s.topElement() << endl; // Should print 10
    s.pop();
    cout << "Top element: " << s.topElement() << endl; // Should print 5
    
    return 0;
}