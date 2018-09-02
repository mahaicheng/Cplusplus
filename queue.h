#include<iostream>
#include<string>

using namespace std;

template<typename T>
class Queue
{
private:
    template<typename T>
    class Node
    {
    public:
        Node() = default;
        Node(T value, Node *pre = nullptr, Node *next = nullptr);
        Node(const Node &item);
        ~Node();
        Node& operator=(const Node &item);

    private:
        T _value;
        Node *_pre;
        Node *_next;
    };

public:
Queue();
~Queue();
void push(const T &item);
T pop();
bool empty();
size_t size();
private:
    Node<T> *_head;
    Node<T> *_tail;
};