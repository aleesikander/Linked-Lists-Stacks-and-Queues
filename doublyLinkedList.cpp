#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node* next;
    Node* prev;
    Node(int data)
    {
        value = data;
        next = nullptr;
        prev = nullptr;
    }
};
class LinkedList
{
    public:
    Node* head;
    Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}

    void addNodeAtFront(int data)
    {
        Node* newNode = new Node(data);
        if(head==nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
};