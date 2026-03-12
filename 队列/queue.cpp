#include <iostream>
using namespace std;

typedef int elementType;
const int maxlen=100;
enum queue_error_code{success,underflow,overflow};

class Queue {
public:
    Queue();
    bool isEmpty() const;
    bool isFull() const;
    queue_error_code getFront(elementType &x) const;
    queue_error_code enqueue(const elementType x);
    queue_error_code dequeue(elementType &x);
private:
    int front,rear;
    elementType data[maxlen];
};

Queue::Queue() {
    front=rear=0;
}

bool Queue::isEmpty() const {
    return front==rear;
}

bool Queue::isFull() const {
    return (rear+1)%maxlen==front;
}

queue_error_code Queue::getFront(elementType &x) const {
    if(isEmpty()) return underflow;
    x=data[front];
    return success;
}

queue_error_code Queue::enqueue(const elementType x) {
    if(isFull()) return overflow;
    data[rear]=x;
    rear=(rear+1)%maxlen;
    return success;
}

queue_error_code Queue::dequeue(elementType &x) {
    if(isEmpty()) return underflow;
    x=data[front];
    front=(front+1)%maxlen;
    return success;
}
// queue_error_code Queue::dequeue(elementType &x) {
//     if(isEmpty()) return underflow;
//     cnt--;
//     for(int i=0;i<cnt;i++) data[i]=data[i+1];
//     return success;
// }

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    elementType x;
    if(q.getFront(x)==success)
        cout<<"Front element:"<<x<<endl;
    q.dequeue(x);
    if(q.getFront(x)==success)
        cout<<"Front element after dequeue:"<<x<<endl;
    return 0;
}