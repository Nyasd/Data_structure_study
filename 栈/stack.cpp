#include <iostream>
using namespace std;

typedef int elementType;
const int maxlen=100;

enum stack_error_code{success,underflow,overflow};

class Stack {
public:
    Stack();
    bool isEmpty() const;
    bool isFull() const;
    stack_error_code top(elementType &x) const;
    stack_error_code push(const elementType x);
    stack_error_code pop();
private:
    int crt;
    elementType data[maxlen];
};

Stack::Stack() {
    crt=-1;
}

bool Stack::isEmpty() const {
    return crt==-1;
}

bool Stack::isFull() const {
    return crt==maxlen-1;
}

stack_error_code Stack::top(elementType &x) const {
    if(isEmpty()) return underflow;
    x=data[crt];
    return success;
}

stack_error_code Stack::push(const elementType x) {
    if(isFull()) return overflow;
    data[++crt]=x;
    return success;
}

stack_error_code Stack::pop() {
    if(isEmpty()) return underflow;
    crt--;
    return success;
}

int main() {
    struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    elementType x;
    if(s.top(x)==success)
        cout<<"Top element:"<<x<<endl;
    s.pop();
    if(s.top(x)==success)
        cout<<"Top element after pop:"<<x<<endl;
    return 0;
}