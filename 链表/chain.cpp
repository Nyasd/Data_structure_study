#include <iostream>
using namespace std;

template <typename T>
class chain
{
private:
    T data;
    chain* next;
public:
    chain();
};

template <typename T>
chain<T>::chain(){
    data = T();
    next = nullptr;
}

int main()
{
    return 0;
}