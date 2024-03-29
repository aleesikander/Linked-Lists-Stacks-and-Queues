#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node* next;

    Node(int data)
    {
        value = data;
        next = NULL;
    }
};

class LinkedList
{
    public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void addNodetoEnd(int data)
    {
        Node* newNode = new Node(data);
        if(head == nullptr)
        {
            head = newNode;
            return;
        }
        else
        {
            Node* current = head;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void traverse()
    {
        Node* current = head;
        while(current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }

    ~LinkedList()
    {
        Node* current = head;
        while(current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};